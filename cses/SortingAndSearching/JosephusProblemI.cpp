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

const int N = 2e5+1, M = 10;
int k,n,m;


void solve(){
    cin>>n;
    int cnt = 0;
    if(n==1){
        cout<<1<<' ';
        return;
    }
    bitset<N> b;
    for(int i= 1; ; i = (i+2)%n){
        if(++cnt>n) break;
        while(b[i]) i++;
        b[i] = 1;
        cout<<i+1<<' ';
        while(b[i+1]) i++;
    }
    
}

void solve2(){
    cin>>n;
    set<int> s;
    rep(i,1,n+1) s.insert(i);
    auto cur = s.begin(); cur++;
    while(!s.empty()){
        rep(i,0,2){
            cur++;
            if(cur==s.end()) cur = s.begin();
        }
        s.erase(cur);
        cout<<*cur<<' ';
    }
}
void solve3(){
    cin>>n;
    vi a(n); rep(i,0,n) a[i] = i+1;
    // deb(a);
    while(a.size()>1){
        vi next;
        // deb(a);
        rep(i,0,a.size()){
            if(i%2==0) next.pb(a[i]);
            else cout<<a[i]<<' ';
        }
        // deb(next)
        if(a.size()%2){
            a.clear();
            a.pb(next.back()); next.pop_back();
            for(int i: next) a.pb(i);
        } 
        else a = next;
    }
    cout<<a[0]<<' ';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve3();
    // while(t--) solve2();
    // while(t--) solve();
    

    return 0;
}