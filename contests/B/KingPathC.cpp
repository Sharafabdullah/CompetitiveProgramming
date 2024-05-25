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

    int x1, y1, x2, y2, n, r, a, b;
    cin >> x1 >> y1 >> x2 >> y2 >> n;

    set<pair<int, int>> pts;
    while (n--)
    {
        cin >> r >> a >> b;
        for (int i = a; i <= b; i++)
        {
            pts.insert({r, i});
        }
    }
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    map<pair<int, int>, int> depth;
    pair<int, int> s = {x1, y1};
    queue<pair<int, int>> q;

    q.push(s);
    depth[s] = 0;

    pair<int, int> cur;
    int dep = 0, nx, ny;
    for (int sz = 1; !q.empty(); dep++, sz = q.size())
    {
        while (sz--)
        {
            cur = q.front(), q.pop();

            for (int d = 0; d < 8; d++)
            {
                nx = cur.first + dx[d];
                ny = cur.second + dy[d];
                pair<int, int> newp = {nx, ny};

                if (pts.count(newp) == 0 || depth.count(newp) != 0)
                    continue;

                q.push(newp);
                depth[newp] = dep + 1;

                if (newp.first == x2 && newp.second == y2)
                {
                    cout << dep + 1;
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}