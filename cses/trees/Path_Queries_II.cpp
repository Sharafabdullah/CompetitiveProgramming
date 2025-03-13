
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,tune=native")
// #include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")
#include<iostream>
#include<vector>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (int i = (begin); i < (end); ++i)
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> vi;

const int N = 2e5 + 10, M = 18;
int k, n, m;
vi val;
vi g[N];

int up[N][M] = {};
int d[N], sz[N], head[N], node_id[N];
vi beforeSG;

struct SegmentTree {
    vector<int> seg;
    int sz;
    
    SegmentTree(vi& arr) {
        sz = arr.size();
        seg.resize(2 * sz);
        build(arr);
    }
    
    void build(vi& org) {
        for (int i = 0; i < sz; ++i) 
            seg[sz + i] = org[i];
        for (int i = sz - 1; i > 0; --i) 
            seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
    
    void update(int ind, int val) {
        ind += sz;
        seg[ind] = val;
        for (ind /= 2; ind > 0; ind /= 2) 
            seg[ind] = max(seg[2 * ind], seg[2 * ind + 1]);
    }
    
    int query(int l, int r) {
        l += sz; r += sz;
        int res = 0;
        while (l <= r) {
            if (l % 2 == 1) res = max(res, seg[l++]);
            if (r % 2 == 0) res = max(res, seg[r--]);
            l /= 2; r /= 2;
        }
        return res;
    }
};

void dfs_lca(int cur, int par, int dd) {
    head[cur] = cur;
    sz[cur] = 1;
    up[cur][0] = par;
    d[cur] = dd;
    for (int i = 1; i < M; i++) 
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    
    for (int ch : g[cur]) {
        if (ch == par) continue;
        dfs_lca(ch, cur, dd + 1);
        sz[cur] += sz[ch];
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int i = M - 1; i >= 0; i--) 
        if ((d[u] - d[v]) & (1 << i)) 
            u = up[u][i];
    
    if (u == v) return u;
    for (int i = M - 1; i >= 0; i--) 
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    
    return up[u][0];
}

int timer = 1;
void dfs_label(int cur, int par, int top) {
    node_id[cur] = timer++;
    head[cur] = top;
    beforeSG[node_id[cur]] = val[cur];
    int hch = -1, hsz = -1;
    for (int ch : g[cur]) {
        if (ch == par) continue;
        if (sz[ch] > hsz) {
            hch = ch;
            hsz = sz[ch];
        }
    }
    if (hch != -1) {
        dfs_label(hch, cur, top);
        for (int ch : g[cur]) {
            if (ch == par || ch == hch) continue;
            dfs_label(ch, cur, ch);
        }
    }
}

int find_path(int u, int v, SegmentTree& sg) {
    int ret = 0;
    while (head[u] != head[v]) {
        if (d[head[u]] < d[head[v]]) swap(u, v);
        ret = max(ret, sg.query(node_id[head[u]], node_id[u]));
        u = up[u][0];
    }
    if (d[u] > d[v]) swap(u, v);
    return max(ret, sg.query(node_id[u], node_id[v]));
}

void solve() {
    cin >> n >> k;
    val.resize(n + 1);
    beforeSG.resize(n + 1);
    rep(i, 1, n + 1) cin >> val[i];
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs_lca(1, 0, 0);
    dfs_label(1, 0, 1);
    SegmentTree sg(beforeSG);
    while (k--) {
        int t;
        cin >> t;
        if (t == 1) {
            int nd, v;
            cin >> nd >> v;
            sg.update(node_id[nd], v);
        } else {
            int u, v;
            cin >> u >> v;
            cout << find_path(u, v, sg) << " ";
        }
    }
}

int main() {
    FASTIO;
    solve();
    return 0;
}
