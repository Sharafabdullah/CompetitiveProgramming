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

const int N = 200, M = 10;
int k, n, m;

void solve(){
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }

    vll nodes(N), pref(N+1);
    nodes[1] = pref[1] = 1;
    nodes[2] = 6, pref[2] = 7;

    rep(i,3,N){
        int out = 3 * 6 + 2 * (nodes[i-1]-6);
        int x = (out - 6) / 2;
        // deb(i, out)
        nodes[i] = x + 6;
        pref[i] = pref[i-1] + nodes[i];
    }

    int lvl = 2;
    vll direct(1e6), ans(1e6);

    direct[1] = ans[1] = 1;
    rep(i,2,8) direct[i] = 1;
    ll total = 6;

    while(lvl<N){
        set<int> curEdge;
        int minus = lvl - 1;
        int x = pref[lvl] - (minus - 1);

        while(pref[lvl - 1] < x){
            curEdge.insert(x);
            x-= minus;
        }
        // deb(curEdge)
        int base = nodes[lvl];
        // deb(lvl, base)

        for(int i = pref[lvl-1]+1; i<=pref[lvl];i++){
            ans[i] = ((2 * total)%mod + mod - direct[i]) %mod ;
        }

        total = 0;
        for(int i = pref[lvl-1]+1; i<=pref[lvl]; i++){
            if(curEdge.count(i)){
                if(i==pref[lvl-1]+1){
                    // deb(lvl, pref[lvl+1])
                    direct[pref[lvl+1]] = ans[i];
                    direct[pref[lvl+1]]%=mod;
                    direct[base + i] += ans[i];
                    direct[base + i] %= mod;
                    direct[base + i + 1] += ans[i];
                    direct[base + i + 1] %= mod;
                    
                    total = total + (3*ans[i])%mod;
                    if(total>=mod) total%=mod;
                }
                else{
                    direct[base + i] += ans[i];
                    direct[base + i] %= mod;
                    direct[base + i + 1] += ans[i];
                    direct[base + i + 1] %=mod;
                    direct[base + i + 2] += ans[i];
                    direct[base + i + 2] %= mod;
                    total = total + (3*ans[i])%mod;
                    if(total >= mod) total %= mod;
                    base++;
                }
            }
            else{
                direct[base + i] += ans[i];
                direct[base + i] %= mod;
                direct[base + i + 1] += ans[i];
                direct[base + i + 1] %= mod;
                total = total + (2*ans[i])%mod;
                if(total>=mod) total %= mod;
            }
        }
        lvl++;
    }
    // rep(i,1,10) cout<<ans[i]<<" ";
    cout<<ans[n]<<endl;
}

int main(){
    FASTIO;

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
