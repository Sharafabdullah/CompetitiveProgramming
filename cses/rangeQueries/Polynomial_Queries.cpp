#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
#define coutfloat(n,d)     cout << fixed << setprecision(d) << n << endl
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef long double   ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<bool>      vb;
typedef vector<vb>        vvb;
typedef vector<string>    vs;
typedef vector<int>       vi;
typedef vector<ll>       vll;
typedef vector<double>    vd;
typedef vector< vi >      vvi;

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
int k,n,m;

struct LazySegmentTree{
    #define L (2*cur + 1)
    #define R (2*cur + 2)
    #define md ((l+r)/2)
private:
    vll seg;
    vector<pll> ops; //for each node in lazy - store first as what to start adding and second as the step size -> (3,4) -> 3,7,11,15,...
    ll skip = 0, sz = 1, n = 0;
    pll no_op = {0, 0};

    ll merge(ll a, ll b){
        return a + b;
    }
    
    void propegate(int l, int r, int cur){
        if(ops[cur] == no_op) return;
        int len = r- l+1; auto [begin, step]= ops[cur];
        //try addign begin = 10, step = 3, l = 5, r = 8
        seg[cur]+= begin*len + step * len*(len-1)/2;
        if(l != r){
            ops[L].first += begin;
            ops[L].second += step;
            ops[R].first += begin + (len/2)* step;
            ops[R].second += step;
        }
        ops[cur] = no_op;
    }

    void update(int l, int r, int cur, int lx, int rx, ll& upL){
        propegate(l, r, cur);
        if(r < lx || l > rx) return;
        if(l >= lx && r <= rx){
            ops[cur].first += l - lx + 1;
            ops[cur].second += 1;
            propegate(l, r, cur);
            return;
        }
        update(l, md, L, lx, rx, upL);
        update(md + 1, r, R, lx, rx, upL);
        seg[cur] = merge(seg[L], seg[R]);
    }

    ll query(int l, int r, int cur, int lx, int rx){
        propegate(l, r, cur);
        if(r < lx || l > rx) return skip;
        if(l >= lx && r <= rx){
            return seg[cur];
        }
        return merge(query(l, md, L, lx, rx), query(md + 1, r, R, lx, rx));
    }

    void build(int l, int r, int cur, vi& arr){
        if(l == r){
            if(l < arr.size()) seg[cur] = arr[l];
            return;
        }
        build(l, md, L, arr);
        build(md + 1, r, R, arr);
        seg[cur] = merge(seg[L], seg[R]);
    }

public:
    LazySegmentTree(vi& arr){
        n = arr.size();
        while(sz < n) sz *= 2;

        seg = vll(sz * 2, skip);
        ops = vector<pll>(sz * 2, no_op);
        deb(ops)
        build(0, sz - 1, 0, arr);
    }

    void update(int l, int r){
        ll upL = 1;
        update(0, sz - 1, 0, l, r, upL);
    }

    ll query(int l, int r){
        return query(0, sz - 1, 0, l, r);
    }

#undef L
#undef R
#undef md
};

void solve(){
    int q; cin >> n >> q;
    vi a(n); rep(i, 0, n) cin >> a[i];
    LazySegmentTree sg(a);
    while(q--){
        int op, a, b; cin >> op >> a >> b; a--, b--;
        if(op == 1){
            sg.update(a, b);
        }
        else{
            cout << sg.query(a, b) << endl;
        }
    }
}

int main(){
    FASTIO;

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}
