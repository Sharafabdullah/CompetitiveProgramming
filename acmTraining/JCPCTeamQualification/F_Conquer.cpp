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

const ll inf = 1e13+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5+10, M = 10;
int k,n,m;

vector<pi> g[N];
ll dp[N][2], ans[N], fch[N];
void dfs(int cur, vb& vis){
    vis[cur] = 1;
    for(auto [ch, d]: g[cur]){
        if(d<dp[cur][0]){
            swap(dp[cur][0], dp[cur][1]);
            dp[cur][0] = d;
            fch[cur] = ch;
        }
        else if(d<dp[cur][1]) dp[cur][1] = d;
    }
    for(auto [ch,d]: g[cur]){
        if(!vis[ch]){
            dfs(ch, vis);
        }
    }
}

void dfs2(int cur, vb& vis){
    vis[cur] = 1;
    ans[cur] = 2*dp[cur][0] + dp[cur][1];
    for(auto [ch, d]: g[cur]){
        if(d==inf) continue;
        if(fch[ch] == cur){
            ans[cur] = min(ans[cur], d + dp[ch][1]);
        } else ans[cur] = min(ans[cur], d + dp[ch][0]);
    }
    for(auto [ch,d]: g[cur]){
        if(!vis[ch]){
            dfs2(ch, vis);
        }
    }
}
void solve(){
    cin>>n>>m;
    rep(i,0,n+5){
        g[i].clear();
        dp[i][0] = dp[i][1] = ans[i] = inf;
        fch[i] = -1;
    }
    rep(i,0,m){
        int a,b,l; cin>>a>>b>>l;
        g[a].pb({b,l});
        g[b].pb({a,l});
    }
    vb vis(n+1);
    dfs(1, vis);
    vis = vb(n+1, 0);
    dfs2(1, vis);
    rep(i,1,n+1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}