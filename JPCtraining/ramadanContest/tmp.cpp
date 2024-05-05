#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a subset of nodes forms a complete subgraph in the original graph
bool isCompleteSubgraph(const vector<int>& nodes, const vector<vector<int>>& graph) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        for (size_t j = i + 1; j < nodes.size(); ++j) {
            if (find(graph[nodes[i]].begin(), graph[nodes[i]].end(), nodes[j]) == graph[nodes[i]].end()) {
                return false; // If an edge is missing, the subset is not complete
            }
        }
    }
    return true; // All edges present, subset forms a complete subgraph
}

// Function to find the maximum complete subgraph
vector<int> findMaximumCompleteSubgraph(const vector<vector<int>>& graph) {
    vector<int> maxCompleteSubgraph;
    int n = graph.size();

    // Iterate through all possible subsets of nodes
    for (int subset = 0; subset < (1 << n); ++subset) {
        vector<int> currentSubset;
        for (int node = 0; node < n; ++node) {
            if (subset & (1 << node)) {
                currentSubset.push_back(node); // Add node to current subset if its bit is set
            }
        }
        // Check if the current subset forms a complete subgraph and update maxCompleteSubgraph if necessary
        if (isCompleteSubgraph(currentSubset, graph) && currentSubset.size() > maxCompleteSubgraph.size()) {
            maxCompleteSubgraph = currentSubset;
        }
    }
    return maxCompleteSubgraph;
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2, 3}, // Node 0 is connected to nodes 1, 2, and 3
        {0, 2, 3}, // Node 1 is connected to nodes 0, 2, and 3
        {0, 1, 3}, // Node 2 is connected to nodes 0, 1, and 3
        {0, 1, 2}  // Node 3 is connected to nodes 0, 1, and 2
    };

    vector<int> maxCompleteSubgraph = findMaximumCompleteSubgraph(graph);

    cout << "Maximum complete subgraph: ";
    for (int node : maxCompleteSubgraph) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
