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

ll inv(ll b){
    return mpow(b, mod-2); //fermat's little theorem b^(m-1) = 1 mod(m) when m is prime
                     // -> b^(m-2) == b^(-1) mod(m)
}

ll mul(ll a, ll b){
    return ((a%mod) * (b%mod)+mod)%mod;
}

ll divide(ll a, ll b){
    return mul(a, inv(b)); 
}
ll add(ll a, ll b){
    return (a%mod + b%mod)%mod;
}
ll sub(ll a, ll b){
    return (a%mod - b%mod + mod)%mod;
}
int base = 31;

int pw[N];
int invVal;
void init(){
    invVal = mpow(base, m-2);
    pw[0] = 1;
    rep(i,1,(int)N){
        pw[i] = (1ll * pw[i-1] * base)%mod;
    }
}

struct Hashing{
    int len, h;
    deque<char> d;
public:
    Hashing(int h){
        h = len = 0;
    }
    void push_back(char c){
        if(len ==0 ) return;
        int dig = c - 'a';
        h = add(dig, mul(h, base));
        d.push_back(c);
        len++;
    }
    void pop_back(){
        int dig = d.back() - 'a';
        h = mul(sub(h,dig), invVal);
        d.pop_back();
        len--; 
    }
    void push_front(char c){
        int dig = c - 'a';
        h = add(h,mul(dig, pw[len]));
        d.push_front(c);
        len++;
    }
    void pop_front(){
        if(len==0) return;
        int dig = d.front() - 'a';
        h = sub(h, mul(dig, pw[len-1]));
        d.pop_front();
        len--;
    }
};

void solve(){
    
    
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}