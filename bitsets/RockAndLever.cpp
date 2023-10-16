#include <bits/stdc++.h>
using namespace std;

#include<sstream>


#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)


typedef long long ll;
typedef pair<int, int> pi;

const ll OO = 1e8;
const double EPS = (1e-7);

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


#define pb					push_back
#define mp					make_pair
#define p(x)				cout<<#x<<" = { "<<x<<" }\n"

typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(50);
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int MSB = 31 - __builtin_clz(a[i]);
        v[MSB]++;
    }
    ll ans = 0;
    for (int i = 0; i < 50; i++)
    {
        ans += v[i] * (v[i] - 1) / 2;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        // ll ans = 0;
        // cin >> n;
        // vector<ll> v(n);
        // for (ll& i : v) cin >> i;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         // p((v[i] & v[j]));
        //         // p((v[i] ^ v[j]));
        //         if ((v[i] & v[j]) >= (v[i] ^ v[j])) ans++;
        //     }

        // }
        // cout << ans << endl;
        solve();

    }

    return 0;
}