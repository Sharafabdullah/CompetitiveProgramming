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

// #include<limits>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi h(n + 1), x(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> x[i] >> h[i];
    }
    vi T(n + 1);
    T[n] = T[0] = std::numeric_limits<int>::max();
    // T[n] = std::numeric_limits<int>::min();
    for (int i = 1; i < n; i++)
    {
        T[i] = x[i + 1] - x[i];
    }
    // for (int i : T) cout << i << "    ";
    cout << endl;
    vector<bool> can(n + 1);
    // can[1] = can[n] = 1;
    for (int i = 1; i <= n; i++)
    {
        // if (T[i] > 0 && T[i - 1] > 0) {
        if (T[i - 1] > h[i]) {
            // p(T[i]);
            // p(h[i]);
            T[i] -= h[i];
            can[i] = 1;
        }
        else if (T[i] > h[i]) {
            T[i + 1] -= h[i];
            can[i] = 1;
        }
        // }

    }
    int sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        // p(i);
        // p(can[i]);
        sum += can[i];
    }
    cout << sum;

    // p(T[0]);

    return 0;
}