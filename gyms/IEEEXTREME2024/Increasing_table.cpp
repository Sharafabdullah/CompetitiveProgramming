#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (auto i = (begin); i < (end); ++i)
#define pb            push_back
#define ppb           pop_back
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x, 0, sizeof(x))
#define endl          '\n'
#define coutfloat(n, d) cout << fixed << setprecision(d) << n << endl
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const ll inf = 1e9 + 1000;
const double eps = 1e-8;
const ll mod = 998244353;
const int N = 2001; 
int k, n, m;

vector<vll> memo(2 * N + 1, vll(N + 1, -1)); 
vi v;

ll dp(int i, int sum) {
    if (sum < 0 || sum > N) return 0;
    if (i == 2 * n + 1) {
        return (sum == 0) ? 1 : 0; // Return 1 if sum is exactly 0 at the end
    }
    if (memo[i][sum] != -1) return memo[i][sum]; 
    
    ll ret = 0;
    if (v[i] == 0) { // If current element is zero
        ret = (dp(i + 1, sum + 1) + dp(i + 1, sum - 1)) % mod;
    } else if (v[i] == 1) { // If current element is one
        ret = dp(i + 1, sum + 1);
    } else if (v[i] == -1) { 
        ret = dp(i + 1, sum - 1);
    }
    
    return memo[i][sum] = (ret % mod); 
}

void solve() {
    cin >> n;
    if (n < 0 || n > 2000) { // Ensure n is within valid range
        cerr << "Error: n must be between 0 and 2000." << endl;
        return;
    }
    
    int x, y, a;
    cin >> x; 
    v.assign(2 * N + 1, 0); 
    rep(i, 0, x) {
        cin >> a;
        if (a >= 0 && a <= 2 * n) v[a] = 1; 
    }
    
    cin >> y; 
    rep(i, 0, y) {
        cin >> a;
        if (a >= 0 && a <= 2 * n) v[a] = -1; // Ensure a is in valid range
    }
    
    cout << dp(1, 0) << endl; 
}

int main() {
    FASTIO;
    int t = 1; 
    
    while (t--) {
        solve();
    }
    return 0;
}
