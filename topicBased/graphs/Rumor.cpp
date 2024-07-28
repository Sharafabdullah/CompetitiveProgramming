#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define sz(x)         ((int)(x).size())
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))


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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 1e5+100, M = 10;
int k,n,m;
 vi c(N);
 vb vis(N);
 vvi g(N);

 int dfs(int v){
    vis[v] = 1;
    int mn = c[v]; //the smallest value in the connected component

    for(int child: g[v]){
        if(!vis[child]){
            mn = min(mn, dfs(child));
        }
    }
    return mn;
 }

void solve(){
    cin>>n>>m;
    rep(i,0,n) cin>>c[i];
    int a, b;
    while(m--){
        cin>>a>>b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            ans += dfs(i);
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}