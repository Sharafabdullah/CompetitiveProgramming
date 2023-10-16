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


// #include<bitmask>
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    ll mask = 1;
    ll l, r;
    cin >> l >> r;
    if (l == r) {
        cout << 0;
    }
    else {
        // int cnt = 0;
        // // cout << __builtin_clzll(r) << endl;
        // int br = __builtin_clzll(r);
        // int bl = __builtin_clzll(l);
        // if (br == bl) {
        //     cnt++;
        //     int i = 0;
        //     while (l & ((ll)1 << (63 - i - bl)) == r & ((ll)1 << (63 - i - br))) {
        //         cnt++;
        //         i++;
        //     }
        // }
        // for (ll i = 0; i <= (63 - __builtin_clzll(r) - cnt); i++)
        // {
        //     // p(i);
        //     // mask = ((ll)mask << 1) | (ll)1;
        //     mask |= (ll)1 << i;
        // }
        // // mask = bitmask<int>().set();
        // cout << mask << endl;
        // cout << bitset<64>(mask) << endl;
        // cout << bitset<64>(r) << endl;
        // cout << bitset<64>(l) << endl;
        // cout << bitset<64>(288230376151711743L) << endl;
        ll x = l ^ r;
        ll msb = 63 - __builtin_clzll(x);
        // p(msb);
        cout << 2 * (1LL << msb) - 1 << endl;
    }

    return 0;
}