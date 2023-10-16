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

const ll OO = 1e6;
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

    int t, cnt, n, m;
    bool f;
    cin >> t;
    string s, x;
    while (t--) {
        cin >> n >> m;
        cin >> x >> s;
        cnt = 0;
        f = 0;
        if (x.find(s) != string::npos) {
            cout << 0 << endl;
            f = 1;
            continue;;
        }
        do {
            x.append(x);
            cnt++;
            if (x.find(s) != string::npos) {
                cout << cnt << endl;
                f = 1;
                break;
            }
            // p(x.find(s));
            // p(x);
        } while (x.length() < s.length());

        if (!f) {
            x.append(x);
            cnt++;
            if (x.find(s) != string::npos) {
                cout << cnt << endl;
                f = 1;
                continue;
            }
            cout << -1 << endl;
        }
    }

    return 0;
}