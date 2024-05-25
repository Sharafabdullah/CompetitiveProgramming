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

    int t, n, k, x, sum = 0;

    vi v;
    cin >> t;
    vi ans;
    while (t--)
    {
        cin >> n >> k >> x;
        v = vector<int>(n);
        if (k > x + 1 || k > n)
        {
            ans.pb(-1);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (i < k)
                {
                    v[i] = i;
                }
                else
                {
                    if (k == x)
                    {
                        v[i] = x - 1;
                    }
                    else
                        v[i] = x;
                }
            }
            sum = 0;
            for (int i : v)
                sum += i;
            ans.pb(sum);
        }
    }
    for (int i : ans)
        cout << i << endl;
    return 0;
}