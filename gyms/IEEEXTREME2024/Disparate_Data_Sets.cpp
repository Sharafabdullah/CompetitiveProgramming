#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

struct Event {
    string event_id;
    string title;
    string acronym;
    string project_code;
    string three_digit_code;
    string record_type;
    string parent_id;
    
    Event() {} // Default constructor
    
    Event(const string& id, const string& t, const string& acr, 
          const string& pc, const string& tdc, const string& rt)
        : event_id(id), title(t), acronym(acr), project_code(pc),
          three_digit_code(tdc), record_type(rt), parent_id("") {}
};

class ConferenceProcessor {
private:
    map<string, Event> events;
    multimap<string, string> children_by_parent; // parent_id -> child_id
    map<string, set<string>> parents_by_acronym;

    vector<string> split(const string& str, char delim) {
        vector<string> tokens;
        string token;
        bool in_quotes = false;
        ostringstream current;
        
        for (size_t i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (ch == '"') {
                if (i + 1 < str.length() && str[i + 1] == '"') {
                    current << '"';
                    i++;
                } else {
                    in_quotes = !in_quotes;
                }
            } else if (ch == delim && !in_quotes) {
                tokens.push_back(current.str());
                current.str("");
                current.clear();
            } else {
                current << ch;
            }
        }
        tokens.push_back(current.str());
        return tokens;
    }

    string trim(const string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (first == string::npos) return "";
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1));
    }

public:
    void processInput() {
        string line;
        while (getline(cin, line)) {
            if (line.empty()) continue;
            
            vector<string> fields = split(line, ',');
            if (fields.size() < 6) continue;

            // Clean up fields
            for (auto& field : fields) {
                field = trim(field);
                if (field.length() >= 2 && field.front() == '"' && field.back() == '"') {
                    field = field.substr(1, field.length() - 2);
                }
            }

            // Create event
            Event event;
            event.event_id = fields[0];
            event.title = fields[1];
            event.acronym = fields[2];
            event.project_code = fields[3];
            event.three_digit_code = fields[4];
            event.record_type = fields[5];

            // Skip events without acronyms
            if (event.acronym.empty()) continue;

            // Store event
            events[event.event_id] = event;

            if (event.record_type == "Parent Event") {
                parents_by_acronym[event.acronym].insert(event.event_id);
            } else if (event.record_type == "IEEE Event") {
                // Link to potential parents with matching acronym
                auto it = parents_by_acronym.find(event.acronym);
                if (it != parents_by_acronym.end()) {
                    for (const string& parent_id : it->second) {
                        children_by_parent.insert({parent_id, event.event_id});
                        events[event.event_id].parent_id = parent_id;
                    }
                }
            }
        }
    }

    void printOutput() {
        // Create sets of valid parent-children relationships
        vector<pair<string, vector<pair<string, Event>>>> valid_sets;

        for (const auto& [parent_id, _] : events) {
            if (events[parent_id].record_type != "Parent Event") continue;

            // Get all children for this parent
            vector<Event> children;
            auto range = children_by_parent.equal_range(parent_id);
            for (auto it = range.first; it != range.second; ++it) {
                children.push_back(events[it->second]);
            }

            // Skip if no children or not unique parent
            if (children.empty()) continue;
            if (parents_by_acronym[events[parent_id].acronym].size() > 1) continue;

            // Update parent's three_digit_code
            set<string> child_codes;
            for (const Event& child : children) {
                if (!child.three_digit_code.empty()) {
                    child_codes.insert(child.three_digit_code);
                }
            }
            events[parent_id].three_digit_code = 
                (child_codes.size() == 1) ? *child_codes.begin() : "???";

            // Create set output
            vector<pair<string, Event>> set_records;
            set_records.push_back({events[parent_id].title, events[parent_id]});
            
            for (const Event& child : children) {
                set_records.push_back({child.title, child});
            }

            // Sort children by title, then ID
            sort(set_records.begin() + 1, set_records.end(),
                [](const auto& a, const auto& b) {
                    return (a.first == b.first) ? 
                           (a.second.event_id < b.second.event_id) : 
                           (a.first < b.first);
                });

            valid_sets.push_back({events[parent_id].acronym, set_records});
        }

        // Sort sets by acronym
        sort(valid_sets.begin(), valid_sets.end());

        // Output results
        for (const auto& [_, set_records] : valid_sets) {
            for (size_t i = 0; i < set_records.size(); i++) {
                const Event& event = set_records[i].second;
                cout << event.event_id << ",\"" << event.title << "\","
                     << event.acronym << "," << event.project_code << ","
                     << event.three_digit_code << "," << event.record_type;
                
                // Add parent ID for children
                if (i > 0) {
                    cout << "," << event.parent_id;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ConferenceProcessor processor;
    processor.processInput();
    processor.printOutput();
    
    return 0;
}