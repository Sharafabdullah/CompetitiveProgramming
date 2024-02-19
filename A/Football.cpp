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

    // int n;
    // cin >> n;
    // string s1, s2 = "", tmp;
    // int n1 = 0, n2 = 0;
    // cin >> s1; n--;
    // n1++;
    // while (n--) {
    //     cin >> tmp;
    //     if (s2.empty() && tmp != s1) s2 = tmp;
    //     if (tmp == s1) n1++;
    //     else n2++;
    // }
    // // p(n1);
    // // p(n2);
    // if (n1 < n2) cout << s2;
    // else cout << s1;
    int n; cin >> n;
    map<string, int> m;
    string tmp;
    while (n--) {
        cin >> tmp;
        if (m.empty()) m.insert({ tmp, 0 });
        else if (m.count(tmp) == 0) m.insert({ tmp, 0 });
        else m[tmp]++;
    }
    // p(m.begin()->first);
    // p(m.begin()->second);
    // p((--m.end())->first);
    if (m.begin()->second > (--m.end())->second) cout << m.begin()->first;
    else cout << (--m.end())->first;
    return 0;
}