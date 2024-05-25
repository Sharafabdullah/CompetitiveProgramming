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

    int n; cin >> n;
    vi v(n);
    for (int& i : v) cin >> i;
    sort(all(v));
    for (int i = 2; i < v.size(); i++) {
        if (v[i] < v[i - 1] + v[i - 2]) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;

    return 0;
}