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
const double EPS = (1e-7);

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n, k, sum = 0, f, s;
    cin >> n >> k;
    vector<pair<double, double>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> f >> s;
        v[i].first = f;
        v[i].second = s;
    }

    for (int i = 0; i < n - 1; i++)
    {
        sum += sqrt(pow((v[i + 1].first - v[i].first), 2) + pow((v[i + 1].second - v[i].second), 2));
    }
    sum = (sum * k) / 50;
    cout << setprecision(9) << sum;

    return 0;
}