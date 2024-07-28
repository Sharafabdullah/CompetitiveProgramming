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

const int N = 1e5 + 10, M = 10;
int k,n,m;
vvi g(N);
vi w(N,1);

void getWeight(int i){
    if(g[i].size()==0) {
        return;
    }
    for(int ch: g[i]){
        getWeight(ch);
        w[i] += w[ch];
    }
}

void solve(){
    // w = vi(N, 1);
    cin>>n>>k;
    int a, b;
    g = vvi(n);
    rep(i,0,n-1){
        cin>>a>>b;
        if(a>b) swap(a,b);
        a--; b--;
        g[a].pb(b);
    }
    // getWeight(0);
    ll lo = 1, hi = n;
    auto cmp = [&](ll md){
        int res=0;

        auto dfs = [&](auto self, int v, int f) -> int{
            int sz=  1;//init size of the comp
            for(int ch: g[v]){
                if(ch==f) continue; //to not go back to father
                sz += self(self, ch,v);
            }
            if(sz>=md && v!=f){
                res++; sz=0; //to start counting again
            }
            return sz;
        };
        int t = dfs(dfs,0,0);
        //if connected comp is bigger than k we can join the k+1 comp with the root to form 
        // a sufficent comp
        if(res>k || (res==k && t>=md)) return false;
        return true;
    };
    //finds the first true given by cmp (lo). hi is the last false
    while(lo<=hi){
        ll md = lo + (hi-lo)/2;
        if(cmp(md)) hi = md - 1;
        else lo = md+1;
    }
    cout<<hi<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}