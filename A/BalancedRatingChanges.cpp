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

    // int n, tmp, sum = 0;
    // cin >> n;
    // vi a(n);
    // vi b(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> tmp;
    //     a[i] = tmp;
    //     b[i] = floor(tmp / 2);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     sum += b[i];
    // }
    // int i = 0;
    // while (sum < 0)
    // {
    //     if (a[i] % 2 && b[i] == floor(a[i] / 2))
    //     {
    //         b[i]++;
    //         sum++;
    //     };
    //     i++;
    // }
    // i = 0;
    // while (sum > 0)
    // {
    //     if (a[i] % 2 && b[i] == ceil(a[i] / 2))
    //     {
    //         b[i]--;
    //         sum--;
    //     }
    //     i++;
    // }
    // for (int i : b)
    //     cout << i << endl;
    // return 0;
    int n;
    cin >> n;
    bool x = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a % 2)
        {
            if (x)
            {
                a = (a + 1) / 2;
            }
            else
            {
                a = (a - 1) / 2;
            }
            x ^= 1;
        }
        else
        {
            a /= 2;
        }
        cout << a << '\n';
        sum += a;
    }
}