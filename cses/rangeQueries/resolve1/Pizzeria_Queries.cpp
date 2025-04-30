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

const ll inf = 1e17+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const ll N = 3e5, M = 10;
ll k, n, m;

struct Node{
    ll first = inf, second = inf, sz = 0;
    Node(){}
    Node(ll f, ll s, ll sz) : first(f), second(s), sz(sz) {}
};
template <class T> struct SegmentTree{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vector<T> seg;
    T skip = {inf,inf, 0};
    ll sz = 1;
    T merge(T x, T y){
        T ret;
        ret.first = min(x.first, y.first + x.sz);
        ret.second = min(y.second, x.second + y.sz);
        ret.sz = x.sz + y.sz;
        return ret;
    }
    void build(ll l, ll r, ll node, vll& org){
        if(l==r){ 
            if(l<org.size()) seg[node]=Node(org[l], org[l],1);
            return;
        }

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge(seg[L], seg[R]);
    }

    void update(ll l, ll r, ll node, ll ind, ll val){
        if(l==r){
            seg[node] = {val,val,1};
            return;
        }
        if(ind<=md) update(l, md, L, ind, val);
        else update(md+1, r, R, ind, val);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    T query(ll l, ll r, ll node, ll lq, ll rq){
        if(r<lq || l > rq) return skip;
        if(l>=lq && r<=rq) return seg[node];

        return merge(query(l, md, L, lq,rq), query(md+1, r, R, lq,rq));
    }

public:
    SegmentTree(vll& arr){
        while(sz<(ll)arr.size()) sz*=2;
        seg = vector<T>(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(ll ind, ll val){
        update(0, sz-1, 0, ind, val);
    }

    pair<ll,ll> query(ll l, ll r){
        Node ret = query(0, sz-1, 0, l, r);
        return {ret.first, ret.second};
    }
#undef L
#undef R
#undef md
};

void solve(){
    ll q;
    cin>>n>>q;
    vll a(n);
    rep(i,0,n) cin>>a[i];
    SegmentTree<Node> sg(a);
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll ind, val; cin>>ind>>val;
            sg.update(ind-1, val);
        }
        else{
            ll ind; cin>>ind; ind--;
            ll ans1 = inf, ans2 = inf;
            if(ind > 0) ans1 = sg.query(0, ind).second;
            if(ind < n - 1) ans2 = sg.query(ind + 1, n - 1).first;
            cout<<min(ans1,ans2 + 1)<<endl;
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
