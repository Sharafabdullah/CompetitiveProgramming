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

struct LazySegmentTree {
    #define L (2*cur + 1)
    #define R (2*cur + 2)
    #define md ((l+r)/2)

private:
    vll seg, lazy1, lazy2;
    int skip = 0, no_op = 0, sz = 1, n = 0;

    void apply_update1(ll& a, ll b) {
        a += b;
    }

    void apply_update2(ll& a, ll b) {
        a = b;
    }

    ll merge(ll a, ll b) {
        return a + b;
    }

    void propegate1(int l, int r, int cur) {
        propegate2(l,r,cur);
        if (lazy1[cur] == no_op) return;
        int len = r - l + 1;
        apply_update1(seg[cur], lazy1[cur] * len);
        if (l != r) {
            apply_update1(lazy1[L], lazy1[cur]);
            apply_update1(lazy1[R], lazy1[cur]);
        }
        lazy1[cur] = no_op;
    }

    void propegate2(int l, int r, int cur) {
        if (lazy2[cur] == no_op) return;
        int len = r - l + 1;
        apply_update2(seg[cur], lazy2[cur] * len);
        if (l != r) {
            lazy2[L] = lazy2[cur];  // Set lazy2 on child nodes
            lazy2[R] = lazy2[cur];
            lazy1[L] = no_op; // Clear lazy1 because update2 overrides it
            lazy1[R] = no_op;
        }
        lazy2[cur] = no_op;
    }

    void update1(int l, int r, int cur, ll val, int lx, int rx) {
        // propegate2(l, r, cur);  // Apply update2 first, if any
        propegate1(l, r, cur);  // Apply update1, if any
        if (r < lx || l > rx) return;
        if (l >= lx && r <= rx) {
            apply_update1(lazy1[cur], val);
            // propegate2(l,r,cur);
            propegate1(l, r, cur);
            return;
        }
        update1(l, md, L, val, lx, rx);
        update1(md+1, r, R, val, lx, rx);
        seg[cur] = merge(seg[L], seg[R]);
    }

    void update2(int l, int r, int cur, ll val, int lx, int rx) {
        // propegate2(l, r, cur);  // Apply update2, if any
        propegate1(l, r, cur);  // Apply update1 first, if any
        if (r < lx || l > rx) return;
        if (l >= lx && r <= rx) {
            apply_update2(lazy2[cur], val);
            // propegate2(l, r, cur);
            propegate1(l, r, cur);
            return;
        }
        update2(l, md, L, val, lx, rx);
        update2(md+1, r, R, val, lx, rx);
        seg[cur] = merge(seg[L], seg[R]);
    }

    ll query(int l, int r, int cur, int lx, int rx) {
        // propegate2(l, r, cur);  // Apply update2 first, if any
        propegate1(l, r, cur);  // Apply update1, if any
        if (r < lx || l > rx) return skip;
        if (l >= lx && r <= rx) {
            return seg[cur];
        }
        return merge(query(l, md, L, lx, rx), query(md+1, r, R, lx, rx));
    }

    void build(int l, int r, int cur, vi& arr) {
        if (l == r) {
            if (l < arr.size()) seg[cur] = arr[l];
            return;
        }
        build(l, md, L, arr);
        build(md+1, r, R, arr);
        seg[cur] = merge(seg[L], seg[R]);
    }

public:
    LazySegmentTree(vi& arr) {
        n = arr.size();
        while (sz < n) sz *= 2;

        seg = vll(sz * 2, skip);
        lazy1 = vll(sz * 2, no_op);
        lazy2 = vll(sz * 2, no_op);
        build(0, sz - 1, 0, arr);
    }

    void update1(int l, int r, int val) {
        update1(0, sz - 1, 0, val, l, r);
    }

    void update2(int l, int r, int val) {
        update2(0, sz - 1, 0, val, l, r);
    }

    ll query(int l, int r) {
        return query(0, sz - 1, 0, l, r);
    }

    #undef L
    #undef R
    #undef md
};


void solve(){
    int q; cin>>n>>q;
    vi a(n); rep(i,0,n) cin>>a[i];
    LazySegmentTree sg(a);
    while(q--){
        int op, x,y,z; cin>>op;
        if(op==1){
            cin>>x>>y>>z; x--,y--;
            sg.update1(x,y, z);
        } 
        else if(op==2){
            cin>>x>>y>>z; x--,y--;
            sg.update2(x,y,z);
        }
        else{
            cin>>x>>y; x--,y--;
            cout<<sg.query(x,y)<<endl;
        }
    }
    
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}