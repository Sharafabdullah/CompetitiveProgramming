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

    int n, m;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<ll> csum(n + 1, 0);
    vector<ll> ordcsum(n + 1, 0);
    // transform(v.begin(), v.end(), csum.begin(), [](int i)
    //           { return i + 1; });
    // for (int i : csum)
    //     cout << i << "  ";
    for (int i = 1; i <= n; i++)
    {
        csum[i] = csum[i - 1] + v[i];
    }
    sort(all(v));
    for (int i = 1; i <= n; i++)
    {
        ordcsum[i] = ordcsum[i - 1] + v[i];
    }

    int type, l, r;
    cin >> m;
    // int *ans = new int(m);
    vector<ll> ans;
    while (m--)
    {
        cin >> type >> l >> r;
        if (type == 1)
        {
            ans.pb(csum[r] - csum[l - 1]);
        }
        else
            ans.pb(ordcsum[r] - ordcsum[l - 1]);
    }
    // for (int i = m - 1; i >= 0; i--)
    // {
    //     cout << ans[i] << endl;
    // }
    // for (int i = 0; i < m; i++)
    // {
    //     cout << ans[i] << "    ";
    // }
    for (ll i : ans)
        cout << i << endl;

    return 0;
}