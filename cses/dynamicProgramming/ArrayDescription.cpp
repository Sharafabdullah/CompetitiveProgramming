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
int k,n,m;
vi v;
// vvi memo(101, vi(1e5+2, -1));
// ll dp(int ind, int g){
//     // deb(ind) deb(g)
//     if(g>m || g<0 || ind >n ) return 0;
//     if(ind==n) return 1;
//     if(memo[g][ind] != -1) return memo[g][ind];

//     if(v[ind]==0){
//         int ans = dp(ind+1, g);
//         if(g>1) ans = (ans + dp(ind+1, g-1))%mod;
//         if(g<m) ans = (ans + dp(ind+1, g+1))%mod;
//         return memo[g][ind] = ans;
//     }
//     else{
//         if(abs(g-v[ind])>=2) return 0;
//         return memo[g][ind] = dp(ind+1, v[ind]);
//     }
// }

void solve(){
    cin>>n>>m;
    rep(i,0,n) { cin>> k; v.pb(k);}
    // cout<<dp(0, v[0]);
}
void solve2(){
    cin>>n>>m;
    vvi tab(n+1, vi(m+1));
    vector<ll> v(n); for(auto& i: v) cin>>i;
    if(v[0]==0){
        rep(i, 1,m+1){
            tab[1][i] = 1;
        }
    } else tab[1][v[0]] = 1;
    rep(i,2,n+1){
        if(v[i-1]==0){
            rep(j,1,m+1){
                tab[i][j] = tab[i-1][j];
                if(j-1>=1) tab[i][j] = (tab[i][j] + tab[i-1][j-1])%mod;
                if(j+1<=m) tab[i][j] = (tab[i][j] + tab[i-1][j+1])%mod;
            }
        }
        else{
            tab[i][v[i-1]] = tab[i-1][v[i-1]];
            if(v[i-1]-1>=1) tab[i][v[i-1]] = (tab[i][v[i-1]] + tab[i-1][v[i-1]-1])%mod;
            if(v[i-1]+1<=m) tab[i][v[i-1]] = (tab[i][v[i-1]]+ tab[i-1][v[i-1]+1])%mod;
        }
        
    }
    int ans = 0;
    rep(j, 0, m+1) ans= (ans +tab[n][j])%mod;
    // deb(tab)
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}