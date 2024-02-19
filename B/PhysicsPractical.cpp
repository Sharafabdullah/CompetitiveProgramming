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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vi a(n);
    for (int& i : a) cin >> i;
    sort(all(a));
    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        int x = upper_bound(all(a), 2 * a[i]) - a.begin();
        ans = min(ans, i + n - x);
    }
    cout << ans;

    return 0;
}