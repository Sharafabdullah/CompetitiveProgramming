#include <bits/stdc++.h>
using namespace std;

#include<sstream>


#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)


typedef long long ll;
typedef pair<int, int> pi;

const ll OO = 1e8;
const double EPS = (1e-7);

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }


#define pb					push_back
#define mp					make_pair
#define p(x)				cout<<#x<<" = { "<<x<<" }\n"

typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 0, r = 0;
    string s, ext;
    bool d = 0;
    cin >> s >> ext;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '|') { d = 1;continue; }
        if (d) r++;
        else l++;
    }
    // p(l);
    // p(r);
    // p(ext.length());
    if (((l + r + ext.length()) % 2) || ext.length() < abs(r - l)) cout << "Impossible";
    else {
        while (!ext.empty()) {
            if (l < r) {
                s.insert(0, 1, ext[0]);
                l++;
            }
            else {
                s.append(1, ext[0]);
                r++;
            }
            ext.erase(0, 1);
        }
        cout << s;
    }


    return 0;
}