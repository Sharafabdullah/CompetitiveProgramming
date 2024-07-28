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
    cin>>n;
    vi a(n); rep(i,0,n) cin>>a[i];
    int cnt =0;
    for (int i = 1; i < n; i+=2)
    {
        if(a[i]%2 && (a[i-1]%2==0) || (a[i]%2==0 && a[i-1]%2!=0)){
            ans+=2;
        }
        if(gcd(a[i], a[i-1])==1) cnt++;
    }
    if(a[n-1]%2!=0 && (a[n-2]%2==0) || (a[n-1]%2==0 && a[n-2]%2!=0)){
        cout<<"NO"<<endl;
        return;
    }
    if(n%2){
        if(gcd(a[n-1], a[n-2])==1) cnt++;
    }
    cout<<"YES"<<endl;
    cout<<cnt<<endl;
}

void solve2(){
    cin>>n;
    vll a(n); rep(i,0,n) cin>>a[i];
    ll g=a[0];
    rep(i,0,n){
        g = gcd(g, a[i]);
    }
    if(g>1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
    }
    int cnt = 0;
    ll m1 = a[0]-a[1], m2 = a[0]+a[1];
    g = gcd(m1, m2);
    for (int i = 1; i < n; i+=2)
    {
        if(gcd(g, a[i])>1 && gcd(g,a[i-1])>1) continue;
        ll m = a[i-1]+a[i];
        if(gcd(m, g)>1){
            g= gcd(m,g);
            cnt++;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    if(n%2){
        if(gcd(g, a[n-1])>1) {}
        else{
            if(gcd(g, a[n-1]+a[n-2])>1){
                cnt++;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<cnt<<endl;
}
int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--) solve();
    // solve2();
    

    return 0;
}