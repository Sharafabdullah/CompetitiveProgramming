#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repd(i, a, b) for (int i = a; i >= b; --i)
#define pb            push_back
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
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
#define deb(...) cerr << "[" << #__VA_ARGS__ << "] = "; _print(__VA_ARGS__); cerr << endl;
#else
#define deb(...)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(const char* s) {cerr << s;}


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename... Args>
void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 21;
int k, n, m;
vector<int> dp;

// ll dfs(int ind, int cur_mask){
//     if(cur_mask == (1<<n) - 1){
//         return 0;
//     }
//     if(ind == n){
//         return inf;
//     }
//     return min(dfs(ind + 1, cur_mask), dfs(ind + 1, cur_mask & (one_ride[cur_mask])));
// }

void solve(){
    cin>>n>>k;
    vll a(n);
    dp = vi(1 << n, inf);
    rep(i,0,n){
        cin>>a[i];
    }
    deb(a)
    dp[0] = 0;
    rep(i,0,1<<n){
        dp[i] = __builtin_popcount(i);
    }
    vi one_ride;
    for(int mask = 0;mask < (1<<n); mask++){
        ll sum = 0;
        rep(j,0,n){
            if((mask & (1<<j)) != 0){
                sum += a[j];
                if(sum > k) break;
            }
        }
        if(sum<=k) one_ride.pb(mask);
    }

    for(int mask = 0;mask < (1<<n); mask++){
        rep(i,0,n){
            dp[mask | (1<<i)] = min(dp[mask | (1<<i)], dp[mask] + 1);
        }
    }
    deb(dp)
    cout<<dp[(1<<n) - 1]<<endl;
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
