#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repd(i, a, b) for (int i = a; i >= b; --i)
#define pb            push_back
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

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
#define deb(...) cerr << "[" << #__VA_ARGS__ << "] = "; _print(__VA_ARGS__); cerr << endl;
#else
#define deb(...)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename... Args>
void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}


int divs(int n, int div=5){
    int ret = 0, fv = div;
    while(n/fv){
        ret += n/fv; 
        fv *= fv;
    }
    return ret;
}

ll sumRng(ll a, ll b){
    if(a<0 || a > b) return 0;
    return b*(b+1)/2 - a*(a+1)/2;
}
ll added(ll l, ll r){
    ll a = 0;
    ll x = 25;
    while( (r / x - (l +  x - 1)/x + 1) != 0){
        a += (r / x + (l +  x - 1)/x + 1);
        x *= 5;
    }
    return a;
}
vi pref(1000);
void solve(){
    int q; cin>>q;
    while(q--){
        ll a,b;
        ll ans = 0;
        cin>>a>>b;
        deb(a)
            deb(pref[b] - pref[a-1])
        cout<<"Brute: "<<pref[b] - pref[a-1]<<endl;
        if(b - a <= 12){
            for(int i = a; i<=b; i++) ans += trailingZeros(i);
        }
        else{
            while(a%5){
                ans += trailingZeros(a++);
            }
            while(b%5!=4){
                ans += trailingZeros(b--);
            }
            deb(a,b)
            int leftZ = trailingZeros(a);
            int rightZ = trailingZeros(b);
            deb(leftZ, rightZ)
            ans += sumRng(leftZ, rightZ)*5;
            deb(ans)
            ans += added(leftZ, rightZ);
        }
        cout<<ans<<endl;
    }
}
ll mod = 1e9 + 7;
ll mpow(ll bs, ll exp) {
    ll res = 1;
    bs = bs;
    while (exp > 0) {
        if (exp & 1)
            res = (res * bs);
        exp = exp >> 1;
        bs = (bs * bs);
    }
    return res;
}

ll fromOneToN(ll n){
    ll ret = 0;
    for(int i = 1; i<15; i++){
        ll c = n / mpow(5, i);
        ret +=  (c * n - mpow(5,i) * c * (c+1)/2 + c);
        deb(n,i, c,ret,mpow(5, i))
    }
    // int c= trailingZeros(n);
    return ret;
}
void solve2(){
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        deb(l,r)
        // cout<<"Brute: "<<pref[r] - pref[l-1]<<endl;
        cout<<fromOneToN(r) - fromOneToN(l-1)<<endl;
    }
}
int main(){
    FASTIO;

    int t = 1;
    // cin >> t;
    rep(i,1,1000){
        pref[i] = pref[i-1] + trailingZeros(i);
        // cout<<i<<": "<<trailingZeros(i)<<" "<<pref[i]<<endl;
    }
    while(t--)
        solve2();

    return 0;
}
