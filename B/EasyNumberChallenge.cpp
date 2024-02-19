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
const ll inf = 1 << 30;
const double eps = (1e-8);

ll const Max = 1e6 + 9;
vector<ll> primes;

void genPrimes() {
    ll upLim = sqrt(Max);
    vector<bool> isPrime(upLim + 1, 1);
    for (ll p = 2; p <= upLim; p++)
    {
        if (isPrime[p]) {
            primes.pb(p);
            // cout << p << "  ";
            for (ll i = p * 2; i <= upLim; i += p)
            {
                isPrime[i] = 0;
            }
        }
    }

}

ll countDiv(ll num) {
    ll count = 1;
    for (ll p : primes) {
        if (p * p > num) break;
        ll pow = 0;
        while (num % p == 0) {
            pow++;
            num /= p;
        }
        count = ((pow + 1) * count) % inf;
    }
    if (num > 1) {
        count = (2 * count) % inf;
    }
    return count;
}
vi d(Max, 1);
int main() {
    genPrimes();
    // for (int i : primes)cout << i << "    ";
    for (size_t i = 0; i < Max; i++)
    {
        d[i] = countDiv(i);
    }
    int a, b, c;
    ll ans = 0;
    cin >> a >> b >> c;
    rep(i, 1, a + 1) {
        rep(j, 1, b + 1) {
            rep(k, 1, c + 1) {
                ans += d[i * j * k];
                ans %= inf;
            }
        }
    }
    cout << ans;

    return 0;
}