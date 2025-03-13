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

struct Compare {
    bool operator()(const pi& p1, const pi& p2) const {
        return p1.second < p2.second;
    }
};

void solve(){
    cin>>n>>k;
    multiset<pi> fb;
    multiset<pi>  sb;
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        if(a>=b) fb.insert({a,b});
        else sb.insert({a,b});
    }
    ll ans = 0;
    // deb(fb)
    // deb(sb)
    while(k>0){
        pi p1,p2;
        deb(ans)
        deb(k)
        if(fb.empty()){
            p1.first = p1.second = inf;
        } else{
            p1 = *fb.begin();
        }
        if(sb.empty()){
            p2.first = p2.second = inf;
        } else {p2 = *sb.begin();}

        if (p1.first == inf && p2.first == inf){
            cout<<-1<<endl;
            return;
        }
        auto [f1,s1] = p1;
        auto [f2, s2] = p2;
        if(s1 < f2 || (s1 == f2 && f1 < s2)){
            fb.erase(fb.begin());
            if(s1 == 1 && f1 == 1){
                ans += 1;
                k-=2;
                continue;
            }
            k--;
            ans += min(s1,f1); f1--;
            if(f1>=s1){
                fb.insert({f1,s1});
            }
            else{
                sb.insert({f1,s1});
            }
        }
        else{
            sb.erase(sb.begin());
            if(s2 == 1 && f2 == 1){
                ans += 1;
                k-=2;
                continue;
            }
            k--;
            ans+= min(s2,f2); s2--;
            if(f2>=s2){
                fb.insert({f2,s2});
            }
            else{
                sb.insert({f2,s2});
            }
        }
    }  
    cout<<ans<<endl;
    
}

void solve2(){
    cin>>n>>k;
    vector<pi> a(n); rep(i,0,n) cin>>a[i].first >> a[i].second;
    vvi dp(n+1, vi(k+1,inf));
    dp[0][0] = 0;
    rep(i,1,n+1){
        auto [f,s] = a[i-1];
        deb(f) deb(s)
        for(int j = k; j>=0; j--){
            dp[i][j] = dp[i-1][j];
            if(f == 0 && s == 0 || j < min(f,s)) continue;
            dp[i][j] = min(min(dp[i][j], dp[i][j+1]), dp[i-1][j-min(f,s)] + min(f,s));
            if(f < s){
                s--;
            } else f--;
        }
    }
    deb(dp)
    if(dp[n][k]==inf){
        cout<<-1<<endl;
    } else cout<<dp[n][k]<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        // solve();
        solve2();
    }
    

    return 0;
}