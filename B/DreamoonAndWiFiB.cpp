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


vi v;

void flip(int c, int pos) {
    if (c == 0) {
        v.push_back(pos);
        return;
    }
    flip(c - 1, pos + 1);
    flip(c - 1, pos - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str1, str2;
    cin >> str1 >> str2;
    int corp = 0, assump = 0, q = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == '+') corp++;
        else corp--;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        if (str2[i] == '+') assump++;
        else if (str2[i] == '-') assump--;
        else {
            q++;
        }
    }
    flip(q, assump);
    long double ans = (count(all(v), corp) * 1.0) / v.size();
    cout << fixed << setprecision(10) << (ans);


    return 0;
}