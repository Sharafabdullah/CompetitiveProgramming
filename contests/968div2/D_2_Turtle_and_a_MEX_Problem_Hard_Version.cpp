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

// const int N = 2e5+10, M = 10;
int k,n,m;



void solve(){
    cin>>n>>m;
    int mxf = 0;
    int fmex = 0;
    int N = 0;
    vector<pi> v;
    rep(i,0,n){
        int l;
        cin>>l;
        N = max(l,N);
        map<int,int> mp;
        vi a(l); rep(i,0,l) {cin>>a[i]; mp[a[i]]++;}
        int mex = 0, cnt = 0; 
        while(cnt<2){
            if(!mp.count(mex)){
                cnt++;
                if(cnt==1){
                    mxf = max(mex, mxf);
                    fmex = mex;
                }
            }
            mex++;
        }
        mex--;
        v.pb({fmex, mex});
    }

    N += 5;
    vvi g(N);
    for(auto [f,s]:v){
        g[f].pb(s);
    }

    vi to(N+10);
    rep(i,0,N+10) to[i] = i;
    for(int i = N-1; i>=0; i--){
        for(int ch: g[i]){
            to[i] = max(to[i], to[ch]);
        }
        if(g[i].size()>1) mxf = max(mxf, to[i]);
    }

    // rep(i,0,10) cout<<to[i]<<" ";
    // cout<<endl;
    ll ans = 0;
    for(int i = 0; i<= min(mxf+10, m); i++){
        ans += max(to[i], mxf);
    }
    if(m > mxf+10){
        ans += 1ll*m*(m+1)/2 - 1ll*(mxf+11)*(mxf+10)/2;
    }
    cout<<ans<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}