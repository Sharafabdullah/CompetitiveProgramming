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

    int t, n, k, q, x;
    string str;
    cin >> t;
    while (t--) {
        cin >> n >> k >> str;
        vi l, r;
        for (int i = 0; i < k; i++)
        {
            cin >> x;
            l.pb(x);
            // p(l[i]);
        }
        for (int i = 0; i < k; i++)
        {
            cin >> x;
            r.pb(x);
        }
        cin >> q;
        // p(q);
        for (int i = 0; i < q; i++)
        {
            cin >> x;
            auto lowB = upper_bound(all(l), x);
            auto upB = lowB - l.begin();
            p(*(lowB - 1));
            upB = *(r.begin() + upB);
            p(upB);
            int a = min((ll)x, *lowB + upB - x);
            int b = max((ll)x, *lowB + upB - x);
            p(a);
            p(b);
            if (b >= n) cerr << b << endl;
            reverse(str.begin() + a - 1, str.begin() + b);
            // cout << "after reversing: " << str << endl;
        }
        cout << str << endl;
        str = "";
    }

    return 0;
}