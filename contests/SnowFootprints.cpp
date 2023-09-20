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

    int n, s, t;
    string str;
    cin >> n >> str;
    // cout<<str[2];
    // int pos = str.find_first_not_of('.');
    // int posEnd = str.find_last_not_of('.');
    // p(pos);
    // p(posEnd);
    // p(str[pos]);
    // p(str[posEnd]);
    for (int i = 1; i <= n; i++)
    {
        if (str[i - 1] == 'L')
        {
            s = i;
            t = i - 1;
            break;
        }
        if (str[i - 1] == 'R')
        {
            s = i;
            t = i + 1;
            while (str[t - 1] == 'R')
            {
                t++;
            }
            if (str[t - 1] == 'L')
                t--;
            break;
        }
    }

    cout << s << " " << t;
    return 0;
}