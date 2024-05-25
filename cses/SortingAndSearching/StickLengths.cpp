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



const ll inf = 1e16;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n; 
    ll sum=0; ll mx = 0;
    vector<int> p(n); for(auto& i: p) {cin>>i; sum+=i; mx= max(mx, (ll)i);}
    ll lo = 0, hi = 2*mx, ans = inf, lastDiff = ans;

    auto cmp = [&](ll md){
        ll diff= 0; 
        rep(i,0,n) diff+=abs(p[i]-md);
        // deb(md)
        // deb(diff)
        ans = min(diff,ans);
        // deb(lastDiff)
        // cout<<endl;
        return diff;
    };
    //finds the first true given by cmp
    // cmp(hi);
    while(lo<=hi){
        ll md = lo + (hi-lo)/2;
        // deb(md)
        // deb(ans)
        if(cmp(md)>cmp(md-1)) hi = md - 1;
        else lo = md+1;
    }
    // cmp(lo);

    cout<<ans<<endl;
}

void solve2(){
    cin>>n; vi v(n); for(auto& i: v) cin>>i;
    sort(all(v));
    ll ans = 0;
    rep(i,0,n){
        ans+= abs(v[i]-v[n/2]);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve2();
    // while(t--) solve();
    

    return 0;
}