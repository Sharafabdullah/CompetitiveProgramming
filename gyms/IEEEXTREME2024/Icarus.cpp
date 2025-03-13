#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<pair<int, int>> st; // {node_id, parent_id}
    vector<pair<int, int>> adj(1); // Adjacency list (node, parent)
    int next_node_id = 2;

    st.push({1, 0}); // Start with root node (id 1, parent 0)
    
    for (char c : s) {
        if (c == 'U') {
            if (!st.empty()) {
                st.pop(); // Move up (remove current node from stack)
            }
        } else {
            int current_node = st.top().first;
            int parent_node = st.top().second;

            adj.push_back({0,0}); // Add new node
            
            if (c == 'L') {
                adj[current_node].first = next_node_id;
            } else {
                adj[current_node].second = next_node_id;
            }

            st.push({next_node_id++, current_node}); // Push new node onto stack
        }
    }

    cout << next_node_id -1 << " 1 " << 1 << endl; // number of nodes, root, root
    for (int i = 1; i < next_node_id; ++i) {
        cout << adj[i].first << " " << adj[i].second << endl;
    }

    return 0;
}
