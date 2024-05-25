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

    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (i == j) continue;
            for (int w = 1; w < 10; w++)
            {
                if (w == i || w == j) continue;
                for (int u = 1; u < 10; u++)
                {
                    if (u == j || u == i || u == w) continue;

                    if (w + u == r2 && i + j == r1 && i + u == d1 && j + w == d2 && i + w == c1 && j + u == c2) {
                        cout << i << " " << j << endl;
                        cout << w << " " << u << endl;
                        return 0;
                    }
                }

            }

        }

    }
    cout << -1;


    return 0;
}