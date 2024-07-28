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


void solve(){
    cin>>n;
    vi cntNg;
    
    vll a(n); for(ll& i: a) {
        cin>>i;
        // if(cntNg.empty()) cntNg.pb(i);
        // else cntNg.pb(cntNg.back());
        // if(i<0) cntNg.back()++;
        }
    ll c= 0, ans = 0;
    vll ng(n+1), pos(n+1);
    for(int i = n-1; i>=0; i--){
        pos[i] = pos[i+1]; ng[i] = ng[i+1];
        if(a[i]>0) pos[i] += a[i];
        if(a[i]<0) ng[i]+=a[i];
    }
    // deb(pos)
    // deb(ng)
    rep(i,0,n){
        c+=a[i];
        if(c<0){
            while(i+1<n && a[i+1]<=0){
                c+=a[i+1];
                i++;
            }
            if(i<=n && pos[i+1]>=abs(ng[i+1])){
                c = -c;
            }
        }
    }
    cout<<abs(c)<<endl;
}

void solve2(){
    cin>>n;
    vll a(n); for(ll& i: a) cin>>i;
    ll mn = a[0], mx = abs(a[0]);
    rep(i,1,n){
        mn = (mn+a[i]);
        mx = max(mx + a[i], abs(mn));
    }
    cout<<max(abs(mn), abs(mx))<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}