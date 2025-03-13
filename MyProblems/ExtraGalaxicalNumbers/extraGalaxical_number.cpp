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

const int N = 1001, M = 10;
int k,n,m,q;

int dp[N][N], pref[N][N], pref_inv[N][N];

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
void solve(){
    cin>>n>>k>>q;
    int n1,n2,k1,k2;
    while(q--){
        cin>>n1>>k1>>n2>>k2;
        ll p1 = (1ll * pref[k2][n2] * pref[k1-1][n1-1])%mod;
        ll p2 = (1ll* pref_inv[k1-1][n2] * pref_inv[k2][n1-1])%mod;
        int ans = (p1 *p2)%mod;
        cout<<ans<<endl;
    }
    
}

int main(){
    FASTIO;

    

    int t= 1;
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for(int i = 1; i<N; i++){
        dp[1][i] = (1ll * dp[1][i-1] * i)%mod;
        dp[0][i] = dp[i][0] = dp[i][1] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i>1 && j>1) dp[i][j] = (1ll * dp[i][j-1] * dp[i-1][j])%mod; 

            pref[i][j] = dp[i][j];
            
            if (i > 0)
                pref[i][j] = (1ll * pref[i][j] * pref[i-1][j])%mod; 
            if (j > 0)
                pref[i][j] = (1ll * pref[i][j] * pref[i][j-1])%mod;
            if (i > 0 && j > 0)
                pref[i][j] = (1ll * pref[i][j] * pref_inv[i-1][j-1])%mod;
            pref_inv[i][j] = inverse(pref[i][j]);
        }
    }


    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}