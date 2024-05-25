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

    int n, f; cin >> n >> f;
    vector<pair<ll, ll>> k(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i].first >> k[i].second;
    }

    sort(all(k), [](pi p1, pi p2) {
        return min(2 * p1.first, p1.second) - min(p1.first, p1.second) > min(2 * p2.first, p2.second) - min(p2.first, p2.second);
        });
    // for (auto p : k) cout << p.first << " " << p.second << endl;
    // cout << endl;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (f > 0) {
            f--;
            sum += min(2 * k[i].first, k[i].second);
        }
        else {
            sum += min(k[i].first, k[i].second);
        }
    }
    cout << sum;


    return 0;
}