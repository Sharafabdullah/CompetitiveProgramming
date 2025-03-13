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

const int N = 5e4+10, M = 10;
int k,n,m;
vi a;
vi g[N];
ll v[N];
bool can = 0;

void dfs(int cur, int par){
    deb(cur) deb(a[cur])
    ll ret = (1ll<<a[cur]);
    for(int ch: g[cur]){
        if(ch== par) continue;
        dfs(ch, cur);
        ret |= (ret ^ v[ch]);
    }
    v[cur] = ret;
    if(ret & (1ll<<k)){
        can = 1;
    }
}

string DecimalToBinary(ll num)
{
    string str;
    while(num){
        str+= (num&1)?'1':'0';
        num>>=1;
    }    
    reverse(all(str));
    return str;
}

void solve(){
    cin>>n>>k;
    a = vi(n+1);
    can = 0;
    rep(i,0,n+1){
        g[i].clear();
        v[i] = 0;
    }
    int ans = 0;
    rep(i,1,n+1) {cin>>a[i];ans = ans ^ a[i];}
    rep(i,0,n-1){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0);
    rep(i,1,n+1){
        cout<<i<<": "<<DecimalToBinary(v[i])<<endl;
    }
    if(can){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}