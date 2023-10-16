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

    int t, n, cnt;
    char tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        vvi m(n, vi(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> tmp;
                m[i][j] = tmp - 'a';
            }

        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // if (i == j) {
                //     cnt += abs(m[0][0] - m[j][i]);
                // }
                // else cnt += abs(m[i][j] - m[j][i]);
                // cout << "i: " << i << " j: " << j << "    ";
                // p(cnt);
                // p(m[i][j]);

                if (m[i][j] - m[j][i] > 0) {
                    cnt += m[i][j] - m[j][i];
                    m[j][i] = m[i][j];
                }
                else if (m[i][j] - m[j][i] < 0) {
                    cnt -= m[i][j] - m[j][i];
                    m[i][j] = m[j][i];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1 - i; j >= 0; j--)
            {
                // if (i == j) {
                //     cnt += abs(m[0][0] - m[j][i]);
                // }
                // else cnt += abs(m[i][j] - m[j][i]);
                // cout << "i: " << i << " j: " << j << "    ";
                // p(cnt);
                // p(m[i][j]);

                if (m[i][j] - m[j][i] > 0) {
                    cnt += m[i][j] - m[j][i];
                    m[j][i] = m[i][j];
                }
                else if (m[i][j] - m[j][i] < 0) {
                    cnt -= m[i][j] - m[j][i];
                    m[i][j] = m[j][i];
                }
            }
        }
        if (m[0][0] > m[0][n - 1]) {
            cnt += m[0][0] - m[0][n - 1];
            m[0][n - 1] = m[0][0];
        }
        if (m[0][n - 1] > m[n - 1][n - 1]) {
            cnt += m[0][n - 1] - m[0][n - 1];
            m[n - 1][n - 1] = m[0][n - 1];
        }
        if (m[n - 1][n - 1] > m[n - 1][0]) {
            cnt += m[n - 1][n - 1] - m[n - 1][0];
            m[n - 1][0] = m[n - 1][n - 1];
        }
        if (m[n - 1][0] > m[0][0]) {
            cnt += m[n - 1][0] - m[0][0];
            m[0][0] = m[n - 1][0];
        }


        cout << cnt << endl;



    }

    return 0;
}