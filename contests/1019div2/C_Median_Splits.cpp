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
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(const char* s) {cerr << s;}


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename... Args>
void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
ll k, n, m;

bool can(vll& a){
    int i1 = -1, i2 = -1;
    int s = 0, b = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i]<=k) s++;
        else b++;
        if(s >= b) {
            i++;
            if(s > b && a[i]>k) i++;
            i1 = i-1;
            break;
        }
    }
    s = 0, b= 0;
    for(int i = i1 + 1; i < a.size(); i++){
        if(a[i]<=k) s++;
        else b++;
        if(s >= b) {
            i2 = i;
            break;
        }
    }
    deb(a)
    deb(i1,i2)
    if(i1 != -1 && i2 != -1 && i2 < (a.size()-1)) return 1;
    else return 0;
}

void solve(){
    cin>>n>>k;
    vll a(n); rep(i,0,n) cin>>a[i];
    ll b = 0, s= 0;
    ll st = -1, en = -1;
    rep(i,0,n){
        if(a[i]<=k) s++;
        else b++;
        if(s >= b) {st = i; break;}
    }
    s = 0, b= 0;
    for(int i = n -1; i >= 0; i--){
        if(a[i]<=k) s++;
        else b++;
        if(s >= b) {en = i; break;}
    }
    deb(s,b)
    bool ok = can(a);
    reverse(all(a));
    ok |= can(a);
    if((st != -1 && en != -1 && st < en - 1) || ok){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
