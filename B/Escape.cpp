#include <bits/stdc++.h>
using namespace std;


#define all(v)				((v).begin()), ((v).end())
#define repv(i, v)		for(int i=0;i<(v).size();++i)
#define rep(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define dow(i, j, n)	for(int i=(j);i>=(int)(n);--i)

#define pb					push_back
#define mp					make_pair
#define p(x)				cout<<#x<<" = { "<<x<<" }\n"



typedef long long ll;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;

const ll OO = 1e9;
const double EPS = (1e-8);


int main() {
    double vp, vd, t, f, c, dp, td;
    int b = 0;
    cin >> vp >> vd >> t >> f >> c;

    if (vp >= vd) { cout << 0; return 0; }
    dp = t * vp;
    while (dp < c) {
        td = dp / (vd - vp);
        dp += td * vp;
        if (dp < c) b++;
        td = dp / vd + f;
        dp += td * vp;
    }
    cout << b;
    return 0;
}