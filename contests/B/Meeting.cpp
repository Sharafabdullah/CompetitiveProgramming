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
const ll inf = 1e9;
const double eps = (1e-8);




int main() {

    int x1, x2, y1, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    set<pair<int, int>> s, ns;
    for (int i = min(x1, x2); i <= max(x1, x2); i++)
    {
        s.insert({ i,y1 });
        s.insert({ i, y2 });
    }
    for (int i = min(y1, y2); i < max(y1, y2); i++)
    {
        s.insert({ x1,i });
        s.insert({ x2,i });
    }
    // for (auto p : s) {
    //     cout << p.first << "    " << p.second << endl;
    // }
    double i, j, r;

    while (n--) {
        cin >> i >> j >> r;
        for (auto p : s) {
            if (pow(p.first - i, 2) + pow(p.second - j, 2) <= r * r) {
                ns.insert(p);
            }
        }
    }
    cout << s.size() - ns.size();



    return 0;
}