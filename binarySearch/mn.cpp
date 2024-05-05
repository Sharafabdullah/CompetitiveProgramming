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
void _print(ld t) {cerr<<setprecision(12) << t;}
void _print(double t) {cerr<<setprecision(9) << t;}
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

vvi g(M);
vi v(N);

void smallestElmInRotatedArr(){
    vi v = {43,3,3,4,6,8,231,2432,213,543,12,321,51,};
    sort(all(v)); rotate(v.B, v.B+5,v.E);
    deb(v);
    int lo = 0, hi = sz(v);
    while(lo<=hi){
        int md = lo + (hi-lo)/2;
        if(v[md]<=v[0]) hi = md -1;
        else lo = md+1;
    }
    deb(find(all(v), 3)- v.B);
    deb(v[lo]); deb(lo);
}

// bool cmp(int md, int target, vi& v){
//     return v[md]>=target;
// }
int lowBound(){
    vi v = {2,3,4,6,10,10,10,34,42};
    //want to find the first true;
    int target = 10;

    ll lo = 0, hi = v.size()-1;
    auto cmp = [&](ll md, ll t){
        return v[md]>=t;
    };
    
    while(lo<=hi){
        ll md = lo + (hi-lo)/2;
        if(cmp(md,target)) hi = md - 1;
        else lo = md+1;
    }
    return lo;
}

void perfectSquares(){
    double x = 5, lo = 0, hi = x;
    while(hi-lo > eps){
        ld md = (lo+hi)/2;
        if(md*md>x) hi = md;
        else lo = md;
    }
    deb(lo);
    deb(sqrt(x));
}

void incDecArr(){
    vi v = {43,535,4214,23,2,1};
    sort(all(v),greater());
    // deb(v);
    int lo = 0, hi = sz(v)-1;
    while(lo<=hi){
        int md = lo + (hi-lo)/2;
        if(md==sz(v)-1 || v[md+1]<=v[md]) hi = md-1;
        else lo = md+1;
    }
    deb(v[lo]);
}
void solve(){
    // smallestElmInRotatedArr();
    
    deb( lowBound());
    // perfectSquares();
    // incDecArr();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}