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
typedef pair<ll, ll> pll;
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

const ll inf = 1e17+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n>>m;
    vector<tuple<ll,ll,ll>> g(n+1);
    for (int i = 1; i <= n; i++)
    {
        g.pb({0, i, 0});
    }
    
    while(m--){
        ll a,b,c; cin>>a>>b>>c;
        g.pb({a,b,c});
    }
    
    vll dst(n+1, inf); dst[0] = 0;
    vi parent(n+1);
    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for(auto [a,b,c]: g){
            if(dst[a]==inf) continue;
            if(c + dst[a] < dst[b]){
                parent[b] = a;
                dst[b] = c + dst[a];
                x = b;
            }
        }
    }
    deb(dst) deb(parent)
    deb(x)
    if(x==-1){
        cout<<"NO"<<endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        x = parent[x];
    }
    int r = x;
    vi circle;

    circle.pb(x);
    x=  parent[x];
    while(r != x){
        circle.pb(x);
        x = parent[x];
    }
    circle.pb(x);
    reverse(all(circle));
    cout<<"YES"<<endl;
    for(int i: circle) cout<<i<<" ";
    
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    tuple<ll,ll,pi,ll> p;
    ll a,b,c; pi d;
    

    return 0;
}