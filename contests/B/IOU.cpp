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

    int n, m;
    cin >> n >> m;
    vi dep(n + 1), ow(n + 1);
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        ow[a] += c;
        ow[b] -= c;
    }
    int sum = 0;
    // for (int i : ow) cout << i << "   ";
    // cout << endl;
    for (int i = 0; i <= n; i++)
    {
        if (ow[i] > 0) sum += ow[i];
    }
    cout << sum;

    return 0;
}