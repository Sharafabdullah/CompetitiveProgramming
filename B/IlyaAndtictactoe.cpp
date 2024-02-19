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

    int v1 = 'x' + 'x', v2 = '.' + 'x';
    vector<vector<char>> m(6, vector<char>(6));
    rep(i, 0, 5) rep(j, 0, 5) {
        if (i == 0 || j == 0) m[i][j] = 'o';
        else cin >> m[i][j];
    }
    rep(i, 1, 5) rep(j, 1, 5) {
        if (m[i][j] == 'x') {
            // cout << i << "  " << j << endl;

            if ((m[i - 1][j] + m[i + 1][j] == v1 || m[i - 1][j] + m[i + 1][j] == v2) ||
                (m[i - 1][j - 1] + m[i + 1][j + 1] == v1 || m[i - 1][j - 1] + m[i + 1][j + 1] == v2) ||
                (m[i - 1][j + 1] + m[i + 1][j - 1] == v1 || m[i - 1][j + 1] + m[i + 1][j - 1] == v2) ||
                (m[i][j - 1] + m[i][j + 1] == v1 || m[i][j - 1] + m[i][j + 1] == v2)
                ) {
                cout << "YES"; return 0;
            }
        }
        if (m[i][j] == '.') {
            // cout << i << "  " << j << endl;

            if ((m[i - 1][j] + m[i + 1][j] == v1) ||
                (m[i - 1][j - 1] + m[i + 1][j + 1] == v1) ||
                (m[i - 1][j + 1] + m[i + 1][j - 1] == v1) ||
                (m[i][j - 1] + m[i][j + 1] == v1)
                ) {
                cout << "YES"; return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}