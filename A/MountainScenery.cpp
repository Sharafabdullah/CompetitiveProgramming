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

    int n, k, tmp;
    cin >> n >> k;
    vector<int> v(2 * n + 1);
    // for (int i = 1; i <= 2 * n + 1; i++)
    // {
    //     cin >> tmp;
    //     if (i % 2 || !k || tmp==1)
    //     {
    //         cout << tmp << " ";
    //     }
    //     else
    //     {
    //         // v[i] = tmp - 1;
    //         cout << (tmp - 1) << " ";
    //         k--;
    //     }
    // }

    for (int i = 0; i < 2 * n + 1; i++)
    {
        cin >> v[i];
    }
    int i = 1;
    while (k)
    {
        if ((v[i] > v[i - 1] + 1) && (v[i] > v[i + 1] + 1))
        {
            v[i]--;
            k--;
        }
        i += 2;
    }
    for (int i : v)
        cout << i << " ";
    return 0;
}