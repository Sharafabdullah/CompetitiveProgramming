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

class bigInt
{

public:
    vector<int> v;
    int cur = 0;
    bigInt()
    {
        v = vector<int>(50, 0);
    }
    bigInt(int size, int init)
    {
        v = vector<int>(size + 1, init);
    }
    bigInt &operator+(bigInt &sec)
    {
        int size = max(sec.cur, cur) + 1;
        bigInt *c = new bigInt();
        for (int i = 0; i < size; i++)
        {
            int sum = v[i] + sec.v[i];
            p(sum);
            c->insertnum(sum);
        }
        for (int i = 0; i < size; i++)
        {
            c->v[i + 1] += c->v[i] / 10;
            c->v[i] = v[i] % 10;
        }
        for (int i = 0; i <= c->cur; i++)
        {
            cout << "---------";
            p(c->v[i]);
        }

        return *c;
    }
    // bigInt &operator=(bigInt &sec)
    // {
    //     v = sec.v;
    //     cur = sec.cur;
    //     return *this;
    // }
    void insert(char n)
    {
        v[cur] = n - '0';
        cur++;
    }
    void insertnum(int n)
    {
        v[cur + 1] = n;
        cur++;
    }
    int size()
    {
        return v.size();
    }
    int at(int i)
    {
        // if (i >= v.size())
        //     return 0;
        return v[i];
    }
    void printRev()
    {
        int t = 1;
        // for (int i = v.size() - 1; i >= 0; i--)
        // {
        //     if (v[i] != 0)
        //     {
        //         t = i;
        //         break;
        //     }
        // }
        // for (int i = 0; i <= t; i++)
        // {
        //     cout << v[i];
        // }
        for (int i : v)
        {
            cout << i << "  ";
        }
        cout << endl;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, tmp;
    string str1, str2;
    cin >> n;
    while (n--)
    {
        // getline(cin, str);
        cin >> str1 >> str2;
        // p(str);
        bool f = 0;
        bigInt a;
        bigInt b;
        for (int i = 0; i < str1.length(); i++)
        {
            // if (str[i] == ' ')
            // {
            //     f = 1;
            //     continue;
            // }
            a.insert(str1[i]);
            // p(str[i]);
            // a.printRev();
        }
        for (int i = 0; i < str2.length(); i++)
        {
            b.insert(str2[i]);
        }

        bigInt c;
        c = (a + b);
        a.printRev();
        b.printRev();
        c.printRev();
    }

    return 0;
}