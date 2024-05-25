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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
ll k,n,m;

ll mpow(ll bs, ll exp) {
    ll res = 1;
    bs = bs % mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * bs) % mod;
        exp = exp >> 1;
        bs = (bs * bs) % mod;
    }
    return res;
}

ll inverse(ll b){
    return mpow(b, mod-2); //fermat's little theorem b^(m-1) = 1 mod(m) when m is prime
                     // -> b^(m-2) == b^(-1) mod(m)
}

ll mul(ll a, ll b){
    return ((a%mod) * (b%mod)+mod)%mod;
}

ll divide(ll a, ll b){
    return mul(a, inverse(b)); 
}
ll add(ll a, ll b){
    return (a%mod + b%mod)%mod;
}
ll subtract(ll a, ll b){
    return (a%mod - b%mod + mod)%mod;
}


ll phi(ll n){
    //return the number of coprimes
    int ans = n; //all the numbers
    for(ll i= 2; i*i <= n; i++ ){
        if(n%i == 0){
            //this means that we found a prime phi(n) = phi(p1^k1) * phi(p2^k2) ...
            while(n%i==0) n/=i;
            ans -= ans/i; //the number of multiples of this prime 
        }
    }
    if(n>1) ans -= ans/n;
    return ans;
}


void solve(){
    cin>>n>>k; vector<ll> p(k); for(auto& i: p) cin>>i;
    vector<set<ll>> vlcm(k);
    // vlcm[0] = p;
    // for (ll i = 1; i < k; i++)
    // {
    //     ll s = 0, e = i;
    //     while(e<vlcm[0].size()){
    //         ll elm = 1;
    //         for(ll j = s; j<=e; j++){
    //             elm = ( elm * vlcm[0][j]);
    //         }
    //         vlcm[i].pb(elm);
    //         e++; s++;
    //     }
    // }
    sort(all(p));
    do {
        ll elm = 1;
        rep(i,0,k){
            elm *= p[i];
            vlcm[i].insert(elm);
        }
    } while( next_permutation(all(p)));
    deb(vlcm)
    ll sign = 1, ans = 0;
    for (ll i = 0; i < k; i++)
    {
        for(ll elm: vlcm[i]){
            if(sign==1) ans = ans + n/ elm;
            else ans = (ans - n/ elm); 
        }
        sign = -sign;
    }
    cout<<ans<<endl;
}
void solve2(){
    cin>>n>>k;
    vector<ll> a(k); for(auto& i: a) cin>>i;
    ll ans = 0;
    for (int i = 0; i < (1ll<<k); i++)
    {
        vector<ll> v;
        for (int j = 0; j < k; j++)
        {
            if(i & (1ll<<j)) v.pb(a[j]);
        }
        ll prod = 1;
        for (int j = 0; j < v.size(); j++)
        {
            if(prod> n/v[j]){
                prod = n+1;
                break; //we reached a point where n/ prod == 0
            }
            prod *= v[j];
        }
        // deb(prod);
        if(v.size()%2) ans += n/prod;
        else ans -= n/prod;
    }
    ans+=n;
    cout<<ans<<endl;
    
}
void solve3(){
    ll n,k;
    cin>>n>>k;
    ll a[k];
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    for(int i=0;i<(1ll<<k);i++)
    {
        vll v;
        for(int j=0;j<k;j++)
        {
            if((i&(1<<j))!=0)
            {
                v.pb(a[j]);
            }
        }
        ll prod=1;
        for(int j=0;j<v.size();j++)
        {
            if(prod>n/v[j])
            {
                prod=n+1;
                break;
            }
            prod*=v[j];
        }
        if(v.size()%2==0) ans-=n/prod;
        else ans+=n/prod;
    }
    ans+=n;
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    n = 3000;
    // cout<< n/17 + n/71 + n/37 + n/11 - n/1207 - n/2627 - n/407<<endl;
    //while(t--) solve(); // correct but tle
    solve2();
    // solve3();

    return 0;
}