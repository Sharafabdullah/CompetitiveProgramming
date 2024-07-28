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

const int N = 1e5+2, M = 10;
int k,n,m;


void solve(){
    cin>>n>>m;
    vector<set<pi>> g(n);
    int a,b;
    while(m--){
        cin>>a>>b; a--,b--;
        g[a].insert({b,-1});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    vi dst(n,inf);
    dst[0] = 0;
    vi parent(n,-1);
    while(!pq.empty()){
        auto [d, cur] = pq.top(); pq.pop();
        deb(cur)
        if(dst[cur] < d) continue;
        for(auto [ch, c]: g[cur]){
            if(dst[cur] + c < dst[ch]){
                dst[ch]=dst[cur]+c;
                pq.push({dst[cur]+c, ch});
                parent[ch] = cur;
            }
        }
    }
    deb(dst)
    if(dst[n-1]>=inf){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vi ans;
        int cur = n-1;
        while(parent[cur]!=-1){
            ans.pb(cur);
            cur = parent[cur];
        }
        ans.pb(0);
        reverse(all(ans));
        deb(ans)
        cout<<ans.size()<<endl;
        for(int i: ans){
            cout<<i+1<<" ";
        }
    }
    
}
vi dp(N,-1);
vvi g(N);
vb vis(N);
vi nxt(N);
void dfs(int cur){
    if(dp[cur]!=-1) return;

    vis[cur] =1;
    for(int ch: g[cur]){
        if(!vis[ch]){
            dfs(ch);
        }
        if((dp[ch]!=-1)&&(dp[ch]+1 > dp[cur])){
            dp[cur] = dp[ch] + 1;
            nxt[cur] = ch;
        }
    }
    return ;
}
void solve2(){
    cin>>n>>m;
    dp[n]=1;
    while(m--){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
    }
    dfs(1);
    if(dp[1]==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dp[1]<<endl;
        int node = 1;
        while(node!=0){
            cout<<node<<" ";
            node = nxt[node];
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
