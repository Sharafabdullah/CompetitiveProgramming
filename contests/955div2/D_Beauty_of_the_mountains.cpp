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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n>>m>>k;
    vector<string> g(n);
    vector<vll> a(n, vll(m)); 
    rep(i,0,n) {
        rep(j,0,m) cin>>a[i][j];
    }
    rep(i,0,n) cin>>g[i];

    ll cap = 0, wcap = 0;
    rep(i,0,n){
        rep(j,0,m){
            if(g[i][j]=='1'){
                cap+= a[i][j];
            }
            else{
                wcap += a[i][j];
            }
        }
    }
    deb(cap) deb(wcap)
    vi diff;
    int cur = 0;
    vvi psum(n+1, vi(m+1));
    rep(i,1,n+1){
        rep(j,1,m+1){
            psum[i][j] =  psum[i-1][j] 
                         + psum[i][j-1] 
                         - psum[i-1][j-1];
            if(g[i-1][j-1]=='1') psum[i][j]++;
        }
    }
    // deb(psum);
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= m; j++)
        {
            ll pc = psum[i][j] - psum[i][j-k] - psum[i-k][j] + psum[i-k][j-k];
            ll pwc = k*k - pc;
            // deb(pc)
            // deb(pwc)
            if(pc-pwc == 0) continue;
            else diff.pb(abs(pc-pwc));
        }
    }
    ll d = abs(cap- wcap);
    // deb(d)
    // deb(cap) deb(wcap)
    deb(diff)
    if(diff.size()){
        ll gd = diff[0];
        for(int i :diff){
            gd = gcd(gd,i);
        }
        deb(gd)

        if(d%gd==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        cout<<(d?"NO":"YES")<<endl;
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}