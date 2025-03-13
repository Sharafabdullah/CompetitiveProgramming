#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree {
    int n;
    vector<ll> tree, lazy;
    
    void propagate(int v, int tl, int tr) {
        if (lazy[v] != 0) {
            tree[v] += lazy[v] * (tr - tl + 1);
            if (tl != tr) {
                lazy[2*v] += lazy[v];
                lazy[2*v+1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }
    
    void update_range(int v, int tl, int tr, int l, int r, ll val) {
        propagate(v, tl, tr);
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            lazy[v] += val;
            propagate(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update_range(2*v, tl, tm, l, r, val);
        update_range(2*v+1, tm+1, tr, l, r, val);
        tree[v] = tree[2*v] + tree[2*v+1];
    }
    
    ll query_range(int v, int tl, int tr, int l, int r) {
        propagate(v, tl, tr);
        if (l > tr || r < tl) return 0;
        if (l <= tl && tr <= r) return tree[v];
        int tm = (tl + tr) / 2;
        return query_range(2*v, tl, tm, l, r) + 
               query_range(2*v+1, tm+1, tr, l, r);
    }
    
public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4*n);
        lazy.resize(4*n);
    }
    
    void update(int l, int r, ll val) {
        update_range(1, 0, n-1, l, r, val);
    }
    
    ll query(int l, int r) {
        return query_range(1, 0, n-1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
        P[i]--; // Convert to 0-based indexing
    }
    
    vector<int> inv_P(n);
    for (int i = 0; i < n; i++) {
        inv_P[P[i]] = i;
    }
    
    SegmentTree normal(n), permuted(n);
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 0) { 
            int l, r, c;
            cin >> l >> r >> c;
            l--; r--;  
            normal.update(l, r, c);
        }
        else if (type == 1) {  
            int l, r, c;
            cin >> l >> r >> c;
            l--; r--;
            for (int i = l; i <= r; i++) {
                permuted.update(i, i, c);
            }
        }
        else if (type == 2) {  
            int l, r;
            cin >> l >> r;
            l--; r--;  
            ll sum = normal.query(l, r);
            for (int i = l; i <= r; i++) {
                sum += permuted.query(inv_P[i], inv_P[i]);
            }
            cout << sum << "\n";
        }
        else {  
            int l, r;
            cin >> l >> r;
            l--; r--; 
            ll sum = 0;
            sum += permuted.query(l, r);
            for (int i = l; i <= r; i++) {
                sum += normal.query(P[i], P[i]);
            }
            cout << sum << "\n";
        }
    }
    
    return 0;
}