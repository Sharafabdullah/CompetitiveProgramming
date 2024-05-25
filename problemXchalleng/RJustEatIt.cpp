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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n;
    vector<ll> v(n); for(ll& i: v) cin>>i;
    ll sum=0, mx = v[0], prev = v[0],num = 1;
    bool f = 0;
    rep(i,0,n) sum+=v[i];
    rep(i,1,n){
        if(prev+v[i]>mx){
            mx = prev+v[i];
            num++;
        }
        // mx = max(mx, prev+v[i]);
        // prev = max(prev+v[i], 0ll);
        if(prev+v[i] <= 0){
            f = 1;
            prev = 0;
        } else {prev = prev+v[i];}
    }
    // if(sum>mx) cout<<"YES"<<endl;
    // else cout<<"NO"<<endl;
    deb(num)
    deb(mx)
    deb(sum)
    if(sum > mx ) cout<<"YES"<<endl;
    else if(sum==mx && num==n && v.back()!=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

void solve2(){
    cin>>n;
    ll sum = 0;
    vi a(n);
    bool f = 0, allpos = 1;
    rep(i,0,n){
        cin>>a[i];
        sum+= a[i];
        if(sum<=0) allpos = 0;
    }
    sum = 0;
    rep(i,n,0){
        sum+=a[i];
        if(sum<=0) allpos= 0;
    }
    if(allpos) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    // while(t--) solve2();
    

    return 0;
}