#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define B begin()
#define E end()
#define clr(x) memset(x, 0, sizeof(x))
#define endl '\n'
#define coutfloat(n, d) cout << fixed << setprecision(d) << n << endl
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

const ll inf = 1e9 + 1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;

ll ans = 0;
int dp[1010][1 << 11] = {};

void getMask(int ind, int stMask, int nxtMask, int lvl) {
    if(ind > n) return;
    if (ind == n) {
        dp[lvl + 1][nxtMask] += dp[lvl][stMask];
        dp[lvl + 1][nxtMask] %= mod;
        if (lvl == m - 1 && nxtMask == 0) {
            ans += dp[lvl][stMask];
            ans %= mod;
        }
        return;
    }
    if(stMask&(1<<ind)){
        getMask(ind+1, stMask, nxtMask, lvl);
    }
    else{
        getMask(ind+1, stMask, nxtMask | (1<<ind), lvl);
        if(ind+1<n && (stMask & (1<<(ind+1)))==0){
            getMask(ind+2, stMask, nxtMask, lvl);
        }
    }
}

void solve() {
    cin >> n >> m;
    dp[0][0] = 1;
    for (int c = 0; c < m; c++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if(dp[c][mask]>0){
                getMask(0,mask, 0, c);
            }
        }
    }
    // cout << dp[m][0] << endl;
    cout<<ans<<endl;
}

int main() {
    FASTIO;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
