#include <bits/stdc++.h>
// #include<something>
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

    // int l = 0, r = 0, n, tmp;
    // bool cant = 0;
    // cin >> n;
    // vi a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // int maxD = -10000000, minI = 1e9 + 7;

    // for (int i = 0; i < n - 1; i++)
    // {
    //     while (a[i] < a[i + 1])
    //     {
    //         l++;
    //         r++;
    //         i++;
    //     }
    //     p(r);
    //     if (a[i] > a[i + 1])
    //     {
    //         r++;
    //         maxD = a[i];
    //     }
    //     else
    //         break;
    // }
    // for (int i = r + 1; i < n - 1; i++)
    // {
    //     minI = a[i];
    //     if (a[i] > a[i + 1])
    //         cant = 1;
    // }
    // p(l);
    // p(r);
    // if (cant || maxD > minI)
    // {
    //     p(cant);
    //     p(maxD);
    //     p(minI);
    //     cout << "no";
    // }
    // else
    // {
    //     cout << "yes" << endl;
    //     cout << l + 1 << " " << r + 1;
    // }

    int i = 0, n, l = 0, r = 0;
    cin >> n;
    vi a(n);
    vi s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(all(s));
    for (int i = 0; i < n; i++)
    {
        if (a[i] != s[i] && !l)
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= l; i--)
    {
        if (a[i] != s[i])
        {
            r = i;
            break;
        }
    }

    // p(r);
    // p(l);

    // while (i < n - 1 && a[i] < a[i + 1])
    // {
    //     l++;
    //     i++;
    //     r++;
    // }
    // while (i < n - 1 && a[i] > a[i + 1])
    // {
    //     r++;
    //     i++;
    // }
    reverse(a.begin() + l, a.begin() + r + 1);
    // for (int i : a)
    //     p(i);
    bool sorted = is_sorted(a.begin(), a.end());
    if (sorted)
    {
        cout << "yes" << endl;
        cout << l + 1 << " " << r + 1;
    }
    else
    {
        cout << "no";
    }

    return 0;
}