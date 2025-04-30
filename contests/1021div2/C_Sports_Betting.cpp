#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repd(i, a, b) for (int i = a-1; i >= b; --i)
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
int k, n, m;

vvi tab;
vi cnt;
int sz=0;
int dp(int i, int cur_det, int next_det){
    int ind = cur_det * 2 + next_det;
    if(i >= sz) return 0;
    if(tab[ind][i]!=-1) return tab[ind][i];


    if(cnt[i]==0) return tab[ind][i] = dp(i+1, next_det,0);
    if(cnt[i]>=4) return tab[ind][i] = 1;
    
    if(next_det) {
        if(cnt[i] >= 2) return tab[ind][i] = 1;
        if(cnt[i]==1) return tab[ind][i] = dp(i+1, 1, 1);
        else return tab[ind][i] = dp(i+1, 1, 0);
    }
    else{
        if(cnt[i]>=2){
            return tab[ind][i] = dp(i+1, 1,0) || dp(i+1, 0,1);
        }
        else{
            return tab[ind][i] = dp(i+1, 0,0);
        }
    }

    return tab[ind][i] = 0;
}

void solve(){
    cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    sort(all(a));
    int st = 0;
    deb(a)
    cnt.clear();
    cnt.pb(1);
    rep(i,1,n){
        if(a[i]==a[i-1]) {
            cnt[st]++;
        }
        else{
            int add = min(3, a[i]-a[i-1]);
            st += add;
            rep(i,0, add){
                cnt.pb(0);
            }
            cnt[st]++;
        }
    }
    cnt.pb(0);
    cnt.pb(0);
    cnt.pb(0);
    sz = cnt.size();
    tab = vvi(4, vi(sz+1, -1));
    deb(cnt)
    cout<<(dp(0, 0, 0)?"YES":"NO")<<endl;
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
