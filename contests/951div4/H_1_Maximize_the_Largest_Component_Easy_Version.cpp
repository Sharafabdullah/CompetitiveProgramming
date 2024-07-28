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

const int N = 3e5, M = 10;
int k,n,m;
int curI, curJ;
vb visR, visC;
vector<vb> vis;
vvi comp;
vector<string> g;
void dfs( int i, int j, int& sz, int num){
    if(i<0 || i>=n || j>=m || j<0 || vis[i][j] || g[i][j]!='#') return;
    vis[i][j] = 1;
    sz++;
    comp[i][j] = num;
    dfs(i+1, j, sz, num);
    dfs(i-1, j, sz, num);
    dfs(i, j+1, sz, num);
    dfs(i, j-1, sz, num);
};
void solve(){
    cin>>n>>m;
    // vector<string> g(n);
    g = vector<string>(n);
    comp = vvi(n, vi(m,-1));
    rep(i,0,n) cin>>g[i];
    vis = vector<vb>(n, vb(m));
    int ans = 0, num = 1;
    // deb(g)
    map<int,int> mp;
    rep(i,0,n){
        rep(j,0,m){
            if(g[i][j]=='#' && !vis[i][j]){
                int sz = 0;
                // deb(i) deb(j)
                dfs(i,j, sz, num);
                mp[num] = sz;
                num++;
                ans = max(sz, ans);
            }
        }
    }
    deb(comp)
    deb(mp)
    rep(i,0,n){
        int cur = 0;
        set<int> s;
        rep(j,0,m){
            if(comp[i][j]==-1) cur++;
            if(!s.count(comp[i][j])){
                cur += mp[comp[i][j]];
                s.insert(comp[i][j]);
            }
            if(i+1<n && !s.count(comp[i+1][j])){
                cur += mp[comp[i+1][j]];
                s.insert(comp[i+1][j]);
            }
            if(i>0 && !s.count(comp[i-1][j])){
                cur += mp[comp[i-1][j]];
                s.insert(comp[i-1][j]);
            }
            
        }
        ans = max(ans, cur);
    }

    rep(j,0,m){
        int cur = 0;
        set<int> s;
        rep(i,0,n){
            if(comp[i][j]==-1) cur++;
            if(!s.count(comp[i][j])){
                cur+=mp[comp[i][j]];
                s.insert(comp[i][j]);
            }
            if(j+1<m && !s.count(comp[i][j+1])){
                cur += mp[comp[i][j+1]];
                s.insert(comp[i][j+1]);
            }
            if(j>0 && !s.count(comp[i][j-1])){
                cur += mp[comp[i][j-1]];
                s.insert(comp[i][j-1]);
            }
        }
        ans = max(ans, cur);
    }
    cout<<ans<<endl;
}
    


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}