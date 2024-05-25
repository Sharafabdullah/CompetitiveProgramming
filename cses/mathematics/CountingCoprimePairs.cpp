#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define sz(x)         ((int)(x).size())
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))


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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 1e6+ 100, M = 10;
ll k,n,m;

vector<ll> primes;
void sieve(int n) {
    // 500ms to get primes up to 1e7 -> ~660000 primes
    bitset<10000000> prime; prime.set();
    for (ll p = 2; p * p<= n; p++) {
        if (prime[p]) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]) primes.pb(p);
}

void PrimeDivisorsRange(ll mxVal, vvi& divOf){
    for (ll i = 2; i < mxVal; i++)
    {
        if(divOf[i].size()==0){
            //this number is a prime - have not been reached before
            divOf[i].pb(i);
            for (int j = 2*i; j < mxVal; j+=i)
            {
                divOf[j].pb(i);
            }
        }
    }
}

void solve(){
    cin>>n;
    //answer = all possible pairs - pairs that have gcd>1
    // pairs with gcd>1 == num div by 2 + num div by 3 + num div by 5 ...
                    //     - num div by 10 - # div by 6 - # div by 10 ...
                    //     + num div by 30 + num div by 42..
                    //* if combination of multiple of primes is odd -> add, else subtract
    vll v(n); for(ll& i: v) cin>>i;
    vvi divOf(N);
    PrimeDivisorsRange(N, divOf);
    // deb(divOf);
    vi numOfDistinctPrimeComb(N), primesCount(N);
    for (int i = 0; i < n; i++)
    {
        for(int mask = 1; mask< (1<<divOf[v[i]].size()); mask++){
            //get all comb of prime div of v[i]
            ll comb = 1, numOfPrimes = 0;
            for (int j = 0; j < divOf[v[i]].size(); j++)
            {
                if(mask & (1<<j)){
                    comb *= divOf[v[i]][j];
                    numOfPrimes++;
                }
            }
            numOfDistinctPrimeComb[comb]++;
            primesCount[comb]= numOfPrimes;
        }
    }
    ll ans = (n*(n-1))/2;
    ll invalid_pairs = 0;
    for (int i = 0; i < N; i++)
    {
        if(primesCount[i] % 2) invalid_pairs += numOfDistinctPrimeComb[i] * (numOfDistinctPrimeComb[i]-1) / 2;
        else invalid_pairs -= numOfDistinctPrimeComb[i] * (numOfDistinctPrimeComb[i]-1) / 2;
    }
    cout<<ans - invalid_pairs<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}