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

const int N = 3e5, M = 10;
int k,n,m;

struct tuples{
    int f, s, t;
    tuples(int f, int s, int t): f(f), s(s), t(t){};
    bool operator<(const tuples& right) const{
        if(f==right.f && s==right.s) return t<right.t;
        else if (f==right.f) return s<right.s;
        else return f<right.f;
    }
};

void solve(){
    cin>>n; vi a(n); for(int& i: a) cin>>i;

    map<tuples, int> common;

    map<pi, int> s1,s2,s3;
    rep(i, 0, n-2){
        s1[{a[i], a[i+1]}]++;
        s2[{a[i], a[i+2]}]++;
        s3[{a[i+1], a[i+2]}]++;
        common[tuples(a[i], a[i+1], a[i+2])]++;
    }
    ll ans = 0;
    // for(auto [k,v]: s1){
    //     // deb(k)
    //     ans += (v-1);
    // }
    // for(auto [k,v]: s2){
    //     // deb(k)
    //     ans += (v-1);
    // }
    // for(auto [k,v]: s3){
    //     // deb(k) deb(v)
    //     ans += (v-1);
    // }
    // ll rep = 0;
    // for(auto [tup, v]: common){
    //     // cout<<tup.f<<" "<<tup.s<<" "<<tup.t<<endl;
    //     // deb(v)
    //     rep += (v-1);
    // }
    // cout<<ans- 3*rep<<endl;
    for(auto [tup, f]: common){
        int a1 = tup.f, a2= tup.s, a3= tup.t;
        ll k = s1[{a1,a2}] - f;
        ans += k * f;
        k = s2[{a1,a2}] - f;
        ans += k* f;
        k = s3[{a2,a3}] -f;
        ans += k* f;
    }
    cout<<ans/2<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}