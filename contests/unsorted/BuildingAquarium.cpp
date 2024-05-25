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

int n, x;
vi v, sum;
bool can(int k, int ind)
{
    for (int i = 0; i <= ind; i++)
    {
        if (k * (i + 1) - sum[i] > x)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        v = vi(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(all(v));
        // for (int i : v)
        //     cout << i << "    ";
        // int k=1;
        // for(; k<n)
        sum = vi(n);
        sum[0] = v[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = v[i] + sum[i - 1];
        }
        int h = 1e9 + 7, l = 1, m, ind;
        while (h >= l)
        {
            m = l + (h - l + 1) / 2;
            for (int i = 0; i < n; i++)
            {
                if (v[i] > m)
                {
                    ind = i;
                    break;
                }
            }
            // p(m);
            // p(h);
            // p(l);
            // p(ind);
            if (can(h, ind))
                l = m;
            else
                h = m - 1;
        }
        cout << h << endl;
    }

    return 0;
}