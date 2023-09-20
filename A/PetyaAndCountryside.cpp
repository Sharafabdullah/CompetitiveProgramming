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

    int max = 0, nmax = 0, n;
    cin >> n;
    vi h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++)
    {
        nmax = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (h[j] <= h[j - 1])
            {
                nmax++;
                // p(h[j]);
                // p(h[i]);
            }
            else
                break;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (h[j] <= h[j + 1])
                nmax++;
            else
                break;
        }
        // cout << "before: " << max << endl;
        if (nmax > max)
            max = nmax;
        // p(max);
    }
    cout << max;

    return 0;
}