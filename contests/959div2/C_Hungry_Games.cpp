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

const ll inf = 1e16+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
ll k,n,m;


void solve(){
    cin>>n>>m;
    vi a(n); rep(i,0,n) cin>>a[i];
    vll sum(n);
    ll ans = n*(n+1)/2;
    ll z = 0;;
    if(a[0]>m) {z++; sum[0]=0;}
    else sum[0]=a[0];
    rep(i,1,n){
        if(sum[i-1]+a[i]>m){
            sum[i]=0;
            z += ((ll)(i-1) * (i))/2;
            // if(a[i]<=m) z--;
        }
        else{
            sum[i] = sum[i-1]+ a[i];
        }
    }
    deb(ans)
    deb(z)
    cout<<ans -z <<endl;
}

void solve2(){
    cin>>n>>k;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    vll sum(n+1); 
    map<int,int> mp;
    rep(i,1,n+1){
        if(a[i-1]>k){
            sum[i]=0;
            mp[0]++;
        } 
        else{
            sum[i] = sum[i-1]+a[i-1];
            sum[i]%=(k+1);
            mp[sum[i]]++;
        }
        
    }
    ll b = (n*(n+1))/2;
    ll lv=0,c;
    ll prev = 0;
    rep(i,0,n){
        
        
    }

    cout<<b - lv<<endl;
}

void solve3(){
    cin>>n>>k;
    vi a(n); rep(i,0,n) cin>>a[i];
    vll sum(n+1); 
    map<ll,int> mp;
    ll lv = 0;
    ll ans = n*(n+1)/2;
    mp[0]++;
    set<int> sp;
    rep(i,1,n+1){
        if(a[i-1]>k){
            lv += i;
            mp.clear();
            mp[0]++;
            sum[i]=0;
        }
        else{
            sum[i] = (sum[i-1]+a[i-1]);
            if(sum[i-1]>k){
                lv += i;
                mp.clear();
                mp[0]++;
                sum[i]=0;
            }
            else{
                ll c= mp[sum[i]];
                lv += c*(c+1)/2;
                mp[sum[i]]++;

            }
        }
    }
    deb(lv)
    // deb(sum)
    // deb(lv)
    // rep(i,0,n){
    //     deb(sum[i])
    //     if(sp.count(i)) continue;
    //     ll c = mp[sum[i]];
    //     deb(c)
    //     lv += c*(c-1)/2;
    //     mp[sum[i]]--;
    // }
    cout<<ans-lv<<endl;
}
void solve4(){
    cin>>n>>k;
    vi a(n); rep(i,0,n) cin>>a[i];
    int l=0, r=0;
    ll cur = 0;
    ll ans = n*(n+1)/2,ex=0;
    deb(a)
    while(r<n){
        if(a[r]>k){

        }
        cur+=a[r];
        deb(r)
        // int ol = l;
        if(cur>k){
            ll cnt =0;
            while(l<=r&&cur>k){
                cur-=a[l];
                l++;
                cnt++;
            }
            ex += (cnt)*(cnt+1)/2;
        }
        // l = ol;
        // if(a[r])
        r++;
    }
    deb(ex)
    cout<<ans-ex<<endl;
}
void solve5(){
    cin>>n>>k;
    vll a(n); rep(i,0,n) cin>>a[i];
    vll sum(n+1); 
    map<ll,int> mp;
    ll lv = 0;
    ll ans = n*(n+1)/2;
    ll z = 0;
    rep(i,1,n+1){
        if(sum[i-1]+a[i-1]>k){
            z++;
            // lv += z*(z+1)/2;
            sum[i]=0;
            mp[0]++;
        }
        else{
            sum[i] = (sum[i-1]+a[i-1])%mod;
            mp[sum[i]]++;
        }
    }
    for(auto [k,v]: mp){
        deb(k) deb(v)
        lv += (ll)v*(v+1)/2;
    }
    cout<<ans - lv<<endl;
}

void solve6(){
    cin>>n>>k;
    vll a(n); rep(i,0,n) cin>>a[i];
    a.pb(inf);
    n++;
    vll psum(n+1);
    rep(i,1,n+1){
        psum[i] = psum[i-1]+a[i-1];
    }
    vll dp(n);
    deb(a)
    deb(psum)
    for(int i = n-2; i>=0; i--){
        int j = upper_bound(psum.begin()+i, psum.end(), k + psum[i])- psum.begin()-1;
        deb(i) deb(j)
        if(j == n-1){
            dp[i] = j - i;
        }
        else{
            dp[i] = dp[j+1] + j-i;
        }
    }
    ll ans = 0;
    for(ll i: dp) ans+=i;
    cout<<ans<<endl;
}
int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    // while(t--) solve();
    // while(t--) solve2();
    // while(t--) solve3();
    // while(t--) solve4();
    // while(t--) solve5();
    while(t--) solve6();

    return 0;
}