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

    int t;
    double a;
    vector<string> ans;
    cin >> t;
    while (t--)
    {
        cin >> a;
        bool yes = 0;
        if (a < 60)
        {
            // cout << "NO" << endl;
            ans.push_back("NO");
            continue;
        }
        for (int i = 0; i < 1000; i++)
        {
            if ((a * i) == (180 * (i - 2)))
            {
                yes = 1;
                break;
            }
        }
        if (yes)
            ans.push_back("YES");
        // cout << "YES" << endl;
        else
            // cout << "NO" << endl;
            ans.push_back("NO");
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}