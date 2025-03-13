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

const ll inf = 1e18+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 1e5+10, M = 10;
int k,n,m;

vi g[N];
void solve(){
    cin>>n;
    int a;
    rep(i,2,n+1){
        cin>>a;
        g[a].pb(i);
        // g[i].pb(a);
    }
    bool type[n+1], vis[n+1];
    rep(i,1,n+1) cin>>type[i];
    vll cost(n+1); rep(i,1,n+1) cin>>cost[i];

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    int d= 0, sz = 1;
    ll dp[2] = {0};
    while(!q.empty()){
        int cur = q.front(); q.pop();
        sz--;
        if(d%2){
            if(type[cur]) dp[1] += cost[cur];
            else dp[0] += cost[cur];
        }
        else{
            if(type[cur]){
                dp[0]+=cost[cur];
            }
            else dp[1] += cost[cur];
        }
        // dp[d%2? type[cur]: !type[cur] ] += cost[cur];
        for(int ch: g[cur]){
            if(!vis[ch]){
                vis[ch] = 1;
                q.push(ch);
            }
        }
        if(!sz){
            sz = q.size();
            d++;
        }
    }
    cout<<min(dp[0],dp[1])<<endl;
}

vll cost(N+1); 
vi type(N+1), vis(N+1);
ll ans=  inf, ccost = 0;
void dfs(int cur, bool req){
    if(req != type[cur]) ccost += cost[cur];
    vis[cur] = 1;
    for(int ch: g[cur]){
        if(!vis[ch]){
            dfs(ch, !req);
        }
    }
}

void solve2(){
    cin>>n;
    rep(i,2,n+1){
        int a;
        cin>>a;
        g[a].pb(i);
    }
    rep(i,1,n+1) cin>>type[i];
    rep(i,1,n+1) cin>>cost[i];
    dfs(1,1);
    ans = min(ccost, ans);
    ccost = 0;
    vis = vi(n+1);
    dfs(1,0);
    cout<<min(ans, ccost)<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        // solve();
        solve2();
    }
    

    return 0;
}