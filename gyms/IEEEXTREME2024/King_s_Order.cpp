#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Project {
public:
    int id;
    int groupId;
    
    Project(int _id, int _groupId) : id(_id), groupId(_groupId) {}
    
    bool operator>(const Project& other) const {
        if (groupId != other.groupId)
            return groupId > other.groupId;
        return id > other.id;
    }
};

vector<int> findProjectOrder(int N, vector<int>& groupIds, vector<vector<int>>& dependencies) {
    vector<vector<int>> adj(N + 1);
    vector<int> inDegree(N + 1, 0);
    
    for (const auto& dep : dependencies) {
        adj[dep[0]].push_back(dep[1]);
        inDegree[dep[1]]++;
    }
    
    priority_queue<Project, vector<Project>, greater<Project>> pq;
    
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            pq.push(Project(i, groupIds[i-1]));
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        Project current = pq.top();
        pq.pop();
        result.push_back(current.id);
        
        // Process all dependencies
        for (int next : adj[current.id]) {
            inDegree[next]--;
            if (inDegree[next] == 0) {
                pq.push(Project(next, groupIds[next-1]));
            }
        }
    }
    
    if (result.size() != N) {
        return vector<int>{-1};
    }
    
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> groupIds(N);
    for (int i = 0; i < N; i++) {
        cin >> groupIds[i];
    }
    
    vector<vector<int>> dependencies;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        dependencies.push_back({A, B});
    }
    
    vector<int> result = findProjectOrder(N, groupIds, dependencies);
    
    // Print result
    if (result[0] == -1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << (i < result.size()-1 ? " " : "");
        }
        cout << endl;
    }
    
    return 0;
}