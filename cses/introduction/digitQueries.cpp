#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define mp            make_pair
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
const ll mod = 2e18;
int N = 30, M = N;


vi g(N);
vector<ll> a(N);
ll mpow(ll bs, ll exp) {
    ll res = 1;
    bs = bs % mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * bs) % mod;
        exp = exp >> 1;
        bs = (bs * bs) % mod;
    }
    return res;
}


void solve(){
    ll k,n,m,i=1;
    cin>>k;
    for(; i<20; i++) if(k<=a[i]) { break;};
    ll start = a[i-1]+1, end = a[i];
    deb(start);
    deb(end);
    deb(i);
    ll lo = mpow(10,i-1), hi = mpow(10,i)-1, is = i,pos=0,md;
    while(lo<=hi){
        md = lo + (hi-lo)/2;
        pos = start+(i)*(md-start);  
        if(k>=pos) {
            lo = md+1;
            }
        else if(k<pos) hi = md-1;
        // deb(md);
        // deb(pos);
        // deb(hi);
        // deb(lo);
        // else break;
    }
        string myNum = to_string(hi);
        deb(myNum);
        deb(pos);
        deb(abs(k-pos));
    // cout<<pos<<endl;
    // cout<<lo<<endl;
    // deb(hi);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("Error.txt","w",stderr);
// #endif
    int t= 1;
    ll sum = 9; a[1] = 9;
    rep(i,2,16){

        ll lvl = (9L*(i*10)* mpow(10,i-2));
        sum+=lvl;
        a[i]= sum;
        // deb(mpow(10,i-2));
        // deb(lvl);
        // deb(sum);
    }
    cin>>t;
    while(t--) solve();
    

    return 0;
}