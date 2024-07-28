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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
ll k,n,m;
vll dm(3);
ll cntWays(ll x, ll y, ll z){
    // deb(x) deb(y) deb(z)
    // if(x*y*z!=k) return -inf;
    ll ans = (dm[0] - x + 1)*(dm[1]-y+1)*(dm[2]-z+1);
    deb(ans)

    return ans;
}

void divisors(ll n, vector<ll>& div) 
{ 
    for (ll i=1; i*i<=n; i++) 
    { 
        if (n%i == 0) 
        { 
            div.pb(i);
            if(i*i != n) div.pb(n/i);
        } 
    } 
}
void solve(){
    cin>>dm[0]>>dm[1]>>dm[2]>>k;
    sort(all(dm));
    ll ans = 0, curK = k;
    vll div;
    // divisors(k, div);
    for (ll x = 1; x <= dm[0]; x++)
    {
        if(curK % x==0){
            ll tmp1 = curK;
            curK/=x;
            for (ll y = 1; y <= dm[1]; y++)
            {
                if(curK % y==0){
                    // ll tmp2 = curK;
                    curK /=y;
                    if(curK <= dm[2]) ans = max(ans, cntWays(x,y,curK));
                    curK *=y;
                }
            }
            curK = tmp1;
        }
        curK = k;
    }
    cout<<ans<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}