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

const int N = 1e5+2, M = 10;
int k, n, m;

vector<vector<pair<ll,ll>>> g(N);
vector<vll> dp(N, vll(2));
vi sz(N,1);
void dfs(int cur, int par){
    for(auto [ch,c]: g[cur]){
        if(ch==par) continue;
        dfs(ch,cur);
        sz[cur] += sz[ch];
    }

    ll myChildren = sz[cur] - 1;
    set<pair<ll, pi>> s;

    for(auto [ch, c]: g[cur]){
        if(ch==par) continue;
        dp[cur][0] += c*sz[ch] + dp[ch][0];
        dp[cur][1] += dp[ch][1] + 2*c;

        s.insert({(dp[ch][1] + 2*c) * (myChildren - sz[ch]), {ch,c}});
    }

    set<pair<ll,pi>> newS;
    int taken = 1;

    while(taken < g[cur].size()-(par==-1?0:1)){
        dp[cur][0] += (*s.begin()).first;
        myChildren -= sz[(*s.begin()).second.first];

        int skip = 1;
        for(auto [f,p]: s){
            auto [ch,c] = p;
            if(skip){
                skip=0;
                continue;
            }
            newS.insert({(dp[ch][1] + 2*c) * (myChildren - sz[ch]),{ch, c}});
        }

        s = newS;
        taken++;
    }

}
void solve(){
    cin>>n;
    int a,b,c;
    rep(i,0,n-1){
        cin>>a>>b>>c;a--,b--;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    dfs(0, -1);
    // rep(i,0,n) cout<<dp[i][0] << " "<<dp[i][1]<<endl;
    cout<<fixed<<setprecision(6) << ((long double) dp[0][0])/((long double) n)<<endl;;
    rep(i,0,n){
        g[i].clear();
        dp[i][0] = dp[i][1] = 0;
        sz[i] = 1;
    }
}

int main(){
    FASTIO;

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
