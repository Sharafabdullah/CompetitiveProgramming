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


void solve(){
    cin>>n>>m;
    multiset<int> ms;
    map<int, set<int>> mp;
    vi h(n); rep(i,0,n) {cin>>h[i];}
    for(int i = n-1; i>=0; i--) {ms.insert(h[i]);mp[h[i]].insert(i+1);}
    deb(ms)
    deb(mp)
    rep(i,0,m){
        int r;
        cin>>r;
        auto hotel = ms.lower_bound(r);
        deb(*hotel)
        if(hotel==ms.end()){
            cout<<0<<" ";
            continue;
        }
        auto ind = mp[*hotel].begin();
        cout<< *ind<<" ";
        int nval = *hotel - r;
        mp[*hotel].erase(ind);
        ms.erase(hotel);
        
        ms.insert(nval);
        mp[nval].insert(*ind);
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
        return max(x, y);
    }
    void build(int l, int r, int node, vi& org){
        if(l==r){ if(l<n) seg[node]=org[l]; return;}

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

    ll query(int l, int r, int node, int val){
        if(l==r){
            if(seg[node]>=val){
                seg[node]-=val;
                return l;
            }
            return -1;
        }
        ll ans = 0;
        if(seg[L] >= val){
            ans = query(l, md, L, val);
        }
        else ans= query(md+1, r, R, val);
        seg[node] = merge(seg[L], seg[R]);
        return ans;
    }

public:
    SegTree(vi& arr){
        int n = arr.size();
        while(sz<n) sz*=2;
        seg = vi(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    ll query(int val){
        return query(0, sz-1, 0, val);
    }
#undef L
#undef R
#undef md
};
void solve2(){
    cin>>n>>m;
    vi a(n); rep(i,0,n) cin>>a[i];
    SegTree sg(a);
    while(m--){
        int r; cin>>r;
        int ind = sg.query(r);
        if(ind==-1){
            cout<<0<<" ";
        }
        else{
            cout<<ind+1<<" ";
            // assert(ind < a.size());
            // a[ind] -= r;
            // sg.update(ind, a[ind]);
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