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

// #define int long long
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

const int N = 2e5+1000, M = 5;
int k,n,m;
vi a;
ll dp[N][M]={};
ll getMin(int ind, int del){
    if(ind>=n) return 0;
    deb(ind) deb(del) 
    if(dp[ind][del]!=-1) return dp[ind][del];
    ll ans = inf;
    if(a[ind] - 2*del<=0){
        return dp[ind][del]= getMin(ind+1, 0);
    }
    else{
        if(a[ind]<=2) ans = min(ans, getMin(ind+1, 1)+1);
        if(del>=1 && a[ind]<5 &&ind+1<n&& a[ind+1]<5) ans = min(ans, getMin(ind+2, 1)+2);
        ans = min(ans, getMin(ind+1, 0)+1);
        deb(ans)
        return dp[ind][del] = ans;
    }
    
}
void solve(){
    cin>>n;
    rep(i,0,5){
        rep(j,0,n+10){
            dp[j][i]=-1;
        }
    }
    a = vi(n);
    rep(i,0,n) cin>>a[i];
    deb(a)
    cout<<getMin(0,0)<<endl;;
    // deb("n")
}
// #undef int;
void solve2(){
    cin>>n;
    int ans = 0;
    vi a(n);rep(i,0,n) {cin>>a[i]; if(a[i]) ans++;}
    deb(ans)
    auto r2 = [&](int ind){
        return a[ind]==1 || a[ind]==2;
    };
    auto r4 = [&](int ind){
        return r2(ind) || a[ind]==3 || a[ind]==4;
    };
    for(int i = 0; i<n-1;){
        if(r2(i) && r2(i+1)){
            ans--;
            i+=2;
        }
        else if(i<n-3 && r2(i) && r4(i+1) && r4(i+2) && r2(i+3)){
            ans--;
            i+=3;
        }
        else i++;
    }
    cout<<ans<<endl;
}
int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--) solve();
    // while(t--) solve2();

}