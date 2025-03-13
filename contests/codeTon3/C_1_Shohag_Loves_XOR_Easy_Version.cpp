#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repd(i, a, b) for (int i = a; i >= b; --i)
#define pb            push_back
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
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
#define deb(...) cerr << "[" << #__VA_ARGS__ << "] = "; _print(__VA_ARGS__); cerr << endl;
#else
#define deb(...)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename... Args>
void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 2e6+10000, M = 10;
ll k, n, m;




void solve(){
    ll x;
    cin>>x>>m;
    ll ans = 0;
    int mn = min(m, 2*x+10);

    // multiset<int> xFact;
    // getFact(x, xFact);
    for(int i = 1; i<=mn; i++){
        deb(i)
        int cur = x ^ i;
        if(cur == 0) continue;
        bool taken = 0;
        if(cur <= i){
            if(i / cur == i * 1.0 /cur){
                ans ++;
                taken = 1;
            }
        }
        if(cur <= x && !taken){
            if(x / cur == x*1.0 / cur){
                ans ++;
                taken = 1;
            }
        }
        // if(dv[x].count(cur) || dv[i].count(cur)) ans++;
    }
    deb(ans)
    cout<<ans<<endl;
}

int main(){
    FASTIO;
    // rangeDivisors(dv);
    // sieve(N);
    // PrimeDivisorsRange(N,dv);
    // biggestPrimeFactors(N, bPrimes);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
