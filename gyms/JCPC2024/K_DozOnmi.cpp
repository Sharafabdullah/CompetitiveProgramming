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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;
vector<vll> pref;

void solve(){
    int q;
    cin>>n>>q;
    string s; cin>>s;
    vvi v(3, vi(n));
    pref = vector<vll>(3, vll(n+1));

    rep(i,0,n){
        if(i%3==0){
            v[0][ i ] = min(abs('d' - s[i]), abs(26-'d'+s[i]));
            v[1][i] = min(abs('o' - s[i]), abs(26-'o'+s[i]));
            v[2][i] = min(abs('z' - s[i]), abs(26-'z'+s[i]));
        }
        else if(i%3==1){
            v[2][ i ] = min(abs('d' - s[i]), abs(26-'d'+s[i]));
            v[0][i] = min(abs('o' - s[i]), abs(26-'o'+s[i]));
            v[1][i] = min(abs('z' - s[i]), abs(26-'z'+s[i]));
        }
        else{
            v[1][ i ] = min(abs('d' - s[i]), abs(26-'d'+s[i]));
            v[2][i] = min(abs('o' - s[i]), abs(26-'o'+s[i]));
            v[0][i] = min(abs('z' - s[i]), abs(26-'z'+s[i]));
        }
    }
    deb(v)
    rep(i,0,n){
        rep(j,0,3){
            pref[j][i+1] = pref[j][i] + v[j][i];
        }
    }

    deb(pref)
    auto get = [&](int l, int r){
        if(l%3==0){
            return pref[0][r+1] - pref[0][l];
        }
        else if(l%3==2) return pref[1][r+1] - pref[1][l];
        else return pref[2][r+1] - pref[2][l];
    };

    while(q--){
        int l,r; cin>>l>>r;
        int dst = r - l + 1;l--, r--;
        deb(l,r)
        deb(dst) 
        if(dst%3==0){
            cout<<get(l,r)<<endl;
        }
        else if(dst%3==1){
            cout<<min(get(l,r-1), get(l+1, r))<<endl;
        }
        else {
            cout<<min({get(l,r-2), get(l+1,r-1), get(l+2, r)})<<endl;;
        }
    }
}

int main(){
    FASTIO;

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
