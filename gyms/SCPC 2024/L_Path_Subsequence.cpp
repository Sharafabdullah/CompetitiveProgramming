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

const int N = 2e5+10, M = 18;
int k,n,m;

vi g[N];
int up[N][M]={};
int d[N],sz[N], head[N];

void dfs_lca(int cur, int par, int dd){
    up[cur][0] = par;
    d[cur] = dd;
    for(int i = 1; i<M; i++){
        if(up[cur][i-1]) up[cur][i] = up[up[cur][i-1]][i-1];
    }
    for(int ch: g[cur]){
        if(ch == par) continue;
        dfs_lca(ch, cur, dd+1);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);

    for (int i = M-1; i >= 0; i--) 
        if ((d[u] - d[v]) & (1 << i)) u = up[u][i];
    
    if (u == v) return u;
    for (int i = M-1; i >= 0; i--) {
        if (up[v][i] != up[u][i]) {
            v = up[v][i];
            u = up[u][i];
        }
    }
    return up[u][0];
}

ll mpow(ll bs, ll exp) {
    ll res = 1;
    bs = bs % mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * bs) % mod;
        exp = exp >> 1;
        bs = (bs * bs) % mod;
    }
    return res;
}

ll fact[N] , fact_inv[N];
inline ll nck(ll n,ll k){    
    if(k>n) return 0;
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) %mod;
}
void cf(){
    fact[0] = 1;
    for(ll i = 1;i < N;i++) fact[i] = i * fact[i - 1] % mod;
    fact_inv[N - 1] = mpow(fact[N - 1] , mod - 2);
    for(ll i = N - 2;i >= 0;i--) fact_inv[i] = fact_inv[i + 1] * (i + 1) % mod;
}
//! don't forget to call cf()


void solve(){
    cin>>n;
    rep(i,0,n+1) {
        g[i].clear();
        rep(j,0,(int)M){
            up[i][j] = 0;
        }
        sz[i] = 0;
        d[i] = 0;
        head[i] = 0;
    }
    int a,b;
    rep(i,0,n-1){
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int q;
    dfs_lca(1,0,0);
    cin>>q;
    while(q--){
        cin>>a>>b;
        int lc = lca(a,b);
        int a1 = d[a] - d[lc];
        int b1 = d[b] - d[lc];
        cout<<nck(a1+b1, a1)<<endl;
    }

    
}


int main(){
    FASTIO;
    cf();
    // #ifndef ONLINE_JUDGE
            freopen("path.in", "r", stdin);
            // freopen("output.txt", "w", stdout);
        // #endif
    int t= 1;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}