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
ll k,n,m;


void solve(ll n){
    // cin>>n;
    ll ans = 0;
    //this works in O(n)
    for (ll i = 1; i <= n; i++)
    {
        ans = (ans + (n/i)*i)%mod;
    }
    if(n>2){
        // ans += n*(n+1)/2 - 3;
    }
    deb(ans)
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

ll mul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}

void solve2(){
    cin>>n;
    //ex: for n = 12 there are
    // number: 1 2 3 4 5 6 7 8 9 10 11 12
    // rep   :12 6 4 3 2 2 1 1 1 1 1 1 1 
    //the answer is the sum of (number* rep)
    // but notice that we could save time if we knew the number of numbers for a repition
    // ex: 5,6 repeate two times -> they add 11* 2 to the ans
    // we can calc the next distinct rep by: q = n/i -> i = n/q -> next i = n/q + 1 (works for every number)
    // 11 is their sum -> can be calc O(1) if we knew the position of the prev and next distinct rep.
    ll ans = 0;
    for(ll i = 1, j; i<=n; i = j){
        ll q = n/i;
        j = n/q + 1;
        //* mpow(2,mod-2) == mpow(2, -1) in modular arithmetic
        ll sumToJ = (mul(j, j-1) * mpow(2, mod - 2))%mod;
        ll sumToI = (mul(i, i-1) * mpow(2, mod-2)) % mod;
        //* We have to add mod because sumToJ may be smaller than sumToI after mod
        ll sum = (sumToJ - sumToI + mod)%mod; 
        ans = (ans + mul(q, sum))%mod;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) {
    //     rep(i,1,10){
    //         solve(i);
    //     }
    // }
    solve2();

    return 0;
}