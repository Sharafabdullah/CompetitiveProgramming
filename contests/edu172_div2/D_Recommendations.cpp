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


template <class T> struct SegmentTree2{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vector<T> seg;
    T skip = inf;
    int sz = 1;
    T merge(T x, T y){
        return min(x, y);
    }
    void build(int l, int r, int node, vll& org){
        if(l==r){ 
            if(l<org.size()) seg[node]=org[l];
            return;
        }

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge(seg[L], seg[R]);
    }

    void update(int l, int r, int node, T val, int ind){
        if(l==r){
            seg[node] = val;
            return;
        }

        if(ind<=md) update(l, md, L, val, ind);
        else update(md+1, r, R, val, ind);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    T query(int l, int r, int node, int lq, int rq, int val){
        if(r<lq || l > rq ) return skip;
        if(l>=lq && r<=rq && val < seg[node]) return seg[node];

        return merge(query(l, md, L, lq,rq,val), query(md+1, r, R, lq,rq,val));
    }

public:
    SegmentTree2(vll& arr){
        while(sz<(int)arr.size()) sz*=2;
        seg = vector<T>(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(int ind, T val){
        update(0, sz-1, 0, val, ind);
    }

    T query(int l, int r, int val){
        return query(0, sz-1, 0, l, r, val);
    }
#undef L
#undef R
#undef md
};

struct node{
    ll l, r, ind;
    node(){}
    node(ll l, ll r, ll ind): l(l), r(r), ind(ind){}
    bool const operator<(const auto& other){
        if(l != other.l){
            return l < other.l;
        }
        else{
            return r > other.r;
        }
    }
};

void solve(){
    cin>>n;
    vector<node> v(n);
    vll sec(n), fst(n);
    rep(i,0,n) {
        cin>>v[i].l>>v[i].r;
        v[i].ind = i;
    } 
    sort(all(v));
    rep(i,0,n){
        sec[i] = v[i].r;
        fst[i] = v[i].l;
    }
    deb(sec)
    SegmentTree2<ll> secSeg(sec);
    // deb(v)
    vll ans(n);
    rep(i,0,n){
        auto [l ,r, ind] = v[i];
        if(i==0){
            ans[ind] = 0;
            continue;
        }
        ll rng = v[i].r - v[i].l + 1;
        deb(rng)
        int mn = 0;
        if(i>0) mn = secSeg.query(0, i-1, r);
        deb(mn)
        // secSeg.update(i, sec[i]);f
        deb(mn)
        if(mn >= inf) ans[ind] = 0;
        else ans[ind] =max(0ll, abs(sec[i] - mn + 1) - rng);
    }
    for(auto a: ans){cout<<a<<endl;}
}

int main(){
    FASTIO;

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
