#include <bits/stdc++.h>
#include <algorithm>
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

#include <cstring>
#include <algorithm>
const int Max = 101;
int color[Max];

int addm[Max][Max] = {0};
int cnt = 0;
void dfs(int node, int n)
{
    // for (int i = 0; i < sizeof(color) / sizeof(color[0]); i++)
    // {
    //     cout << color[i] << "  ";
    // }

    if (color[node] == -1)
    {
        // cout << "new connenction - color is zero" << endl;
        color[node] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        // cout << color[i] << endl;

        if (addm[node][i] == 1)
        {
            // cout << "There is a connection from " << node << " to " << i << endl;
            // cout << "inside: " << color[i] << endl;

            if (color[i] == -1)
            {
                color[i] = 1 - color[node];
                // cout << "before recursion:" << endl;
                dfs(i, n);
            }
            else if (color[i] == color[node])
            {
                cnt++;
                addm[i][node] = addm[node][i] = 0;
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // fill(color, color + Max, -1);
    memset(color, -1, sizeof(color));
    // for (int i = 0; i < Max; i++)
    // {
    //     cout << color[i] << "   ";
    // }

    // lp(i, Max) color[i] = -1;
    int n, e, from, to;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> from >> to;
        addm[from - 1][to - 1] = addm[to - 1][from - 1] = 1;
    }

    // lp(i, n)
    // {
    //     lp(j, n)
    //     {
    //         cout << addm[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            dfs(i, n);
        }
    }
    if ((n - cnt) % 2 == 1)
        cnt++;
    cout << cnt;

    return 0;
}