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

    long long n, k, max, l, h, s, mid;
    int cnt = 0;

    cin >> n >> k;
    max = k + (k - 2) * (k - 1) / 2;
    if (max < n)
        cout << -1;
    else if (n < k)
    {
        if (n == 1)
            cout << 0;
        else
            cout << ++cnt;
    }
    else
    {
        n -= k;
        cnt++;
        l = 1;
        h = (k - 2);
        while (n > 0 && l < h)
        {
            mid = (h + l) / 2;
            s = h * (h + 1) / 2 - mid * (mid + 1) / 2;
            if ((n - s) >= 0)
            {
                cnt += h - mid;
                n -= s;
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (n != 0)
            cnt++;
        cout << cnt;
    }
    return 0;
}