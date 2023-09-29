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

    ll n, m, nrem, mrem;
    cin >> n >> m;
    nrem = n % 5;
    mrem = m % 5;
    ll cnt = 0;
    for (int i = 1; i <= n % 5; i++)
    {
        for (int j = 1; j <= m % 5; j++)
        {
            if (j + i == 5)
                cnt++;
        }
    }
    // p(cnt);
    // p(((n / 5) * (m / 5)) * 5);
    cout << ((n / 5) * (m / 5)) * 5 + mrem * (n / 5) + nrem * (m / 5) + cnt << endl;

    return 0;
}
