#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr)

using ll = long long;
const int N = 3e5;
int n, q, x;
int a[N];
ll pref[N + 1];

struct SegmentTree {
    vector<int> tree;
    int size;

    void init(int n) {
        size = n;
        tree.assign(4 * n, 0);
    }

    void build(int start, int end, int node) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1);
        build(mid + 1, end, 2 * node + 2);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int start, int end, int l, int r, int node=0) {
        if (r < start || end < l) return INT_MIN;
        if (l <= start && end <= r) return tree[node];
        
        int mid = (start + end) / 2;
        int leftMax = query(start, mid, l, r, 2 * node + 1);
        int rightMax = query(mid + 1, end, l, r, 2 * node + 2);
        return max(leftMax, rightMax);
    }
};

SegmentTree segTree;

void solve() {
    cin >> n >> q;
    segTree.init(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Build the Segment Tree and prefix sum array
    segTree.build(0, n - 1, 0);
    pref[0] = 0;
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    while (q--) {
        cin >> x;
        ll ans = 0;

        for (int l = 0; l < n; l++) {
            int lo = l, hi = n - 1, best = l;

            // Binary search with Segment Tree for max value constraint
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int maxPairSum = segTree.query(0, n - 1, l, mid);

                if (maxPairSum <= x) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            ll elm = best - l + 1;
            ll sum = pref[best + 1] - pref[l];
            ans += sum - elm * a[l];
        }
        cout << ans << '\n';
    }
}

int main() {
    FASTIO;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
