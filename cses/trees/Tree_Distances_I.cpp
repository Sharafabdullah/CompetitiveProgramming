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

const int N = 2e5+10, M = 10;
int k,n,m;
vi g[N];
int dst1[N], dst2[N];

pi bfs(int st, int* dst){
    queue<int> q;
    q.push(st);
    vb vis(n+1);
    vis[st] = 1;
    int sz = 1, d = 0, last = st;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        dst[cur] = d;
        sz--;
        for(int ch: g[cur]){
            if(!vis[ch]){
                vis[ch] = 1;
                last = ch;
                q.push(ch);
            }
        }
        if(!sz){
            sz = q.size();
            d++;
        }
    }
    return {last, d-1};
}

void solve(){
    cin>>n;
    rep(i,0,n-1){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    auto [fNode, depth] = bfs(1, dst1);

    auto [sNode, sd] = bfs(fNode, dst1);
    bfs(sNode, dst2);

    rep(i,1,n+1){
        cout<<max(dst1[i], dst2[i])<<" ";
    }

    
}

int height[N], ans[N];

void dfs(int cur, int par){
    height[cur] = 0;
    for(int ch: g[cur]){
        if(ch==par) continue;
        dfs(ch, cur);
        height[cur] = max(height[cur], height[ch]+1);
    }
}

void calc(int cur, int par, int parPartans){
    vi sufmx, prefmx;
    for(int ch: g[cur]){
        if(ch==par) continue;
        sufmx.pb(height[ch]);
        prefmx.pb(height[ch]);
    }
    int n = prefmx.size();
    for(int i = 1; i < n; i++){
        prefmx[i] = max(prefmx[i-1], prefmx[i]);
    }
    for(int i = n-2; i>=0; i--){
        sufmx[i] = max(sufmx[i+1], sufmx[i]);
    }
    int cnt= 0;
    for(int ch: g[cur]){
        if(ch == par) continue;
        int op1 = (cnt==0? -inf: prefmx[cnt-1]);
        int op2 = (cnt==n-1? -inf: sufmx[cnt+1]);
        calc(ch, cur,1 + max(parPartans, max(op1,op2)));
        cnt++;
    }
    ans[cur] = 1 + max(parPartans, (n==0 ? -1:prefmx.back()));
}

void solve2(){
    cin>>n;
    rep(i,0,n-1){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 0);
    calc(1, 0, -1);
    rep(i,1,n+1) cout<<ans[i]<<" ";

}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        // solve();
        // solve2();
        
    }
    

    return 0;
}