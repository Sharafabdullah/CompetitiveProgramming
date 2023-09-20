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

vvi g;
vi boss;

void findBoss(int node, int parent, int k)
{
    if (boss[node] != 0)
        return;
    boss[node] = parent;
    cout << "current node: " << node << endl;
    if (node > k)
        return;
    for (int i = 1; i < g[node].size(); i++)
    {
        int child = g[node][i];
        cout << "inside lopp " << child << "    " << endl;
        if (boss[child] == 0)
            findBoss(child, node, k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, w, s;
    cin >> n >> k;
    g = vvi(k + 1);
    boss = vi(n + 1, 0);
    for (int i = 1; i <= k; i++)
    {
        cin >> w;
        for (int j = 0; j < w; j++)
        {
            cin >> s;
            s;
            g[i].pb(s);
        }
    }

    // for (vi v : g)
    //     {for (int i : v)
    //         cout << i << "   ";

    //     cout<<endl;}
    // // cout << endl;
    for (int i = 0; i < k; i++)
    {

        if (boss[i] == 0)
        {
            cout << "Entering boss" << endl;
            findBoss(i, 0, k);
        }
    }

    for (int i : boss)
        // if()
        cout << i << endl;

    return 0;
}