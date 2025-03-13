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

const int N = 50001, M =501;
int k,n,m;

vi g[N];
ll dp[N][M]={0}, dp2[N][M]={0};
ll ans = 0;
void dfs(int cur, int par){
    for(int ch: g[cur]){
        if(ch == par) continue;
        dfs(ch, cur);
    }
    dp[cur][0] = 1;
    for(int distance = 1; distance <= k; distance++)
    {
        dp[cur][distance] = 0;
        for(int child : g[cur])
            if(child != par)
                dp[cur][distance] += dp[child][distance-1];
    }
}

void calc(int cur, int par){
    for(int dis = 0; dis <= k; dis++)
    dp2[cur][dis] = dp[cur][dis];
 
    if(par != 0)
    {
       dp2[cur][1] += dp2[par][0];
       for(int dis = 2; dis <= k; dis++)
       {
           dp2[cur][dis] += dp2[par][dis - 1];
           dp2[cur][dis] -= dp[cur][dis - 2];
       }
    }
    deb(dp[cur][k])
    deb(dp2[cur][k])
    deb(cur) 
    for(int ch: g[cur]){
        if(ch == par) continue;
        calc(ch, cur);
    }
}

void solve(){
    cin>>n>>k;
    rep(i,0,n-1){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    dfs(1,0);
    // rep(i,1,n+1){
    //     rep(k, 0, 5){
    //         cout<<dp[i][k]<<" ";
    //     }
    //     cout<<endl;
    // }
    ans = 0;
    calc(1, 0);
    rep(i,1,n+1){
        ans += dp2[i][k];
    }
    cout<<ans/2<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}