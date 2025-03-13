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

const ll inf = 1e15+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;




void solve(){
    cin>>n;
    vi a(n); rep(i,0,n) cin>>a[i];

    
}

void solve2(){
    cin>>n;
    vi a(n), tmp(n); rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>tmp[i];

    vll add(n+2), mul(n+2), pref(n+1), ans(n);

    rep(i,0,n) pref[i+1] = pref[i] + tmp[i];
    pref.pb(inf);
    deb(pref)
    rep(i,0,n){
        mul[i]+=1;
        ll lo = i+1, hi = n+1;
        auto cmp = [&](ll md){
            if(pref[md] - pref[i] > a[i]) return true;
            return false;
        };
        //finds the first true given by cmp (lo). hi is the last false
        while(lo<=hi){
            ll md = lo + (hi-lo)/2;
            if(cmp(md)) hi = md - 1;
            else lo = md+1;
        }
        deb(i)
        deb(lo)
        deb(pref[lo] - pref[i])
        lo--; // to make it zero based
        deb(pref[lo] - pref[i])
        mul[lo]-=1;
        add[lo] += a[i] - (lo==i? 0: (pref[lo]-pref[i]));
    }
    deb(add)
    rep(i,1,n+1){
        mul[i] += mul[i-1];
    }
    deb(mul) 
    rep(i,0,n){
        ans[i] = mul[i] * tmp[i] + add[i];
    }
    rep(i,0,n) cout<<ans[i]<<" ";
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        // solve();
        solve2();
    }
    

    return 0;
}