#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
#define coutfloat(n,d)     cout << fixed << setprecision(d) << n << endl
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)


typedef long long ll;
typedef unsigned long long ull;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<bool>      vb;
typedef vector<vb>        vvb;
typedef vector<string>    vs;
typedef vector<int>       vi;
typedef vector<ll>       vll;
typedef vector<double>    vd;
typedef vector< vi >      vvi;


#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;

vector<ll> primes;
void sieve(int n) {
    // 500ms to get primes up to 1e7 -> ~660000 primes
    bitset<10000001> prime; prime.set();
    for (ll p = 2; p * p<= n; p++) {
        if (prime[p]) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]) primes.pb(p);
}

void primeFactors(ll n, vector<int>& v) 
{ 
    //you can use map
    for (ll i = 2; i*i <= n; i++){
        if(n%i==0){
            int c = 0;
            while(n%i==0) n/=i, v.pb(i);
            // v.pb({i, c});
        }
    }
    if (n > 1) v.pb(n); 
    sort(v.rbegin(), v.rend());
} 

void solve(){
    int d;
    cin>>n>>d;
    ll r = 0, b = 0;
    vi a(n), ind(n,0);
    vvi fact(n);
    rep(i,0,n){
        cin>>a[i];
        primeFactors(a[i], fact[i]);
    }
    deb(fact)
    rep(i,0,d){
        int cur = i % n;
        int bPrime = fact[cur].size() <= ind[cur]?0: fact[cur][ind[cur]++];
        deb(bPrime)
        deb(fact[cur])
        if(bPrime!=0) {
            int bPrimeInd =  lower_bound(all(primes), bPrime) - primes.begin() + 1;
            if(bPrimeInd % 2) r+= bPrime;
            else b+= bPrime;
        }
        deb(r) deb(b)
        if(r>=b) cout<<"R"<<endl;
        else cout<<"B"<<endl;
    }
}

int main(){
    FASTIO;
    sieve(1e7);
    int t= 1;
    // cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}