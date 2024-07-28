#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define B begin()
#define E end()
#define clr(x) memset(x,0,sizeof(x))
#define endl '\n'
#define coutfloat(n,d) cout << fixed << setprecision(d) << n << endl
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector< vi > vvi;

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;

struct PropSegTree {
    #define L 2*cur + 1
    #define R 2*cur + 2
    #define md (l + r) / 2

private:
    void apply_update(ll& a, ll b, int len) {
        if (b == no_op) return;
        a = b * len;  // Apply the update to the segment based on its length
    }

    ll calc_op(ll a, ll b) {
        return a + b;
    }

    void propagate(int l, int r, int cur) {
        if (ops[cur] == no_op) return;
        apply_update(seg[cur], ops[cur], r - l + 1);
        if (l != r) {
            apply_update(ops[L], ops[cur], 1);
            apply_update(ops[R], ops[cur], 1);
        }
        ops[cur] = no_op;
    }

    void update(ll l, ll r, ll cur, ll val, ll lx, ll rx) {
        propagate(l, r, cur);
        if (r < lx || l > rx) return;
        if (l >= lx && r <= rx) {
            apply_update(ops[cur], val, 1);
            propagate(l, r, cur);
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md + 1, r, R, val, lx, rx);
        seg[cur] = calc_op(seg[L], seg[R]);
    }

    ll query(ll l, ll r, ll cur, ll lx, ll rx) {
        propagate(l, r, cur);
        if (r < lx || l > rx) return skip;
        if (l >= lx && r <= rx) {
            return seg[cur];
        }
        ll res = calc_op(query(l, md, L, lx, rx), query(md + 1, r, R, lx, rx));
        return res;
    }

public:
    vector<ll> seg, ops;
    ll skip = 0, no_op = inf, sz = 1;
    PropSegTree(ll n) {
        while (sz < n) sz *= 2; // After this, sz is the size of the last level of the seg tree
        seg = vector<ll>(sz * 2, 0);
        ops = vector<ll>(sz * 2, no_op);
    }

    void Rupdate(ll l, ll r, ll val) {
        update(0, sz - 1, 0, val, l, r);
    }

    ll query(ll l, ll r) {
        return query(0, sz - 1, 0, l, r);
    }

#undef L
#undef R
#undef md
};

void solve() {
    int q;
    cin >> n >> q;
    PropSegTree s(n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            ll l, r, val;
            cin >> l >> r >> val;
            s.Rupdate(l, r - 1, val);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << s.query(l, r - 1) << endl;
        }
    }
}

int main() {
    FASTIO;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
