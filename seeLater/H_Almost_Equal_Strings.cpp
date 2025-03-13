// #pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")

#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (int i = (begin); i < (end); ++i)
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
const ll mod1 = 1e9 + 7;

const int N = 1e6+10, M = 10;
int k,n,m;


int base1 = 127, base2 = 131, mod2 = 1e9+11;
int pw2[N], pw1[N];

void init(){
    pw2[0] = pw1[0] = 1;
    rep(i,1,(int)N){
        pw1[i] = (1ll*pw1[i-1]*base1)%mod1;
        pw2[i] = (1ll*pw2[i-1]*base2)%mod2;
    }
}
vector<pi> h;
void hashing(string& s){
    int h1 = 0, h2= 0;
    h.reserve(s.size());
    rep(i, 0, s.size()) {
        h1 = (1ll * h1 * base1 + s[i]) % mod1;
        h2 = (1ll * h2 * base2 + s[i]) % mod2;
        h.emplace_back(h1, h2);
    }
}
pi get(int l, int r){
    pi ret = h[r];
    int sz = r - l + 1;
    if (l > 0) {
        ret.first = (ret.first - 1ll * pw1[sz] * h[l-1].first % mod1 + mod1) % mod1;
        ret.second = (ret.second - 1ll * pw2[sz] * h[l-1].second % mod2 + mod2) % mod2;
    }
    return ret;
}

void solve(){
    cin>>n; string s; cin>>s;
    hashing(s);
    int q; cin>>q;
    while(q--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        a--,b--,c--,d--; int len1 = b - a + 1, len2 = d - c + 1;
        if(len1!=len2){
            cout<<"DIFFERENT\n";
            continue;
        }
        int lo = 0, hi = len1 - 1;
        while (lo <= hi) {
            int md = lo + (hi - lo) / 2;
            if (get(a, a + md) != get(c, c + md)) hi = md - 1;
            else lo = md + 1;
        }
        deb(lo)
        if(lo == len1 || get(a+lo+1, b) == get(c+lo+1, d)){
            cout<<"SIMILAR\n";
        }
        else cout<<"DIFFERENT\n";
    }
    // int n; cin >> n;
    // string s; cin >> s;
    // hashing(s);
    
    // int q; cin >> q;
    // while (q--) {
    //     int a, b, c, d; 
    //     cin >> a >> b >> c >> d;
    //     --a; --b; --c; --d;
        
    //     int len1 = b - a + 1, len2 = d - c + 1;
    //     if (len1 != len2) {
    //         cout << "DIFFERENT\n";
    //         continue;
    //     }

    //     int lo = 0, hi = len1 - 1;
    //     while (lo <= hi) {
    //         int md = lo + (hi - lo) / 2;
    //         if (get(a, a + md) != get(c, c + md)) hi = md - 1;
    //         else lo = md + 1;
    //     }

    //     if (lo == len1 || get(a + lo+1, b) == get(c + lo+1, d)) {
    //         cout << "SIMILAR\n";
    //     } else {
    //         cout << "DIFFERENT\n";
    //     }
    // }
}

int main(){
    FASTIO;
    init();

    int t= 1;
    // cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}