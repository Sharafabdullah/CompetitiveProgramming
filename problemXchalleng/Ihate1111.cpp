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

vector<ll> v(12);
bool dp(ll n){
    deb(n)
    if(n==0) return 1;
    if(n<11) return 0;
    rep(i,1,12){
        if(n%v[i]== n) break;
        if(dp(n%v[i])) return 1;
    }
    return 0;
}
void print(int ind, ll cur){
    // if(cur>100) return;
    rep(i,ind, 12){
        cur += v[i];
        if(cur> 10000) break;
        print(i, cur);
        deb(cur)
        cur -= v[i];
    }
}
void solve(){
    cin>>n;
    // cout<<(dp(n)? "YES":"NO")<<endl;;
    // print(0, 0);
    bool f = 0;
    while(n>=0){
        if(n%11==0) {
            f= 1;
            break;
        }
        n-= 111;
    }
    cout<<(f? "YES":"NO")<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    v[0] = 1;
    rep(i,1,12){
        v[i] = (v[i-1]*10 + 1);
    }
    rep(i,6000,12000){
        cout<<i<<" ";
    }
    cin>>t;
    while(t--) solve();
    

    return 0;
}