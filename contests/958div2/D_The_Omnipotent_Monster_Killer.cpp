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

const ll inf = 1e18+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


// void solve(){
//     cin>>n;
//     ll sum = 0;
//     vll a(n); rep(i,0,n) {cin>>a[i];sum+=a[i];}
//     vvi g(n);
//     rep(i,0,n-1){
//         int a,b; cin>>a>>b; a--,b--;
//         g[a].pb(b);
//         g[b].pb(a);
//     }
//     queue<tuple<int,bool,ll>> q;
//     q.push({0, 0, 0});
//     q.push({0, 1,0});
//     vi vis(n);
//     int d = 0,sz=1;
    
//     ll s1 = 0, s2=0;
//     vector<vll> dp(n+1, vll(2));

//     while(!q.empty()){
//         auto [cur, taken, val] = q.front();q.pop();
//         sz--;
//         // deb(cur)
//         // deb(s1)
//         dp[cur][taken] = max(dp[cur][taken], val );
//         s1 = max(s1,val);
//         for(int ch: g[cur]){
//             if(vis[ch]<3){
//                 vis[ch]++;
//                 if(taken){
//                     q.push({ch, 0, val});
//                 }
//                 else{
//                     q.push({ch, 1, val + a[ch]});
//                     q.push({ch, 0, val});
//                 }
//                 // q.push({ch, taken^1, });
//             }
//         }
//         if(!sz){
//             sz = q.size();
//             d++;
//         }
//     }
//     deb(s1) deb(sum - s1)
//     ll mx = 0;
//     for(auto vec: dp){
//         for(ll elm: vec){
//             mx = max(mx, elm);
//         }
//         break;
//     }
//     // deb(mx)
//     cout<< sum + s1<<endl;
// }
vvi g; 
vll a;
int lg=20;
vector<vll> dp(lg, vll(N));
void dfs(int cur, int par){
    rep(i,0,lg){
        dp[i][cur] = (i+1)*a[cur];
    }
    for(int ch: g[cur]){
        if(ch==par) continue;
        dfs(ch, cur);
        ll mn1=inf, mn2=inf;
        rep(i,0,lg){
            mn1= min(mn1, dp[i][ch]);
            if(mn1<mn2) swap(mn1,mn2);
        }
        rep(i,0,lg){
            ll val = mn2;
            // rep(j,0,lg){
            //     if(j==i) continue;
            //     val = min(val, dp[j][ch]);
            // }
            if(dp[i][ch]==mn2) val = mn1;
            dp[i][cur]+= val;
        }
    }
}

void solve2(){
    cin>>n;
    a = vll(n); rep(i,0,n) {cin>>a[i];}
    g = vvi(n);
    rep(i,0,lg){
        rep(j,0,n+1){
            dp[i][j]= inf;
        }
    }
    rep(i,0,n-1){
        int a,b; cin>>a>>b; a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0,-1);
    ll ans = inf;
    rep(i,0,lg) ans=min(ans, dp[i][0]);
    cout<<ans<<endl;
};
int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}