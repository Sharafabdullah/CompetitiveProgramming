#include <bits/stdc++.h>
using namespace std;

#include <sstream>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define lpi(i, j, n) for (int i = (j); i < (int)(n); ++i)
#define lpd(i, j, n) for (int i = (j); i >= (int)(n); --i)

typedef long long ll;
typedef pair<int, int> pi;

const ll OO = 1e8;
const double EPS = (1e-9);

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1
                                                                     : 1; }

#define pb push_back
#define mp make_pair
#define p(x) cout << #x << " = { " << x << " }\n"

typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;

int n, l;
vector<double> v;

bool can(long double mid)
{
    // if (fabs(mid - v[0]) < EPS || fabs(mid - l + v[n - 1]) < EPS)
    //     return false;
    if (mid < v[0] || mid < l - v.back())
        return false;
    for (int i = 1; i < n; i++)
    {
        if (mid < (v[i] - v[i - 1]) / 2.0)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    v = vector<double>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
    // for (double i : v)
    //     cout << i << " ";
    // cout << endl;
    long double l = 0, h = 1e9 + 7;
    long double mid;
    while (fabs(h - l) > EPS)
    {
        mid = (l + h) / 2;
        // p(mid);
        if (can(mid))
            h = mid;
        else
            l = mid;
    }
    cout << setprecision(9) << fixed << l;
    // cout << setprecision(9) << fixed << h;

    return 0;
}