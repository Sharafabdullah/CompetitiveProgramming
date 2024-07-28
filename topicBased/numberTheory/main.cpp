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

const int N = 3e5, M = 10;
int k,n,m;

void divisors(int n, vector<ll>& div) 
{ 
    for (ll i=1; i*i<=n; i++) 
    { 
        if (n%i == 0) 
        { 
            div.pb(i);
            if(i*i != n) div.pb(n/i);
        } 
    } 
}

void rangeDivisors(int n, vvi& num){
    for (int i = 1; i <= n; i++)
    {
        //for each number - add it to the numbers that this number divides
        if(num[i].empty()){
            for(int j = i; j<=n; j+= i){
                num[j].pb(i);
            }
        }
    }
}

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return (a/gcd(a,b)) * b;
}

vector<ll> primes;
void sieve(int n) {
    // 500ms to get primes up to 1e7 -> ~660000 primes
    bitset<10000000> prime; prime.set();
    // vb prime(n+1, 1);
    for (ll p = 2; p<= n; p++) {
        if (prime[p]) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
            primes.pb(p);
        }
    }
    // for (int p = 2; p <= n; p++)
    //     if (prime[p]) primes.pb(p);
}

void primeFactors(int n, vector<pi>& v) 
{ 
    for (ll i = 2; i*i <= n; i++){
        if(n%i==0){
            int c = 0;
            while(n%i==0) n/=i, c++;
            v.pb({i, c});
        }
    }
    if (n > 1) v.pb({n,1}); 
} 

void fastPrimeFact(ll n, vi& v){
    //do sieve first - v index i will have the number of the ith prime in n
    for (int i = 0; i < primes.size() && i<v.size(); i++)
    {
        while(n%primes[i]==0) {v[i]++; n/= primes[i];}
    }
}

using namespace chrono; steady_clock::time_point tstt,endt;
void start(){tstt = steady_clock::now();}
void end(int i = 0){
    if(!i) cout<<"Time: "<<duration_cast<microseconds>(steady_clock::now()- tstt).count()<<char(230)<<"s"<<endl;
    else cout<<"Time: "<<duration_cast<milliseconds>(steady_clock::now()- tstt).count()<<"ms"<<endl;}


void solve(){
    vector<ll> v;
    divisors(16, v);
    deb(v)
    vector<pi> p;
    primeFactors(16, p);
    deb(p)
    deb(gcd(43242312,2142155344));
    deb(lcm(342,213))

    // start();
    sieve(10000);
    deb(primes.size());
    deb(primes.back())
    // deb(primes)
    // end(1);
    vi fact(10);
    fastPrimeFact(16, fact);
    deb(fact)
    
}
ll mpow(ll bs, ll exp) {
    ll res = 1;
    bs = bs % mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * bs) % mod;
        exp = exp >> 1;
        bs = (bs * bs) % mod;
    }
    return res;
}

ll inverse(ll b){
    return mpow(b, mod-2); //fermat's little theorem b^(m-1) = 1 mod(m) when m is prime
                     // -> b^(m-2) == b^(-1) mod(m)
}

ll mul(ll a, ll b){
    return ((a%mod) * (b%mod)+mod)%mod;
}

ll divide(ll a, ll b){
    return mul(a, inverse(b)); 
}
ll add(ll a, ll b){
    return (a%mod + b%mod)%mod;
}
ll subtract(ll a, ll b){
    return (a%mod - b%mod + mod)%mod;
}


ll phi(ll n){
    //return the number of coprimes
    int ans = n; //all the numbers
    for(ll i= 2; i*i <= n; i++ ){
        if(n%i == 0){
            //this means that we found a prime phi(n) = phi(p1^k1) * phi(p2^k2) ...
            while(n%i==0) n/=i;
            ans -= ans/i; //the number of multiples of this prime 
        }
    }
    if(n>1) ans -= ans/n;
    return ans;
}

ll checkPhi(ll n){
    int c= 0;
    rep(i,1,n) if(__gcd(n,(ll) i)==1) c++;
    return c;
}

void arrayMultGCD(){
    vi v1 = { 342,244321,231,20000,231521}; 
    vi v2 = {3412,321,20000}; 
    // find the gcd of the product of first vector and second - v[i] is up to 1e5
    v1 = {100000,100, 10000000};
    v2 = {1000000,10,10000000};
    n = 20000;
    vi v1p(n), v2p(n);
    sieve(2*n);
    for(int i: v1) {
        fastPrimeFact(i, v1p);
    }
    for(int i:  v2) fastPrimeFact(i, v2p);
    // deb(v1p) deb(v2p)
    ll ans = 1;
    rep(i,0, 10){
        if(primes[i]>n) break;
        int common = min(v1p[i], v2p[i]);
        // deb(common)
       deb( mpow(primes[i], common));
        ans = (ans * mpow(primes[i], common));
    }
    deb(ans)
}

void findPhi(int n, vector<ll>& phi){
    rep(i,0,n) phi.pb(i);
    for(int i =2; i<n ; i++){
        if(phi[i]==i){ //this phi hasn't been changed
            for(int mult = i; mult<n; mult+= i){
                phi[mult] -= phi[mult]/i; //for every phi - the number of numbers that are not coprime because of i is phi[mult]/i
            }
        }
    }
}
void phiProg(){
    deb(phi(100));
    deb(checkPhi(100));
    start();
    n = 1e2;
    deb(phi(n));
    end(1);

    cout<<"Brute force phi: "<<endl;
    start();
    deb(checkPhi(n));
    end(1);

    cout<<"Array phi: "<<endl;
    start();
    vector<ll> v; 
    findPhi(n,v);
    end(1);
    deb(v)
    
    // deb(phi(100));
    // deb(checkPhi(100));
    // deb(phi(100));
    // deb(checkPhi(100));

}
std::vector<int> MobiusFunction(int n) {
    std::vector<int> mu(n + 1, 1); // Initialize Möbius function values to 1
    std::vector<int> primes;
    std::vector<bool> is_prime(n + 1, true); // Sieve of Eratosthenes
    
    mu[0] = 0; // By convention, mu(0) is 0
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            mu[i] = -1; // i is a prime number
        }
        for (size_t j = 0; j < primes.size() && i * primes[j] <= n; ++j) {
            int k = i * primes[j];
            is_prime[k] = false;
            if (i % primes[j] == 0) {
                mu[k] = 0; // k has a squared prime factor
                break;
            } else {
                mu[k] = -mu[i]; // k is a product of i and a prime
            }
        }
    }
    
    return mu;
}

int mobius(int n) {
    if (n == 1) return 1; // μ(1) is 1
    int primeCount = 0; // Count of distinct prime factors
    // Check for each prime factor from 2 up to sqrt(n)
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            // p is a prime factor of n
            if (n % (p * p) == 0) {
                return 0; // n has a squared prime factor
            }
            while (n % p == 0) {
                n /= p; // Remove all occurrences of p
            }
            primeCount++;
        }
    }
    // If n is greater than 1, it is a prime factor larger than sqrt(n)
    if (n > 1) {
        primeCount++;
    }
    // If the number of distinct prime factors is even, return 1
    // If it is odd, return -1
    return (primeCount % 2 == 0) ? 1 : -1;
}

void mobiusFunction(){
    //free square -> no square div it - doesn't have repeated primes - don't have prime with power greater than one
    //mob(not free) = 0
    //mob(free) -> if n has odd num of primes: -1 (all primes are -1), if even: 1
    n = 1000;
    vi v = MobiusFunction(1000);
    rep(i,1,n){
        if(mobius(i)!=v[i]) {cout<<"error"<<endl; break;}
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    // arrayMultGCD();
    // phiProg();
    mobiusFunction();
    return 0;
}