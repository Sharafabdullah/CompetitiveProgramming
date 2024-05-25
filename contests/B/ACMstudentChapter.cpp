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

vi l(100000);

bool check(int mid) {
    queue<pi> q, finish;
    for (int i = 0; i < l.size(); i++)
    {
        if (!finish.empty() && finish.front().first <= i) {
            // p(i);
            // p(finish.front().first);
            mid += finish.front().second;
            // p(mid);
            // for(pi p: finish){

            // }
            finish.pop();
        }
        if (l[i] > 0) {
            q.push({ i + 3 * 60 * 60, l[i] });
        }
        if (mid > 0 && !q.empty()) {
            int f = 0;
            while (mid-- && (q.front().second-- > 0)) {
                p(f);
                p(mid);
                // mid--;
                f++;
            }
            p(i + 900);
            finish.push({ i + 900, f });
            if (q.front().second == 0) q.pop();
        }
        if (!q.empty() && i > q.front().first) {
            return false;
        }
    }
    return true;

}


int main() {

    int t, n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        t = stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
        // cout << t << endl;
        l[t]++;
    }
    for (int i : l) {
        if (i > 0) cout << i << "  ";
    }
    cout << endl;
    int lo = 0, hi = 1000, ans = 1, md;
    while (lo <= hi) {
        md = (lo + hi) / 2;
        p(md);
        // p(lo);
        // p(hi);
        if (check(md)) {
            ans = md;
            lo = md + 1;
        }
        else hi = md - 1;
    }
    cout << ans << endl;

    return 0;
}