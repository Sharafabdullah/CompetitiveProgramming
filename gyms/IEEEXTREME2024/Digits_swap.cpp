#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Helper function for swapping and backtracking
void findMaximum(string& s, int k, string& maxNum, unordered_set<string>& visited) {
    // If no swaps are left, compare and update maxNum if the current state is larger
    if (k == 0) {
        maxNum = max(maxNum, s);
        return;
    }

    int len = s.size();

    // Check if this state has already been processed to avoid redundant work
    string state = s + to_string(k);
    if (visited.count(state)) return;
    visited.insert(state);

    // Greedy selection: Try to put the largest possible digit at each position
    for (int i = 0; i < len - 1; ++i) {
        char maxDigit = s[i];
        int maxIdx = i;

        // Find the largest digit to the right of `i`
        for (int j = i + 1; j < len; ++j) {
            if (s[j] >= maxDigit) {  // >= ensures we select rightmost for tie
                maxDigit = s[j];
                maxIdx = j;
            }
        }

        // Only swap if a larger digit is found on the right side
        if (maxIdx != i && s[maxIdx] > s[i]) {
            swap(s[i], s[maxIdx]);

            // Recursive call to explore with reduced `k`
            findMaximum(s, k - 1, maxNum, visited);

            // Backtrack to revert the string
            swap(s[i], s[maxIdx]);
        }
    }

    // Final comparison if no swaps yield a new config
    maxNum = max(maxNum, s);
}

void maximizeNumberAfterSwaps() {
    string s;
    int k;
    cin >> s >> k;

    string maxNum = s;  // Initialize maxNum with the original number
    unordered_set<string> visited;

    // Call the helper function to perform backtracking with greedy optimization
    findMaximum(s, k, maxNum, visited);

    cout << maxNum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    maximizeNumberAfterSwaps();
    return 0;
}
