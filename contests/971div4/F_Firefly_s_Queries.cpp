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

vi v;
ll pref[N];
ll calc(ll a, ll b){
    return pref[b] - (a?pref[a-1]:0);
}

ll ans(ll a, ll b){
    ll sc = a/n, ec = b/n;
    deb(a) deb(b) deb(ec)
    // if(a==b){
    //     return v[(a+ sc)%n];
    // }
    if(sc == ec ){
        deb(a) deb(b)
        a %= n, b %= n;
        a = (a + sc) % n;
        b = (b + sc) % n;
        ll ret;
        if(a>b){
            ret = calc(a, n-1)  + calc(0, b); 
        }
        else{
            ret = calc(a,b);
        }
        deb(a) deb(b)
        deb(pref[b])
        deb(ret)
        return ret;
    }
    ll ret = (ec - sc - 1) * pref[n-1];
    ret += ans(a, a +n - a%n-1);
    ret += ans(ec * n, b);
    deb(a) deb(b)
    deb(ret)
    return ret;
}
void solve(){
    int q;
    cin>>n>>q;
    v = vi(n);
    rep(i,0,n) cin>>v[i];
    pref[0] = v[0];
    rep(i,1,n){
        pref[i] = pref[i-1] + v[i];
    }
    // deb(pref[2])
    while(q--){
        ll a,b; cin>>a>>b;
        cout<<ans(a-1,b-1)<<endl;
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