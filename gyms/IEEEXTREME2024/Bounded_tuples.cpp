#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 998244353;

using namespace std;

bool satisfiesConstraints(const vector<int>& V, const vector<tuple<int, int, vector<int>>>& constraints) {
    for (const auto& constraint : constraints) {
        int low, high;
        vector<int> indices;
        tie(low, high, indices) = constraint;
        
        long long sum = 0;
        for (int idx : indices) {
            sum += V[idx];
        }
        
        if (sum < low || sum > high) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<tuple<int, int, vector<int>>> constraints(M);
    
    for (int i = 0; i < M; ++i) {
        int low, high, K;
        cin >> low >> high >> K;
        vector<int> indices(K);
        for (int j = 0; j < K; ++j) {
            cin >> indices[j];
            indices[j]--; // Convert to 0-based index
        }
        constraints[i] = make_tuple(low, high, indices);
    }
    
    long long totalValid = 0;
    bool infinite = false;
    
    // Iterate over all possible assignments of V
    for (int mask = 0; mask < (1 << N); ++mask) {
        vector<int> V(N);
        
        for (int i = 0; i < N; ++i) {
            V[i] = (mask & (1 << i)) ? 1 : 0;
        }
        
        if (satisfiesConstraints(V, constraints)) {
            totalValid++;
            if (totalValid >= MOD) {
                infinite = true;
                break;
            }
        }
    }
    
    if (infinite) {
        cout << "infinity" << endl;
    } else {
        cout << totalValid << endl;
    }
    
    return 0;
}
