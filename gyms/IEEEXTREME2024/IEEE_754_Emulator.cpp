#include <bits/stdc++.h>
using namespace std;

// Union to easily convert between float and its binary representation
union FloatBits {
    float f;
    uint32_t bits;
};

class FloatCalculator {
private:
    vector<FloatBits> C;                  // Store computed values
    vector<vector<FloatBits>> lookupTables;   // Store LUT values

    // Extract bits from position j to j+b-1 from a 32-bit value
    uint32_t extractBits(uint32_t value, int j, int b) {
        uint32_t mask = ((1u << b) - 1) << j;
        return (value & mask) >> j;
    }

    // Perform bitwise NAND operation
    FloatBits nandOperation(FloatBits a, FloatBits b) {
        FloatBits result;
        result.bits = ~(a.bits & b.bits);
        return result;
    }

    // Convert hex string to FloatBits
    FloatBits hexToFloat(const string& hex) {
        FloatBits conv;
        conv.bits = stoul(hex, nullptr, 16);
        return conv;
    }

public:
    void reset() {
        C.clear();
        lookupTables.clear();
    }

    void setInitialValue(const string& hexValue) {
        C = {hexToFloat(hexValue)};
    }

    void addLookupTable(int size, const vector<string>& hexValues) {
        vector<FloatBits> table;
        for (const string& hex : hexValues) {
            table.push_back(hexToFloat(hex));
        }
        lookupTables.push_back(table);
    }

    void processCommand(const string& cmd, const vector<string>& params) {
        if (cmd == "L") {  // Lookup Table
            int i = stoi(params[0]);
            int j = stoi(params[1]);
            int b = stoi(params[2]);
            
            uint32_t mask = extractBits(C[0].bits, j, b);
            C.push_back(lookupTables[i][mask]);
        }
        else if (cmd == "N") {  // NAND
            int i = stoi(params[0]);
            int j = stoi(params[1]);
            C.push_back(nandOperation(C[i], C[j]));
        }
        else if (cmd == "F") {  // Fused Multiply Add
            int i = stoi(params[0]);
            int j = stoi(params[1]);
            int k = stoi(params[2]);
            FloatBits result;
            result.f = fma(C[i].f, C[j].f, C[k].f);
            C.push_back(result);
        }
        else if (cmd == "C") {  // Constant
            C.push_back(hexToFloat(params[0]));
        }
    }

    string getLastResultHex() const {
        stringstream ss;
        ss << hex << setfill('0') << setw(8) << C.back().bits;
        return ss.str();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;

    FloatCalculator calc;
    
    while (T--) {
        calc.reset();
        
        // Read initial value
        string initialHex;
        cin >> initialHex;
        calc.setInitialValue(initialHex);
        
        // Read lookup tables
        int L;
        cin >> L;
        for (int i = 0; i < L; i++) {
            int size;
            cin >> size;
            vector<string> hexValues(size);
            for (int j = 0; j < size; j++) {
                cin >> hexValues[j];
            }
            calc.addLookupTable(size, hexValues);
        }
        
        // Process commands
        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            string cmd;
            cin >> cmd;
            
            vector<string> params;
            if (cmd == "L") {
                string p1, p2, p3;
                cin >> p1 >> p2 >> p3;
                params = {p1, p2, p3};
            }
            else if (cmd == "N" || cmd == "F") {
                string p1, p2;
                cin >> p1 >> p2;
                params = {p1, p2};
                if (cmd == "F") {
                    string p3;
                    cin >> p3;
                    params.push_back(p3);
                }
            }
            else if (cmd == "C") {
                string p1;
                cin >> p1;
                params = {p1};
            }
            
            calc.processCommand(cmd, params);
        }
        
        // Print result in hexadecimal
        cout << calc.getLastResultHex() << '\n';
    }
    
    return 0;
}