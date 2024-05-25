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

    int n;
    cin >> n;
    string str = "";
    for (int i = 1; i <= n; i++)
    {
        if (i <= 7)
        {
            switch (i % 7)
            {
            case 0:
                str += 'R';
                break;
            case 1:
                str += "O";
                break;
            case 2:
                str += 'Y';
                break;
            case 3:
                str += 'G';
                break;
            case 4:
                str += 'B';
                break;
            case 5:
                str += 'I';
                break;
            case 6:
                str += 'V';
                break;

            default:
                break;
            }
        }
        else
        {
            // p(str);
            str += str[str.length() - 4];
        }
    }
    cout << str;

    return 0;
}