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

const int N = 3e5, M = 10;
int k,n,m;

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


template<typename T>
struct cmp {
    bool operator()( T& p1,  T& p2)  {
        return p1 > p2;
    }
};

void divisors(ll n, vector<ll>& div) 
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
void rangeDivisors( vvi& num){
    for (int i = 1; i < num.size(); i++)
    {
        //for each number - add it to the numbers that this number divides
        for(int j = i; j< num.size(); j+= i){
            num[j].pb(i);
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
void PrimeDivisorsRange(ll mxVal, vvi& divOf){
    for (ll i = 2; i < mxVal; i++)
    {
        if(divOf[i].size()==0){
            //this number is a prime - have not been reached before
            divOf[i].pb(i);
            for (int j = 2*i; j < mxVal; j+=i)
            {
                //only gets distinct primes
                divOf[j].pb(i);
            }
        }
    }
}
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

void fastPrimeFact(ll n, vi& v){
    //do sieve first - v index i will have the number of the ith prime in n
    for (int i = 0; i < primes.size() && i<v.size(); i++)
    {
        while(n%primes[i]==0) {v[i]++; n/= primes[i];}
    }
}
void primeFactors(ll n, vector<pi>& v) 
{ 
    //you can use map
    for (ll i = 2; i*i <= n; i++){
        if(n%i==0){
            int c = 0;
            while(n%i==0) n/=i, c++;
            v.pb({i, c});
        }
    }
    if (n > 1) v.pb({n,1}); 
} 

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

class MinSegmentTree {
    //*Change min to max in build and in query
private:
    int n; // Size of the input array
    vi tree;
    // Build the segment tree
    void build(int v, int tl, int tr, vi& arr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm,arr);
            build(2 * v + 1, tm + 1, tr,arr);
            tree[v] = min(tree[2 * v], tree[2 * v + 1]);
        }
    }

public:
    // Constructor: Initialize the segment tree
    MinSegmentTree(vector<int>& input) {
        n = input.size();
        tree.resize(4*n);
        build(1, 0, n - 1, input); // Build the segment tree
    }

    // Query the minimum value in the range [l, r]
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) return INT_MAX; // Empty range
        if (l == tl && r == tr) return tree[v]; // Fully covered range
        int tm = (tl + tr) / 2;
        return min(query(2 * v, tl, tm, l, min(r, tm)),
                   query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    // Public query method
    int query(int l, int r) {
        if(l>r|| r>=n || l>=n) {
            deb(l) deb(r)
            return inf;
        }
        return query(1, 0, n - 1, l, r);
    }
    void print(){
        deb(tree);
    }
};

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
void solve(){
    ll lo = 0, hi = inf;
    auto cmp = [&](ll md){
        return true;
    };
    //finds the first true given by cmp (lo). hi is the last false
    while(lo<=hi){
        ll md = lo + (hi-lo)/2;
        if(cmp(md)) hi = md - 1;
        else lo = md+1;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}