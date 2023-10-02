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


vi p;
vector<bool> isPrime(1000, true);
void sieveOfEratosthenes(int n) {

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // cout << "Prime numbers up to " << n << " are:" << endl;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            p.pb(i);
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // vi p = {2,3,5,7,11,13,17, 19, 23,29, 31, 37,43, 47,49};
    sieveOfEratosthenes(50);
    cin >> n >> m;
    // cin >> n >> m;
    bool ok = 0;

    if (isPrime[m] && find(all(p), n) + 1 == find(all(p), m)) cout << "YES";
    else cout << "NO";
    return 0;
}