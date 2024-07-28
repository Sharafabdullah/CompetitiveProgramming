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
const ll mod = 998244353;

const int N = 5e3+10, M = 10;
int k,n,m;

ll mpow(ll bs, ll exp) {
    ll res = 1;
    bs = bs % mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * bs) % mod;
        exp = exp >> 1;
        bs = (bs * bs) % mod;
    }
    return res;
}
ll fact[N] , fact_inv[N];
inline ll nck(ll n,ll k){    
    if(n<0 || k>n) return 0;
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}
void cf(){
    fact[0] = 1;
    for(ll i = 1;i < N;i++) fact[i] = i * fact[i - 1] % mod;
    fact_inv[N - 1] = mpow(fact[N - 1] , mod - 2);
    for(ll i = N - 2;i >= 0;i--) fact_inv[i] = fact_inv[i + 1] * (i + 1) % mod;
}
//! don't forget to call cf()


void solve(){
    cin>>n;
    vll a(n); rep(i,0,n) cin>>a[i];
    sort(all(a));
    ll ans = 0;
    for(int choose = 1; choose<=n; choose++){
        for(int ind = choose; ind<=n; ind++){
            ans += a[ind-1] * nck(ind-1, choose-1);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
} 

int dp[N][N];

int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
} 
 
int mul(int x, int y) {
  return x * 1LL * y % mod;
}
void solve2(){
    cin>>n;
    int sum = 0;
    vi a(n); rep(i,0,n) {cin>>a[i];sum+=a[i];}
    sort(all(a));
    memset(dp, 0, sizeof(dp));
    vll dp[n+1];
    rep(i,0,n+1){
        dp[i] = vll(sum+1);
    }
    // dp[0][0] = 1;
    ll ans = 0;
    for(int i = 0; i<n; i++){
        dp[i+1][a[i]]++;
        ans= add(ans, a[i]);
        for(int s = 0; s<=sum; s++){
            dp[i+1][s] = add(dp[i+1][s], dp[i][s]);
            if(s + a[i]>sum) continue;
            dp[i+1][s+a[i]] += dp[i][s];
            dp[i+1][s+a[i]]%=mod;

            if(a[i] > (s+a[i]+1)/2) {
                ans += mul(a[i], dp[i][s]);
                ans %=mod;
            }
            else{
                ans += mul((s+a[i]+1)/2, dp[i][s]);
                ans %=mod;
            }
        }   
    }
    cout<<ans % mod<<endl;
}



void solve3(){
    int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int s = accumulate(a.begin(), a.end(), 0);
  vector<int> dp(s + 1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = s - a[i]; j >= 0; --j) 
      dp[j + a[i]] = add(dp[j + a[i]], dp[j]);
  int ans = 0;
  for (int j = 0; j <= s; ++j) 
    ans = add(ans, mul((j + 1) / 2, dp[j]));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < a[i]; ++j) 
      ans = add(ans, mul(a[i] - (a[i] + j + 1) / 2, dp[j]));
  cout << ans << '\n';
}

int main(){
    FASTIO;
    cf();
    int t= 1;
    // cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    // while(t--) solve3();
    

    return 0;
}