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
typedef pair<ll, ll> pi;
typedef vector<bool>      vb;
typedef vector<vb>        vvb;
typedef vector<string>    vs;
typedef vector<ll>       vi;
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

const ll inf = 1e17+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n>>m;
    vector<vector<pi>> g(n);
    ll a,b,c;
    while(m--){
        cin>>a>>b>>c; a--,b--;
        g[a].pb({b,c});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});

    vi ways(n),mn(n), mx(n), dst(n,inf);
    dst[0] = 0;
    ways[0] = 1;
    while(!pq.empty()){
        auto [d, cur] = pq.top(); pq.pop();
        // deb(cur)
        if(d > dst[cur]) continue;
        for(auto [to, c]: g[cur]){
            if(c + d > dst[to]) continue;
            else if(c + d == dst[to]){
                ways[to] = (ways[to] + ways[cur])%mod;
                mn[to] = min(mn[to], mn[cur]+1);
                mx[to] = max(mx[to], mx[cur]+1);
            }
            else{
                ways[to] = ways[cur]%mod;
                mn[to] = mn[cur]+1;
                mx[to] = mx[cur]+1;
                dst[to]= c+d;
                pq.push({c+d, to});
            }
        }
    }
    deb(ways)
    deb(mn)
    cout<<dst[n-1]<<" "<<ways[n-1]<<" "<<mn[n-1]<<" "<<mx[n-1];
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}