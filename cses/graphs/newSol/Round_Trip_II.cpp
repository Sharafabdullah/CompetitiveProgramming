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
void _print(const char* s) {cerr << s;}


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

const int N = 3e5, M = 10;
int k, n, m;
vvi g;
vb inStack, vis;
vi parent;
vi ans;
stack<int> st;

void dfs(int i){
    vis[i] = 1;
    inStack[i] = 1;
    st.push(i);
    
    for(int ch: g[i]){
        // if(ans.size()) return;
        if(inStack[ch]){
            ans.pb(ch);
            while(!st.empty() && st.top()!=ch) {
                ans.pb(st.top());
                st.pop();
            }
            ans.pb(ch);
            return;
        }
        if(vis[ch]) continue;
        parent[ch] = i;
        dfs(ch);
        if(ans.size()) return;
    }
    inStack[i] = 0;
    st.pop();
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    inStack.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);

    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
    }
    rep(i,1,n+1){
        if(!vis[i]) {
            dfs(i);
            if(ans.size()) break;
        }
    }
    if(ans.size()){
        reverse(all(ans));
        cout<<ans.size()<<endl;
        for(int i: ans) cout<<i<<" ";
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
