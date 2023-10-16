#include <bits/stdc++.h>
using namespace std;

// #include<sstream>


#define all(v)				((v).begin()), ((v).end())
// #define sz(v)				((int)((v).size()))
// #define clr(v, d)			memset(v, d, sizeof(v))
#define repe(i, v)		for(int i=0;i<(v).size();++i)
// #define rep(i, n)		for(int i=0;i<(int)(n);++i)
#define rep(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define dow(i, j, n)	for(int i=(j);i>=(int)(n);--i)

#define pb					push_back
#define mp					make_pair
#define p(x)				cout<<#x<<" = { "<<x<<" }\n"



const ll inf = 1e9;
const double eps = (1e-8);

// int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }



typedef long long ll;
typedef pair<int, int> pi;
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
// typedef vector< vd >      vvd;
// typedef vector<string>    vs;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, q, l, r, f, e;
    vector<bool> s1(2060, 0), s2(2060, 0);
    cin >> p >> q >> l >> r;
    while (p--) {
        cin >> f >> e;
        for (int i = f; i <= e; i++)
        {
            s1[i] = 1;
        }
    }
    while (q--) {
        cin >> f >> e;
        for (int i = f; i <= e; i++)
        {
            s2[i] = 1;
        }
    }
    // for (int i = 0; i < 700; i++)
    // {
    //     cout << " { " << s1[i] << ", ";
    //     cout << s2[i] << " } ";
    //     if (i % 10 == 0) cout << endl;
    // }
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            if (s1[i + j] && s2[j]) {
                // cout << "i: " << i << "   j:" << j << endl;
                cnt++;
                break;
            }
        }
    }
    cout << cnt;


    return 0;
}