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

const int N = 2e5+10, M = 21;
int k,n,m;

int ancestor[N][M]; //stores 2^0 , 2^1, 2^2, ... , 2^M ancestor of every node
vi g[N];
void dfs(int cur, int par){
    ancestor[cur][0] = par;
    // deb(cur)
    for(int j = 1; j<M; j++){
        if(ancestor[cur][j-1]!=-1){
            ancestor[cur][j] = ancestor[ancestor[cur][j-1]][j-1];
            // the 8th ancestor of me is the 4th ancestor of my 4th ancestor
        }
        else ancestor[cur][j] = -1;
    }
    for(int ch: g[cur]){
        if(ch == par) continue;
        dfs(ch, cur);
    }
}
int query(int cur, int msk){
    for(int j = M-1; j>=0; j--){
        if((1<<j)&msk){
            cur = ancestor[cur][j];
            if(cur==0 || cur==-1) return -1;
        }
    }
    return cur;
}
void solve(){
    cin>>n>>k;
    for(int i = 2; i < n + 1; i++){
        int a;
        cin>>a;
        g[a].pb(i);
        g[i].pb(a);
    }
    dfs(1, -1);
    while(k--){
        int node, anc; cin>>node>>anc;
        cout<<query(node, anc)<<endl;
    }
    
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