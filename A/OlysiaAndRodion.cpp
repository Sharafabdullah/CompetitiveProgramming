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

class Bint
{
public:
    vi dig;
    Bint()
    {
        dig = vi(1, 1);
    }
    Bint &operator*(int x)
    {
        for (int j = 0; j < dig.size(); j++)
        {
            dig[j] *= x;
        }
        for (int i = 0; i < dig.size(); i++)
        {

            if (i == dig.size() - 1 && dig[i] > 9)
            {
                dig.push_back(dig[i] / 10);
                dig[i] = dig[i] % 10;
            }
            if (dig[i] > 9)
            {
                dig[i + 1] = (dig[i + 1] + (dig[i] / 10));
                dig[i] = dig[i] % 10;
            }
        }
        return *this;
    }
    int Size() { return dig.size(); }
    void print()
    {
        for (int i = dig.size() - 1; i >= 0; i--)
        {
            cout << dig[i];
        }

        cout << endl;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    if (n == 1)
    {
        if (t == 10)
            cout << -1;
        else
            cout << t;
        return 0;
    }
    Bint bint;
    while (bint.dig.size() < n)
    {
        // cout << "inside while";
        bint = bint * t;
    }
    bint.print();

    return 0;
}