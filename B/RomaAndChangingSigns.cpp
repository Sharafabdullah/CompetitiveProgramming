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

    int n, k, ind = 0, sum = 0;
    cin >> n >> k;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // if (!ind && a[i] >= 0) ind = i;
    }
    /*
        if (ind < k) {
            for (int i = 1; i < n + 1; i++)
            {
                if (k > 0 && a[i] < 0) k--;
                sum += abs(a[i]);

            }
        }
        else {
            // for (int i : a) cout << i << "   ";
            // cout << "-----" << endl;
            for (int i = 1; i < n + 1; i++)
            {
                // p(sum);
                // p(k);
                if (k > 0) {
                    // p(k);
                    // p(a[i]);
                    sum += abs(a[i]);
                    k--;
                }
                else {
                    sum += a[i];
                }
            }

        }
        // p(a[ind]);
        // p(k - n);
        // p(sum);
        if (k % 2) sum -= 2 * a[ind];

        cout << sum; */

    for (int i = 1; i <= n && k && a[i] < 0; i++) {
        a[i] *= -1;
        k--;
    }
    sort(a.begin() + 1, a.end());
    if (k & 1) a[1] *= -1;
    for (int i : a) sum += i;
    cout << sum;
    return 0;
}