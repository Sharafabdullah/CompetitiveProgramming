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

const int N = 3e5, M = 10;
int k,n,m;

vi g[N];
ll lazy[N]={}, val[N]={};
int lvl[N]={}, par[N]={};
bool bad[N] = {};

ll mpow(ll bs, ll exp) {
    ll res = 1;
    bs = bs;
    while (exp > 0) {
        if (exp & 1)
            res = (res * bs);
        exp = exp >> 1;
        bs = (bs * bs);
    }
    return res;
}

void propagate(int ind){
    if(lazy[ind]==0) return;
    val[ind] += lazy[ind];
    for(int ch: g[ind]){
        if(lvl[ch]<lvl[ind]) continue;
        lazy[ch] += (lazy[ind]/2);
    }
    lazy[ind]=0;
}

ll get_helper(int ind, int dst){
    vi path;
    int cnt = 0;
    int tmp = ind;
    path.pb(ind);
    while(ind !=par[ind] && cnt<30){
        cnt++;
        ind = par[ind];
        path.pb(ind);
    }
    reverse(all(path));
    for(int i: path){
        propagate(i);
    }
    // deb(path)

    return val[tmp];
}
ll get(int ind){
    return get_helper(ind, 0);
}

void dfs(int cur, int d){
    lvl[cur] = d;
    for(int ch: g[cur]){
        if(lvl[ch]!=0 || par[ch]!=0) continue;
        par[ch] = cur;
        dfs(ch, d+1);
    }

}
void solve(){
    cin>>n;
    rep(i,0,n+10) {lazy[i] = 0; val[i] =0; lvl[i] = 0;par[i]= 0;}
    rep(i,0,n-1){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    lvl[1] = 1;
    par[1]=1;
    dfs(1,1);
    int q,ind; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op==1){
            cin>>ind>>k;
            lazy[ind]+=k;
            propagate(ind);
        }
        else{
            cin>>ind;
            cout<<get(ind)<<endl;
        }
    }
    // rep(i,1,n+1) cout<<lazy[i]<<" ";
    // cout<<endl;
    // rep(i,1,n+1) cout<<lvl[i]<<" ";
    // cout<<endl;
    // rep(i,1,n+1) cout<<val[i]<<" ";
    // cout<<endl;
    rep(i,0,n+10) g[i].clear();
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}