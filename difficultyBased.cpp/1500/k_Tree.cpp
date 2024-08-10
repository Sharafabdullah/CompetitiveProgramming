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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    int d;
    cin>>n>>k>>d;
    vll helper(200), dp(200);
    rep(i,1,k+1){
        helper[i] = 1;
        if(i>=d) dp[i] = 1;
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if(i - j <0) break;
            helper[i] =(helper[i] + helper[i-j])%mod;
        }
        
    }
    for (int i = 1; i < n+1; i++)
    {
        dp[i] = (dp[i] + dp[i-1])%mod;
        for(int j = d; j<k+1; j++){
            if(i -j <0) break;
            dp[i] =(dp[i] + helper[i-j])%mod;
        }
    }
    

    deb(helper)
    deb(dp)
    cout<<dp[n]<<endl;
    
    
}
void solve2(){
    int d;
    cin>>n>>k>>d;
    vector<vll> dp(n+1, vll(2));
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < d; j++)
        {
            if(i-j<0) break;
            dp[i][0] = (dp[i][0] + dp[i-j][0])%mod;
            dp[i][1] = (dp[i][1] + dp[i-j][1])%mod;
        }
        for (int j = d; j < k+1; j++)
        {
            if(i-j<0) break;
            dp[i][1] = (dp[i][1]+dp[i-j][0]+ dp[i-j][1])%mod;
        }
    }
    cout<<dp[n][1]<<endl;
    

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    solve2();
    

    return 0;
}