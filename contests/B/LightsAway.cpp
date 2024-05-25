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

    vi v(9);
    for (int& i : v) cin >> i;
    sort(all(v));
    int ans = 0;
    while (!v.empty()) {
        bool f = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = i + 1; j < v.size() - 1; j++)
            {
                if (v[i] + v[j] > v[v.size() - 1]) {

                    ans++;
                    f = 1;
                    v.erase(v.begin() + i);
                    v.erase(v.begin() + j);
                    v.erase(v.end() - 1);
                    // i--;
                    break;
                }
            }
            if (f) break;
            // cout << endl << i << "  " << endl;
            // for (int w : v) cout << w << " ";
        }
        if (!f) { v.erase(v.end() - 1); }
    }

    cout << ans;


    return 0;
}