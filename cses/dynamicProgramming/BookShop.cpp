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

// vi pages, books;
// vvi memo(1001,vi(1e5+1, -1));
// int dp(int ind, int m){
//     if(m<0) return -inf;
//     if(m<=0 || ind>=n) return 0;
//     if(memo[ind][m]!=-1) return memo[ind][m];
//     int ans = 0;
//     // rep(i,ind+1, n){
//     //     if(m - books[i]>=0){
//     //         ans = max(ans, dp(i, m - books[i]) + pages[i]);
//     //     }
//     // }
//     return memo[ind][m] = max(dp(ind+1, m), dp(ind+1, m- books[ind])+pages[ind]);
// }

// void solve(){
//     cin>>n>>m;
//     books.resize(n), pages.resize(n);
//     rep(i,0,n) cin>>books[i];
//     rep(i,0,n) cin>>pages[i];
//     cout<<dp(0, m)<<endl;
// }

void solve2(){
    cin>>n>>m;
    vi w(n), profit(n);
    rep(i,0,n) cin>>w[i];
    rep(i,0,n) cin>>profit[i];

    vvi tab(1005,vi(1e5+10));
    rep(i,1,n+1){
        rep(j, 1, m+1){
            tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
            if(j - w[i-1] >=0 ) tab[i][j] = max(tab[i][j], tab[i-1][j-w[i-1]] + profit[i-1]);
        }
    }
    // deb(tab)
    cout<<tab[n][m]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve(); tle
    while(t--) solve2();
    

    return 0;
}