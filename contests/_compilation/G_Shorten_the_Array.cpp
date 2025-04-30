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

void solve(){
    cin>>n>>k;
    vll a(n);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        if(a[i]>=k){
            cout<<1<<endl;
            return;
        }
    }
    deb(n)
    vector<pair<int,int>> av_pair(n,{-inf,inf});

    rep(i,0,32){
        if(k & (1<<i)){
            deb(k)
            vi pref(n);
            int cnt = 1, prev_end = 0, prev_st = 0;
            pref[0] = (a[0] & (1<<i)) ? 1 : 0;
            for(int j = 1; j < n; j++){
                pref[j] = (pref[j-1] + ((a[j] & (1<<i)) ? 1 : 0)) & 1;
                if(pref[j]!=pref[i]){
                    prev_end = i-1;
                    prev_st = i - cnt;
                    cnt = 0;
                }
                else{
                    cnt++;
                }
                av_pair[j].first = max(av_pair[j].first, i - prev_end);
                av_pair[j].second = min(av_pair[j].second, i - prev_st);
            }
            deb(i, pref)
        }
    }
    int ans = inf;
    rep(i,0,n){
        auto [f,s] = av_pair[i];
        if(f==-inf || s == inf || f > s) continue;
        ans = min(ans, f);
    }
    cout<<(ans==inf?-1:ans)<<endl;
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
