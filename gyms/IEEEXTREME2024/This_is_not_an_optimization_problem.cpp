#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

class Solver {
private:
    int n;
    vector<ll> w;
    vector<vector<int>> g;
    vector<vector<int>> up;
    vector<int> depth, subtreeSize;
    int LOG;

    void dfs(int v, int p, int d) {
        depth[v] = d;
        up[v][0] = p;
        subtreeSize[v] = 1; // Initialize subtree size

        for (int i = 1; i <= LOG; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }

        for (int u : g[v]) {
            if (u != p) {
                dfs(u, v, d + 1);
                subtreeSize[v] += subtreeSize[u]; // Update the subtree size
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        // Bring u and v to the same depth
        int diff = depth[u] - depth[v];
        for (int i = LOG; i >= 0; i--) {
            if (diff & (1 << i)) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = LOG; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    void preprocess() {
        LOG = ceil(log2(n));
        depth.resize(n);
        subtreeSize.resize(n);
        up.assign(n, vector<int>(LOG + 1));

        // Set root as node 0
        dfs(0, 0, 0);
    }

    // Calculate contribution of each vertex
    vector<ll> calcContributions() {
        vector<ll> contrib(n);
        
        for (int v = 0; v < n; v++) {
            // The number of nodes in the subtree of v
            ll size = subtreeSize[v];
            // Calculate contributions based on how many times v appears
            contrib[v] = (w[v] * size) % MOD; // Direct contribution of weight
        }
        
        return contrib;
    }

public:
    Solver(int sz) : n(sz) {
        w.resize(n);
        g.resize(n);
    }
    
    void addW(int node, ll val) {
        w[node] = val;
    }
    
    void addE(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<ll> solve() {
        preprocess(); // Build LCA structure
        
        // Calculate contributions of each vertex
        vector<ll> contrib = calcContributions();
        
        // Output the contributions
        return contrib;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    Solver s(n);
    
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.addW(i, x);
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        s.addE(u, v);
    }
    
    vector<ll> res = s.solve();
    for (int k = 0; k < n; k++) {
        cout << res[k] << "\n";
    }
    
    return 0;
}
