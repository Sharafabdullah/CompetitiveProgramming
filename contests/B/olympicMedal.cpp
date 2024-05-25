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

    int n, m, k;
    double r = 0;
    cin >> n;
    vi r2(n);
    for (int& i : r2) cin >> i;
    sort(all(r2));
    double r22 = r2[n - 1];
    cin >> m;
    vi p2(m);
    for (int& i : p2) cin >> i;
    sort(all(p2));
    double p22 = p2[m - 1];
    cin >> k;
    vi p1(k);
    for (int& i : p1) cin >> i;
    sort(all(p1));
    double p11 = p1[0];
    int a, b;
    cin >> a >> b;

    double tmp = sqrt(b * p22 * pow(r22, 2) * 1.0 / (a * p11 + b * p22));

    // for (int i = 0; i < r2.size(); i++)
    // {
    //     for (int j = 0; j < p2.size(); j++)
    //     {
    //         for (int l = 0; l < p1.size(); l++)
    //         {
    //             double tmp = sqrt(b * p2[j] * pow(r2[i], 2) * 1.0 / (a * p1[l] + b * p2[j]));
    //             // p(r2[i]);
    //             // p(p2[j]);
    //             // p(p1[l]);
    //             // p(tmp);
    //             r = max(r, tmp);
    //         }

    //     }
    // }
    cout << fixed << setprecision(7) << tmp << endl;



    return 0;
}