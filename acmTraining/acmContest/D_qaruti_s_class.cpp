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

const int N = 1e6+1000, M = 10;
int k,n,m;

vector<ll> primes;
vll ans(N,0);
void sieve(int n) {
    // 500ms to get primes up to 1e7 -> ~660000 primes
    bitset<3000001> prime; prime.set();
    for (ll p = 2; p * p<= n; p++) {
        if (prime[p]) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]) primes.pb(p);
}

void solve(){
    cin>>n;
    cout<<ans[n]<<endl;
}
    set<int> comb;

void primeFactors(ll n, vector<int>& v) 
{ 
    //you can use map
    for (ll i = 2; i*i <= n; i++){
        if(n%i==0){
            int c = 0;
            while(n%i==0) n/=i, c++;
            v.pb(i);
        }
    }
    if (n > 1) v.pb(n); 
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;

    sieve(2e6+1000);
    ans[1] = 1;
    ans[2] = 2;
    ll np = primes[1];
    int ind = 1;

    queue<ll> q;
    for (int n = 3; n < 1e6+1000; n++)
    {
        ans[n] = ans[n-1];
        if(q.size()&&n == q.front()){
            q.pop();
            ans[n]--;
            continue;
        }
        if(n%np==0){
            ind++;
            q.push(np*2);
            deb(np*2)
            np= primes[ind];
            ans[n]++;
        }
    }
    // rep(i,1,100) cout<<i<<" : "<<ans[i]<<endl;
    // rep(i,1,100) cout<<i<<" : "<<primes[i]<<endl;
    // comb.clear();
    // set<int> seen;
    // for (int i = 2; i < 100; i++)
    // {
    //     vector<int> v;
    //     ans[i]=ans[i-1];
    //     primeFactors(i,v);
    //     for(auto p: v){
    //         if(seen.count(p)==0){
    //             comb.insert(p);
    //             ans[i]++;
    //         }
    //         else if()
    //     }
    // }
    
    cin>>t;
    while(t--) solve();
    

    return 0;
}