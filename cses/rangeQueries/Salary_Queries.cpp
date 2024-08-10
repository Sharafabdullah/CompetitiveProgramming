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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


void solve(){
    cin>>n>>m;
    ordered_set<pi> os;
    map<int,int> mp; rep(i,0,n){cin>>k;os.insert({k, i}); mp[i] = k;}
    
    while(m--){
        char op; cin>>op;
        if(op=='!'){
            int p, v; cin>>p>>v;p--;
            int oldVal = mp[p];
            os.erase({oldVal, p});
            os.insert({v, p});
            mp[p] = v;
        }
        else{
            int a,b; cin>>a>>b;
            int o1 = os.order_of_key({a,0});
            int o2 = os.order_of_key({b,inf}); //finds the order of the first element greater than b
            cout<<o2-o1<<endl;

        }
    }

    
}

struct SegTree{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vi seg;
    ll skip = 0,sz = 1;
    ll merge(ll x, ll y){
        return x+y;
    }
    void build(int l, int r, int node, vi& org){
        if(l==r){ if(l<n) seg[node]=org[l]; return;}

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int node, ll val, int ind){
        if(l==r){
            seg[node]+=val;
            return;
        }

        if(ind<=md) update(l, md, L, val, ind);
        else update(md+1, r, R, val, ind);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    ll query(int l, int r, int node, int lq, int rq){
        if(r<lq || l > rq) return skip;
        if(l>=lq && r<=rq) return seg[node];

        return merge(query(l, md, L, lq,rq), query(md+1, r, R, lq,rq));
    }

public:
    SegTree(int n){
        // int n = arr.size();
        while(sz<n) sz*=2;
        seg = vi(sz*2,skip);
        // build(0, sz-1, 0, arr);
    }
    
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    ll query(int l, int r){
        return query(0, sz-1, 0, l, r);
    }
#undef L
#undef R
#undef md
};

void solve2(){
    cin>>n>>m;
    vi bounds;
    vi arr(n); rep(i,0,n) {cin>>arr[i]; bounds.pb(arr[i]);}
    vector<array<int,3>> qrs(m);
    rep(i,0,m){
        char op; cin>>op;
        int a,b;
        cin>>a>>b;
        bounds.pb(b);
        qrs[i][1]=a, qrs[i][2]=b;
        if(op=='?') {qrs[i][0] = 1;bounds.pb(a); bounds.pb(b);}
        else qrs[i][0] = 0;
    }
    sort(all(bounds));
    bounds.erase( unique(all(bounds)), bounds.end());
    deb(bounds)

    SegTree sg((int)bounds.size());
    rep(i,0,n){
        int id = lower_bound(all(bounds), arr[i]) - bounds.B;
        deb(id)
        if(id == bounds.size()) continue;
        sg.update(id, 1);
    }

    rep(i,0, m){
        auto [op, one, two] = qrs[i];
        
        if(op==1){
            auto it1 = lower_bound(all(bounds), one) - bounds.B;
            auto it2 = lower_bound(all(bounds), two) - bounds.B;
            deb(it1) deb(it2)
            cout<<sg.query(it1,it2)<<endl;
        }
        else{
            one--;
            int val = arr[one];
            int oldPos = lower_bound(all(bounds), val) - bounds.B;
            deb(oldPos)
            deb(sg.query(oldPos, oldPos));
            sg.update(oldPos, -1);
            deb(sg.query(oldPos, oldPos));
            arr[one] = two;
            int pos = lower_bound(all(bounds), two) - bounds.B;
            sg.update(pos, 1);
        }
    }
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    solve2();
    

    return 0;
}