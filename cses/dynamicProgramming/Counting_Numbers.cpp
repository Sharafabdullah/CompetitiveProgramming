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
ll k,n,m;

ll dp[20][10][2][2];
ll get(string& n, int ind, int prev,bool leading_z, bool mx){
    if(ind == n.size()){
        return 1;
    }
    if(prev!=-1 && dp[ind][prev][leading_z][mx]!=-1) return dp[ind][prev][leading_z][mx];
    ll ans = 0;
    int up = 9;
    if(mx){
        up = n[ind] - '0';
    }
    
    for (int i = 0; i <= up; i++) {
        if(i == prev && leading_z==0) continue;
        ans += get(n, ind + 1, i,leading_z && (i==0) ,mx && (i == up));
    }
    return dp[ind][prev][leading_z][mx] = ans;
}

void solve(){
    cin >> n >> m;
    string ns= to_string(n-1), ms= to_string(m);
    memset(dp, -1, sizeof(dp));
    ll n1 = get(ns, 0, -1,1, 1);

    // deb(n1) 
    memset(dp, -1, sizeof(dp));
    ll m1 = get(ms, 0, -1,1, 1);
    // deb(m1)
    cout << m1 - n1 << endl;
}

void solve2(){
    cin>>n>>m;
    
}

int main(){
    FASTIO;

    int t = 1;
    // cin >> t;
    while(t--) solve();
    // solve2();

    return 0;
}
