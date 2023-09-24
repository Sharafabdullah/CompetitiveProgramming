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

vector<pair<int, int>> waste;

int sumK(int f, int s)
{
    int cnt = 0;
    for (int i = 0; i < waste.size(); i++)
    {
        if (f > waste[i].first)
            cnt++;
        else if (f == waste[i].first && s > waste[i].second)
            cnt++;
        else
            break;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, t, f, s;
    cin >> n >> m >> k >> t;
    for (int i = 0; i < k; i++)
    {
        cin >> f >> s;
        waste.push_back({f, s});
    }
    sort(all(waste));
    // for (auto i : waste)
    // {
    //     cout << i.first << "    " << i.second << endl;
    // }
    for (int i = 0; i < t; i++)
    {
        cin >> f >> s;
        if (count(waste.begin(), waste.end(), std::make_pair(f, s)))
        {
            cout << "Waste" << endl;
            continue;
        }
        int res = (m * (f - 1) + s - sumK(f, s)) % 3;
        // p(sumK(f, s));
        // p(res);
        cout << (res == 1 ? "Carrots" : res == 2 ? "Kiwis"
                                                 : "Grapes")
             << endl;
    }

    return 0;
}