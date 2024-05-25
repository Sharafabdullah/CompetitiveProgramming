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

const int Max = 102;
int seq[Max];
int ans[Max][4];
int n;

int dp(int d, int m) {
    int& ret = ans[d][m];

    if (d != 0)
    {
        if (seq[d] == 0 && m != 0) return OO;
        if (seq[d] == 1 && m == 2) return OO;
        if (seq[d] == 2 && m == 1) return OO;
        if (ret != OO) return ret;
    }
    if (d == n) return m == 0 ? 1 : 0;

    if (m == 0) ret++;
    // else ret = ans[d][m];
    // p(ret);
    // p(d);
    // p(m);



    // if (m == -1) {
    //     ret = min(ret, dp(d + 1, 0));
    //     ret = min(ret, dp(d + 1, 1));
    //     ret = min(ret, dp(d + 1, 2));
    // }
    // if (m == 1) {
    //     ret = min(ret, dp(d + 1, 0));
    //     ret = min(ret, dp(d + 1, 2));
    // }
    // else if (m == 2) {
    //     ret = min(ret, dp(d + 1, 0));
    //     ret = min(ret, dp(d + 1, 1));
    // }
    // else if (m == 0) {
    //     ret = min(ret, dp(d + 1, 2));
    //     ret = min(ret, dp(d + 1, 1));
    // }
    cout << "before " << d << endl << endl;
    cout << "before rest: " << ret << endl;
    ret = min(ret, dp(d + 1, 0));
    cout << "before contest: " << ret << endl;
    if (m != 1) ret = min(ret, dp(d + 1, 1));
    cout << "before gym: " << ret << endl << endl;
    if (m != 2) ret = min(ret, dp(d + 1, 2));


    return (m == 0 ? ret + 1 : ret);
    // return ret;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    // fill(seq, seq+Max, OO);
    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ans[i][j] = OO;
        }

    }
    ans[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }
    cout << dp(0, 0);

    return 0;
}