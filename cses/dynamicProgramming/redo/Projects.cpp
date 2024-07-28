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

const int N = 2e5+20, M = 10;
int k,n,m;

//dp[i] the maximum value we can achieve until i = max(value achieved at prev step, value achieved at the last project that we can include with i + profit of project i)
ll dp[N]={};
void solve(){
    cin>>n;
    vector<tuple<int,int,int>> v;
    rep(i,0,n){
        int a,b,c;
        cin>>a>>b>>c;
        v.pb(make_tuple(a,b,c));
    }
    // memset(dp, dp+(ll)n, 0);
    sort(all(v),[](auto l, auto r){
        return get<1>(l) < get<1>(r);
    }); 
    // rep(i,0,n){
    //     auto [f,s,t] = v[i];
    //     cout<<f<<" "<<s<<" "<<t<<" "<<endl;
    // }
    //will sort the array based on the starting time -> ending time -> profit
    rep(i,1,n+1){
        dp[i]=dp[i-1];
        auto [f,s,p]=v[i-1];
        ll lo = 0, hi = v.size()-1;
        auto cmp = [&](ll md){
            if(get<1>(v[md]) < f) return false;
            return true;
        };
        //finds the first true given by cmp (lo). hi is the last false
        while(lo<=hi){
            ll md = lo + (hi-lo)/2;
            if(cmp(md)) hi = md - 1;
            else lo = md+1;
        }
        if(hi<0) {
            dp[i]=max(dp[i], (ll) p);
            continue;
        }
        auto [f2,s2,p2] = v[hi];
        dp[i]=max(dp[i], dp[hi+1]+p);
    }
    // rep(i,0,n+2){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout<<dp[n]<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}