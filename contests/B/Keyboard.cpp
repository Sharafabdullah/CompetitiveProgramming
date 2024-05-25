#include <bits/stdc++.h>
using namespace std;

#include<sstream>


#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)


typedef long long ll;
typedef pair<int, int> pi;

const ll OO = 1e8;
const double EPS = (1e-7);

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


#define pb					push_back
#define mp					make_pair
#define p(x)				cout<<#x<<" = { "<<x<<" }\n"

typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0, q, n, m, x, ith, jth; char ch;
    cin >> n >> m >> x;
    vector<vector<char>> k(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            // p(ch);
            k[i][j] = ch;
        }

    }
    cin >> q;
    bool ok;

    while (q--) {
        ok = 0;
        cin >> ch;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (k[i][j] == tolower(ch)) {
                    ok = 1;
                    ith = i;
                    jth = j;
                }
            }

        }
        if (!ok) {
            cout << -1;
            return 0;
        }
        if (ch >= 'A' && ch <= 'Z') {
            bool can = 0;
            ok = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (k[i][j] == 'S')
                    {
                        can = 1;
                        double d = sqrt(pow(ith - i, 2) + pow(jth - j, 2));
                        if ((double)x >= d) {
                            // p(ith);
                            // p(jth);
                            // p(d);
                            ok = 1;
                        }
                    }
                }
            }
            if (!can) {
                cout << -1;
                return 0;
            }
            if (!ok) { cnt++; }
        }
    }
    cout << cnt;

    return 0;
}