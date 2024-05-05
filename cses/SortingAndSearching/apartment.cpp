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
int k,n,m,a;

vvi g(M);
vi v(N);

void solve(){
    cin>>n>>m>>k;
    vi app(n), apart(m); rep(i,0,n) cin>>app[i];
    rep(i,0,m) cin>>apart[i];
    sort(all(app)); sort(all(apart));
    int i=0,j=0, cnt= 0;
    while(i<n){
        while(j<m && apart[j]< app[i]-k)j++;
        if(j==m) break;
        // deb(apart[j]);
        // deb(app[i]);
        // cout<<endl;
        if(abs(apart[j]-app[i])<=k){
            i++;
            j++;
            cnt++;
        } else i++;
    }
    cout<<cnt<<endl;

    // multiset<int> aprt;
    // rep(i,0,n) cin>>app[i];
    // rep(i,0,m) {cin>>a;aprt.insert(a);}
    // sort(all(app));
    // int i=0,j=0,ans=0;
    // // deb(app);
    // vb taken(n);
    // // deb(aprt);
    // // deb(app);
    // rep(i,0,n){
    //     auto lo = lower_bound(aprt.begin(), aprt.end(), app[i]);
    //     // deb(app[i]);
    //     // deb(*lo) 
    //     if(lo!=aprt.begin()) lo--;
    //     if(*lo<=app[i]+k && *lo>=app[i]-k){ans++; aprt.erase(lo); continue;}
    //     if(lo!=aprt.end()) lo++;
    //     // deb(*lo)
    //     if(*lo<=app[i]+k && *lo>=app[i]-k){ ans++;aprt.erase(lo); continue;}
    // }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}