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


void solve(){
    cin>>n>>m;
    vvi dp(n+1, vi(m+1));
    rep(i,1,n+1){
        dp[i][1]=i-1;
        rep(j,2,m+1){
            if(i==1){ dp[i][j]= j-1;continue;}
            if(i==j) continue;
            dp[i][j]=min(dp[i-1][j]+dp[1][j]+1, dp[i][j-1]+dp[i][1]+1);
            for (int k = 2; k < max(i,j); k++)
            {
                if(i-k>=1) dp[i][j]=min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
                if(j-k>=1) dp[i][j]=min(dp[i][j], dp[i][j-k]+dp[i][k]+1);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}