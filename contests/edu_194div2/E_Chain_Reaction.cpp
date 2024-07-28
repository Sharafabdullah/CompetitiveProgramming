#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); ++i)
#define pb push_back
#define F first
#define S second
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
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

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

const ll inf = 1e9 + 1000;
const double eps = 1e-8;
const ll mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vll a(n); 
    rep(i, 0, n) cin >> a[i];
    deb(a)

    vll ks(*max_element(all(a)) + 1);
    auto calc = [&](int k) {
        ll ret = 0, cur = 0;
        rep(i, 0, n) {
            ll num = (a[i] + k - 1) / k;
            if (num > cur) {
                ret += (num - cur);
                cur = num;
            } else {
                cur = num;
            }
        }
        deb(k) deb(ret)
        ks[k] = ret;
        return ret;
    };

    
    for (int k = 1; k < ks.size(); ++k) {
        ll cur = calc(k);
        ks[k] = cur;
        // deb(k)
        // deb(cur)
        
        ll lo = k+1, hi = ks.size() - 1;
        auto cmp = [&](ll md) {
            ll ret = calc(md);
            return ret < cur;
        };

        // finds the first true given by cmp (lo). hi is the last false
        while (lo <= hi) {
            ll md = lo + (hi - lo) / 2;
            if (cmp(md)) hi = md - 1;
            else lo = md + 1;
        }
        deb(hi) deb(cur)
        while (k < hi) {
            k++;
            if (k < ks.size()) ks[k] = cur;
        }
        // deb(k)
    }

    rep(i, 1, ks.size()) {
        cout << ks[i] << " ";
    }
    cout << endl;
}

int main() {
    FASTIO;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
