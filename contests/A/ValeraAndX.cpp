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

    int n;
    char tmp;
    int m[309];
    fill(m, m + 309, 0);
    cin >> n;
    bool ok = 0;
    int other, org;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            if (i == j || i == n - j - 1) {
                m[tmp - 'a']++; org = tmp - 'a';
                // p(i);
                // p(j);
            }
            else { m[tmp - 'a']--;other = tmp - 'a'; }
        }

    }
    // p(other);
    for (int i = 0; i < 309; i++)
    {
        // p(m[i] + 'a');
        if (m[i] < 0 && i != other && i != org) {
            ok = 0;
            break;
        }
        if (m[i] == 2 * n - 1) { ok = 1; }
    }
    cout << (ok ? "YES" : "NO");


    return 0;
}