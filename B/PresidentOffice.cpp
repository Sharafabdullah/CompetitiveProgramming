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

int n, m, ith, jth, cnt = -1;
char p;
vector<vector<char>> v;
vector<vector<bool>> vis;
set<char> s;
void dfs(int i, int j)
{
    if (i >= n || j >= m || i < 0 || j < 0 || v[i][j] == '.' || vis[i][j] == 1)
        return;

    // p(i);
    // p(j);
    // cout << "inside dfs" << endl;

    vis[i][j] = 1;
    if (s.count(v[i][j]) == 0)
    {
        cnt++;
        // p(cnt);
        s.insert(v[i][j]);
        if (s.size() > 1)
            return;
    }
    if (v[i][j] != p)
        return;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char tmp;
    cin >>
        n >> m >> p;
    v = vector<vector<char>>(n);
    vis = vector<vector<bool>>(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> tmp;
            // p(tmp);
            v[i].push_back(tmp);
            if (v[i][j] == p)
            {
                ith = i;
                jth = j;
            }
        }
    }
    // p(ith);
    // p(jth);
    dfs(ith, jth);

    cout << cnt;

    return 0;
}