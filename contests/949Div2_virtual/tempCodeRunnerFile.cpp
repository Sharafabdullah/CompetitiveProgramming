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



const ll inf = 1e15+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
ll k,n,m,x;

void binaryRep(ll n){
    string s;
    cout<<"inside bin: ";
    while(n){
        s.push_back( ((int)n%2 + '0'));
        // deb(s)
        // deb((n%2 + '0'));
        // deb(n&1)
        
        n/=2;
    }
    reverse(all(s));
    cout<<s<<endl;
    // cout<<endl;
}

void solve(){
    cin>>x>>m;
    int lastOne = 60;
    for(int i = 34; i>=0; i--){
        if(x & (1ll<<i)) {
            lastOne = i;
            break;
        }

    }
    if(!x) lastOne = -1;
    // deb(lastOne);
    map<ll,ll> mp;
    for (int i = 0; i < 32; i++)
    {
        if((x & (1ll<<i)) == 0){
            ll mask = 0;
            for (int j = 0; j < i; j++)
            {
                mask = mask<<1;
                mask |=1ll;
            }
            // deb(mask)
            // binaryRep(mask);
            if(i >= lastOne){
                ll n1 = (1ll<<i) - x;
                mp[n1] += (1ll<<i);
            } else{
                ll n1 = (mask&x) + 1;
                ll n2 = (1ll<<i) - (mask&x);
                mp[min(n1,n2)] += (1ll<<i);
            }
        }
    }
    ll ans = x;
    for(auto [k,v]: mp){
        // deb(k) deb(v)
        if(k>m) break;
        ans += v;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    // binaryRep(100);
    // binaryRep(16);

    return 0;
}