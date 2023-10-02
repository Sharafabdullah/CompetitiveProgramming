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

    int n, t1, t2, tmp;
    double k;
    cin >> n >> t1 >> t2 >> k;
    k /= 100;
    vector<pair<int, double>> ans(n);

    vector<pair<int, int>> part(n);
    for (pair<int, int>& p : part) cin >> p.first >> p.second;
    double op1, op2;
    for (int i = 0; i < n; i++)
    {
        op1 = t1 * part[i].first * (1 - k) + t2 * part[i].second;
        op2 = t1 * part[i].second * (1 - k) + t2 * part[i].first;
        // p(op1);
        // p(op2);
        if (op1 > op2) {
            ans[i] = { i + 1,op1 };
        }
        else {
            ans[i] = { i + 1, op2 };
        }
    }
    // sort(all(ans), [](pair<int, double> p, pair<int, double> p2) {
    //     return p.second > p2.second;
    //     });
    sort(all(ans), [](pair<int, double> p, pair<int, double> p2) {
        if (p.second == p2.second) {
            return p.first < p2.first;
        }
        return p.second > p2.second;
        });
    for (pair<int, double>& p : ans) {
        cout << p.first << " ";
        cout << fixed << setprecision(2) << (double)p.second << endl;
    }

    return 0;
}