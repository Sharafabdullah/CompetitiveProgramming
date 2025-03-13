#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate (base^exp) % MOD
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to solve each test case
void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Step 1: Filter elements that divide x and compute their count
    vector<int> divisors;
    unordered_map<int, int> count;
    
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i != x / i) divisors.push_back(x / i);
        }
    }
    sort(divisors.begin(), divisors.end());

    // Count the number of occurrences of divisors in the array
    for (int i = 0; i < n; ++i) {
        if (x % a[i] == 0) {
            count[a[i]]++;
        }
    }
    
    // Step 2: Use inclusion-exclusion to find subsequences with LCM = divisors[i]
    vector<int> subseq_count(divisors.size(), 0);
    
    for (int i = divisors.size() - 1; i >= 0; --i) {
        int d = divisors[i];
        subseq_count[i] = mod_pow(2, count[d], MOD) - 1; // Number of subsequences using divisor d
        subseq_count[i] = (subseq_count[i] + MOD) % MOD; // Ensure non-negative
        
        // Remove over-counted subsequences
        for (int j = i + 1; j < divisors.size(); ++j) {
            if (divisors[j] % divisors[i] == 0) {
                subseq_count[i] = (subseq_count[i] - subseq_count[j] + MOD) % MOD;
            }
        }
    }
    
    // Step 3: Output the result for LCM = x
    int idx = lower_bound(divisors.begin(), divisors.end(), x) - divisors.begin();
    cout << subseq_count[idx] << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T; // Number of test cases
    
    while (T--) {
        solve();
    }
    
    return 0;
}
