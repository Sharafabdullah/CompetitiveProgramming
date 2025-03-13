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

const int N = 3e5 + 10, M = 10;
int k, n, m;

// Function to reverse the number n in base p
ll rev(ll n, ll p) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % p);
        n /= p;
    }
    // deb(digits)
    ll result = 0;
    for (int digit : digits) {
        result = (result*p) % mod;
        result += digit;
    }
    return result;
}

ll sum(ll l, ll r){
    return (r*(r+1)/2 - (l-1)*l/2);
}

ll sum_squares(ll l, ll r){
    return r*(r+1)*(2*r+1)/6 - (l-1)*l*(2*l-1)/6;
}


 
void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;

    deb(n, k)
    ll sum_before = 0;

    ll sq = sqrt(n);
    for (ll p = 2; p <= sq && p <= k; ++p) {
        ans += rev(n, p);
        ans %= mod;
    }
    
    if(k > sq){
        ll l = sq + 1;
        
        deb(l, ans)
        for (ll r = l; l <= k && l <= n; l = r + 1) {
            r = min(k, n/(n/l));
            ans+= (r - l + 1) * (n/l);
            ans %= mod;
            ans+= (n * sum(l, r))% mod;

            ans = (ans - ((n/l) * sum_squares(l, r))%mod + mod)%mod;
        }
        // deb(l, ans)
        // deb(" ------ ")
        // while(l <= n && l <= k){
        //     ans += rev(n,l);
        //     ans %= mod;
        //     l++;
        // }
    }
    deb(ans)

    
    if(k>n) ans = (ans+ (n * ((k-n) % mod)));
    ans %= mod;
    deb(ans)
    cout << ans << endl;
}


int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    cin >> t;



    while(t--)
        solve();

    return 0;
}
