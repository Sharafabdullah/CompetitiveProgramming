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
int k,n,m;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)) * b;
}

void solve(){
    cin>>n;
    multiset<pi> s;
    vi a(n); for(int& i: a) {cin>>i;s.insert({i,i});}
    ll x = n;
    vll ans(n,1);
    ll l = a[0];
    rep(i,1,n){
        l = lcm(l, a[i]);
    }
    deb(l)
    rep(i,0,n){
        if (a[i]==l){
            cout<<-1<<endl;
            return;
        }
    }
    while(x<=1e9){
        if((*s.begin()).F > x){
            // deb(ans);
            deb(s);
            return;
        }
        ll lst = (*s.begin()).F;
        x+= s.count(*s.begin());
        while(lst == (*s.begin()).F){
            s.insert({lst + (*s.begin()).S, (*s.begin()).S});
            s.erase(s.begin());
        }
    }

    // if(x>1e9){
    //     cout<<-1<<endl;
    // }
    cout<<"ans: "<<endl;
    rep(i,0,n){
        pi p;
        for(auto pr: s){
            if(pr.S == a[i]){
                p = pr;
                
                break;
            }
        }
        cout<<p.first<<" ";
    }
    cout<<endl;

    // cin>>n;
    // vll a(n); for(ll& i: a) cin>>i;
    // ll lo = 0, hi = 1e9;
    // auto calc = [&](ll x){
    //     ll ans = 0;
    //     for(ll el: a){
    //         ans += (x/el) + 1;
    //     }
    //     if(ans==x){
    //         cout<<x<<": ";
    //         deb(ans);
            
    //     }
    //     return ans;
    // };
    // ll x = 1;
    // rep(i,1,100){
    //     // cout<<i<<": ";
    //     calc(i);
    // }
    // // auto cmp = [&](ll md){
    // //     return calc(md) >= calc(md-1);
    // // };
    // // //finds the first true given by cmp (lo). hi is the last false
    // // while(lo<=hi){
    // //     ll md = lo + (hi-lo)/2;
    // //     if(cmp(md)) hi = md - 1;
    // //     else lo = md+1;
    // // }

    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    
    

    return 0;
}