#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 998244353;

int N;
vector<int> C, R, B;
vector<int> missing;
map<pair<int, int>, long long> dp;

// Function to check if the pair satisfies the rule
bool check_pair(int a, int b, int rule, int target) {
    return (rule == 0) ? (min(a, b) == target) : (max(a, b) == target);
}

// Recursive DP function to count valid configurations
long long solve_dp(int pos, int used) {
    if (pos == N) return 1; // Base case: All positions processed

    pair<int, int> state = {pos, used}; // Create a state for memoization
    if (dp.count(state)) return dp[state]; // Return cached result

    long long result = 0;
    int pos1 = 2 * pos;
    int pos2 = 2 * pos + 1;

    int val1 = C[pos1];
    int val2 = C[pos2];

    // Process candidates for the first position
    for (int i = 0; i < missing.size(); i++) {
        int num1 = (val1 == -1) ? missing[i] : val1; // Determine candidate

        // Check if num1 is valid
        if (val1 == -1 && (used & (1 << i))) continue;

        // Update the used mask if necessary
        int new_used = used | (val1 == -1 ? (1 << i) : 0);

        // Process candidates for the second position
        for (int j = 0; j < missing.size(); j++) {
            int num2 = (val2 == -1) ? missing[j] : val2; // Determine candidate

            // Check if num2 is valid
            if (val2 == -1 && (new_used & (1 << j))) continue;

            // Check if the pair satisfies the condition
            if (!check_pair(num1, num2, R[pos], B[pos])) continue;

            // Update used mask for the second candidate
            int next_used = new_used | (val2 == -1 ? (1 << j) : 0);
            result = (result + solve_dp(pos + 1, next_used)) % MOD; // Recur
        }
    }

    return dp[state] = result; // Memoize the result
}

void solve() {
    cin >> N;

    C.resize(2 * N);
    R.resize(N);
    B.resize(N);
    vector<bool> used(2 * N + 1, false);
    
    // Read input values
    for (int i = 0; i < 2 * N; i++) {
        cin >> C[i];
        if (C[i] != -1) used[C[i]] = true; // Track used numbers
    }

    for (int i = 0; i < N; i++) cin >> R[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    // Collect unused numbers
    for (int i = 1; i <= 2 * N; i++) {
        if (!used[i]) missing.push_back(i);
    }

    dp.clear(); // Clear previous memoization states
    cout << solve_dp(0, 0) << '\n'; // Start DP with first position and no numbers used
}

int main() {
    FASTIO;
    solve();
    return 0;
}
