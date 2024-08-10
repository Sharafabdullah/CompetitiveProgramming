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


// #ifndef ONLINE_JUDGE
// #define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
// #define deb(x)
// #endif

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(ld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;

struct SegTree1{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vll seg;
    ll skip = 0,sz = 1;
    ll merge(ll x, ll y){
        return x | y;
    }
    void build(int l, int r, int node, vll& org){
        if(l==r){
            if(l<org.size()) seg[node]=org[l];
              return;}

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int node, ll val, int ind){
        if(l==r){
            seg[node] = val;
            return;
        }

        if(ind<=md) update(l, md, L, val, ind);
        else update(md+1, r, R, val, ind);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    ll get(int l, int r, int node, int lq, int rq){
        if(r<lq || l > rq) return skip;
        if(l>=lq && r<=rq) return seg[node];

        return merge(get(l, md, L, lq,rq), get(md+1, r, R, lq,rq));
    }

public:
    SegTree1(vll& arr){
        int n = arr.size();
        while(sz<n) sz*=2;
        seg = vll(sz*4,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    ll get(int l, int r){
        return get(0, sz-1, 0, l, r);
    }
#undef L
#undef R
#undef md
};

struct SegTree2{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vll seg;
    ll skip = (1ll << 61)-1,sz = 1;
    ll merge(ll x, ll y){
        return x & y;
    }
    void build(int l, int r, int node, vll& org){
        if(l==r){if(l<org.size()) seg[node]=org[l]; return;}

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int node, ll val, int ind){
        if(l==r){
            seg[node] = val;
            return;
        }

        if(ind<=md) update(l, md, L, val, ind);
        else update(md+1, r, R, val, ind);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    ll get(int l, int r, int node, int lq, int rq){
        if(r<lq || l > rq) return skip;
        if(l>=lq && r<=rq) return seg[node];

        return merge(get(l, md, L, lq,rq), get(md+1, r, R, lq,rq));
    }

public:
    SegTree2(vll& arr){
        int n = arr.size();
        while(sz<n) sz*=2;
        seg = vll(sz*4,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    ll get(int l, int r){
        return get(0, sz-1, 0, l, r);
    }
#undef L
#undef R
#undef md
};

struct SegTree3{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vll seg;
    ll skip = 0,sz = 1;
    ll merge(ll x, ll y){
        return x ^ y;
    }
    void build(int l, int r, int node, vll& org){
        if(l==r){if(l<org.size()) seg[node]=org[l]; return;}

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int node, ll val, int ind){
        if(l==r){
            seg[node] = val;
            return;
        }

        if(ind<=md) update(l, md, L, val, ind);
        else update(md+1, r, R, val, ind);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    ll get(int l, int r, int node, int lq, int rq){
        if(r<lq || l > rq) return skip;
        if(l>=lq && r<=rq) return seg[node];

        return merge(get(l, md, L, lq,rq), get(md+1, r, R, lq,rq));
    }

public:
    SegTree3(vll& arr){
        int n = arr.size();
        while(sz<n) sz*=2;
        seg = vll(sz*4,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    ll get(int l, int r){
        return get(0, sz-1, 0, l, r);
    }
#undef L
#undef R
#undef md
};

void solve(){
    cin>>n;
    vll a(n); rep(i,0,n) cin>>a[i];
    SegTree1 sg1(a);
    SegTree2 sg2(a);
    SegTree3 sg3(a);
    cin>>m;
    while(m--){
        int a,b; cin>>a>>b; a--,b--;
        cout<<sg1.get(a,b) + sg2.get(a,b) + sg3.get(a,b)<<endl;
    }
}

int32_t main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    // return 0;
}