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


set<int> app;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m, rem;
    ll sum = 0;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        sum = 0;
        rem = n % m;
        if (rem == 0) {
            cout << 0 << endl;
        }
        else {
            bool ok = 1;
            while (rem != 0) {
                sum += rem;
                // p(rem);
                rem = (rem * 2) % m;
                if (app.count(rem) >= 1) {
                    cout << -1 << endl;
                    ok = 0;
                    break;
                }
                app.insert(rem);
            }
            if (ok) cout << sum << endl;
        }
        app.clear();
    }

    return 0;
}