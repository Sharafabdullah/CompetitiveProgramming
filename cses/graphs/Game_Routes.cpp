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

const int N = 1e5+1, M = 10;
int k,n,m;


void solve(){
    cin>>n>>m;
    vvi g(n);
    int a,b;
    vi inDeg(n);
    while(m--){
        cin>>a>>b;a--,b--;
        g[a].pb(b);
        inDeg[b]++;
    }
    queue<int> q;
    rep(i,1,n){
        if(!inDeg[i]) q.push(i);
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int ch: g[cur]){
            inDeg[ch]--;
            if(!inDeg[ch] && ch!=0){
                q.push(ch);
            }
        }
    }
    vi cnt(n);
    q.push(0);
    cnt[0]=1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int ch: g[cur]){
            inDeg[ch]--;
            cnt[ch]+=cnt[cur];
            cnt[ch]%=mod;
            if(!inDeg[ch]){
                q.push(ch);
            }
        }
    }
    cout<<cnt[n-1]<<endl;
    
}

vi dp(N,-1);
vvi g(N);
vb vis(N);

int dfs(int cur){
    if(dp[cur]!=-1) return dp[cur];
    dp[cur]=0;
    for(int ch: g[cur]){
        dp[cur] = (dp[cur]+dfs(ch))%mod;
    }
    return dp[cur];
}

void solve2(){
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        g[a].pb(b);
    }
    dp[n] = 1;
    dfs(1);
    cout<<dp[1]<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    solve2();
    

    return 0;
}