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

    int n, m, f, t;
    cin >> n >> m;
    // p(n);
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        // p(i);
        cin >> f >> t;
        // v[f][i + 1] = t;
        // v[t][i + 1] = f;
        v[f].pb(t);
        v[t].pb(f);
        //
    }
    queue<pair<int, int>> q;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (v[j].size() == 1)
            {
                // p(j);
                // p(v[j][0]);
                q.push({j, v[j][0]});
            }
        }
        if (!q.empty())
            cnt++;
        while (!q.empty())
        {
            f = q.front().first;
            t = q.front().second;
            q.pop();
            v[f].clear();
            v[t].erase(find(v[t].begin(), v[t].end(), f));
        }
    }
    cout << cnt;

    return 0;
}