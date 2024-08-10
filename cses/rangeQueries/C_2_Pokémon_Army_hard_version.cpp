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

template <class T> struct SegmentTree{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vector<T> seg;
    T skip = T(0,0,0,0);
    int sz = 1;
    T merge(T x, T y){
        T ret;
        ret.omn = min(x.emn + y.omn, x.omn - y.emx);
        ret.omx = max(x.emx + y.omx, x.omx - y.emn);

        ret.emn = min(x.emn + y.emn, x.omn - y.omx);
        ret.emx = max(x.emx + y.emx, x.omx - y.omn);
        return ret;
    }
    void build(int l, int r, int node, vi& org){
        if(l==r){ if(l<n) seg[node]=T(org[l], org[l], 0,0); return;}

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int node, ll val, int ind){
        if(l==r){
            seg[node] = T(val,val, 0,0);
            return;
        }

        if(ind<=md) update(l, md, L, val, ind);
        else update(md+1, r, R, val, ind);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    T query(int l, int r, int node, int lq, int rq){
        if(r<lq || l > rq) return skip;
        if(l>=lq && r<=rq) return seg[node];

        return merge(query(l, md, L, lq,rq), query(md+1, r, R, lq,rq));
    }

public:
    SegmentTree(vi& arr){
        while(sz<(int)arr.size()) sz*=2;
        seg = vector<T>(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    T query(int l, int r){
        return query(0, sz-1, 0, l, r);
    }
#undef L
#undef R
#undef md
};

struct Node{
    ll omn, omx, emn,emx;
    Node(){}
    Node(ll a, ll c, ll b, ll s):omn(a), omx(c), emn(b), emx(s){};
};

void solve(){
    int q; cin>>n>>q;
    vi a(n); rep(i,0,n )cin>>a[i];
    bool d = 0;
    SegmentTree<Node> sg(a);
    Node ans = sg.query(0,n-1);
    cout<<max(ans.omx, ans.emx)<<endl;
    while(q--){
        int s,b; cin>>s>>b; s--,b--;
        sg.update(s, a[b]);
        sg.update(b, a[s]);
        swap(a[s], a[b]);
        Node ans = sg.query(0,n-1);
        cout<<max(ans.omx, ans.emx)<<endl;
    }
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}