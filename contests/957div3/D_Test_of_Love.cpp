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
    cin>>n>>m>>k;
    string s; cin>>s;
    // rep(i,0,s.size()){
    //     if(s[i]=='W' || s[i]=='C'){
    //         cnt=0;
    //         while(i<n && (s[i]=='W' || s[i]=='C')){
    //             cnt++;
    //             i++;
    //         }
    //         if(cnt>=k){
    //             cout<<"NO"<<endl;
    //             return;
    //         }
    //     }
    // }
    // deb("HI")
    vb dp(n+2); dp[0] = 1;
    int cnt= 0;
    rep(i,1,n+2){
        // if(i!=n+1 && (s[i-1]=='C' || s[i-1]=='W')){
        //     cnt++;
        // } else if(n!=-1)cnt=0;
        if(i!=n+1 && s[i-1]=='C') continue;
        rep(j,1,m+1){
            if(i-j<0) break;
            if((i-j==0 || s[i-j-1]=='L')&&dp[i-j]) {
                dp[i] = 1;
            } 
        }
        if(cnt<k && dp[i-1]==1 &&dp[i]==0){
            cnt++;
            dp[i]=1;
        }    
    }
 deb(dp)
    cout<<(dp[n+1]?"YES":"NO")<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}