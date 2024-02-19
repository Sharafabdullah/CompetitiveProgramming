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

string s1, s2;
vi v;
int n, m;

bool can(int mid) {
    vector<bool> rem(n, 0);
    for (int i = 0; i < mid; i++)
    {
        // p(v[i]);
        rem[v[i]] = 1;
    }
    // for (bool b : rem) cout << b << " ";
    // cout << endl;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (rem[i]) continue;
        if (j < m && s1[i] == s2[j]) j++;
    }
    return j == m;
}

int main() {
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    v = vi(n);
    for (int& i : v) { cin >> i; i--; }
    // for (int i : v) cout << i << "    ";
    // cout << endl;

    int lo = 0, hi = n, bst = 0, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (can(mid)) {
            bst = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << bst << endl;


    return 0;
}