#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repd(i, a, b) for (int i = a; i >= b; --i)
#define pb            push_back
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<bool>      vb;
typedef vector<vb>        vvb;
typedef vector<string>    vs;
typedef vector<int>       vi;
typedef vector<ll>       vll;
typedef vector<double>    vd;
typedef vector< vi >      vvi;

#ifndef ONLINE_JUDGE
#define deb(...) cerr << "[" << #__VA_ARGS__ << "] = "; _print(__VA_ARGS__); cerr << endl;
#else
#define deb(...)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(const char* s) {cerr << s;}


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename... Args>
void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;

#define L (2*cur + 1)
#define R (2*cur + 2)
#define md ((l+r)/2)

struct LazySegmentTree {
private:
    vll seg;
    const int skip = 0;
    
    vll ops;
    const int no_op = 0;
    int sz, n;

    inline ll merge(ll a, ll b) {
        return max(a, b);
    }

    inline void push(ll l, ll r, ll cur) {
        if (ops[cur] == no_op) return;  
        seg[cur] += ops[cur]; // Apply update to current segment
        if (l != r) {  // If not a leaf node, push lazily
            ops[L] += ops[cur];
            ops[R] += ops[cur];
        }
        ops[cur] = no_op;  // Clear the operation after propagating
    }

    void update(ll l, ll r, ll cur, ll val, ll lx, ll rx) {
        push(l, r, cur);  // Ensure the current segment is up-to-date
        if (r < lx || l > rx) return;  // Out of range
        if (l >= lx && r <= rx) {  // Full segment overlap
            ops[cur] += val;
            push(l, r, cur);  // Push the update immediately
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md + 1, r, R, val, lx, rx);
        seg[cur] = merge(seg[L], seg[R]);  // Recalculate the parent node
    }

    ll query(ll l, ll r, ll cur, ll ind) {
        push(l, r, cur);  // Ensure the current segment is up-to-date
        // if (r < lx || l > rx) return skip;  // Out of range
        if (l == r) {  // Full segment overlap
            return seg[cur];
        }

        if(ind <= md) return query(l, md, L, ind);
        else return query(md+1, r, R, ind);

        // push(l,md,L);
        // push(md+1,r,R);
        // if(seg[L] >= val){
        //     return query(l, md, L, lx, rx);
        // } else return query(md + 1, r, R, lx, rx);

    }

    void build(ll l, ll r, ll cur,const vi& a){
        if(l==r){
            if(l<a.size()) seg[cur] = a[l];
            return;
        }
        build(l, md, L,a);
        build(md+1, r, R,a);
        seg[cur] = merge(seg[R], seg[L]);
    }

public:
    LazySegmentTree(const vi& arr) : n(arr.size()) {
        sz = 1;
        while (sz < n) sz *= 2;  // Round up to the next power of two
        seg.assign(2 * sz, skip);  // Segment tree initialized to `skip`
        ops.assign(2 * sz, no_op);  // Lazy propagation array initialized to `no_op`
        build(0, sz-1, 0, arr);
    }

    void update(ll l, ll r, ll val) {
        update(0, sz - 1, 0, val, l, r);
    }

    ll query(ll ind) {
        return query(0, sz - 1, 0, ind);
    }
};

void solve(){
    cin>>n>>m;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    LazySegmentTree sg(a);
    rep(i,0,m){
        int t;
        cin>>t;
        if(t==1){
            int a,b,v;
            cin>>a>>b>>v;
            sg.update(a-1,b-1,v);
        }
        else{
            int a; cin>>a;
            
            cout<<sg.query(a-1)<<endl;
        }
    }
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
