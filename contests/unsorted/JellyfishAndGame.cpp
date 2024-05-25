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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, n, m, k;
    cin >> t;
    while (t--) {
        ll sum = 0;
        cin >> n >> m >> k;
        vector<ll> J(n);
        vector<ll> G(m);
        for (ll& i : J) cin >> i;
        for (ll& i : G) cin >> i;

        auto j = minmax_element(all(J));
        auto g = minmax_element(all(G));
        // cout<<*j.first<<"    "<<*j.second<<endl;
        if (k % 2) {
            // if(*j.first < *g.second){
            //     *j.first = *g.second;
            // }
            *j.first = max(*j.first, *g.second);

        }
        else {
            *j.second = min(*j.second, *g.first);
        }
        for (int i : J) {
            sum += i;
        }
        cout << sum << endl;
    }

    return 0;
}