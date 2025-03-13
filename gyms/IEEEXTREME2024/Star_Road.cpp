#include <iostream>
#include <vector>
#include <algorithm>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int stars[MAXN];
int dp[MAXN];

int dfs(int u, int parent, int mx) {
    // if (dp[u] != -1) return dp[u];

    int maxRestaurants = 0;
    bool leaf = 1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        leaf = 0;
        maxRestaurants = max(maxRestaurants, dfs(v, u, mx));
        if(stars[v]>mx){
            maxRestaurants = max(maxRestaurants, dfs(v, u, stars[v]) + 1);
        }
        
    }
    if(leaf) return max(1, maxRestaurants);
    else return maxRestaurants;

}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stars[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(&dp[0], &dp[0] + MAXN,-1);

    int result = 0;
    for (int i = 0; i < min(n, 120); i++) {
        result = max({result, dfs(i, -1, stars[i])});
    }

    cout << result << endl;
    return 0;
}