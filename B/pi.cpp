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
int mgcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return mgcd(y, x % y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n)
    {
        vi a(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (mgcd(max(a[i], a[j]), min(a[i], a[j])) == 1)
                {
                    cnt++;
                }
            }
        }
        // for (int i : a)
        //     cout << i << "    ";
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << a[i] << "   ";
        // }

        if (!cnt)
        {
            cout << "No estimate for this data set" << endl;
        }
        else
        {
            double prob = n * (n - 1) / 2.0;
            cout << setprecision(7) << sqrt(6.0 * prob / cnt) << endl;
        }
        cin >> n;
    }

    return 0;
}