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

    int n, m, tmp;
    ll ves = 0, pet = 0;

    cin >> n;
    unordered_map<int, pair<int, int>> mp;
    // mp[1] = std::make_pair(10, 20);
    // p(mp[3].first);

    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        mp[tmp] = std::make_pair(i, n - i + 1);
        // mp[1] = std::make_pair(10, 20);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        ves += mp[tmp].first;
        pet += mp[tmp].second;
    }
    cout << ves << " " << pet;

    return 0;
}