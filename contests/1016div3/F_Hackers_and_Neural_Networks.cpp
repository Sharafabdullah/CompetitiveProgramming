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
int k, n, m;

void solve(){
    cin>>n>>m;
    vector<string> ans(n);
    vector<bitset<510>> b(m); 
    rep(i,0,n) cin>>ans[i];
    rep(i,0,m){
        rep(j,0,n){
            string str;
            cin>>str;
            if(str == ans[j]) b[i].set(j);
        }
        // cout<<b[i]<<endl;
    }
    deb(n)
    bitset<510> cur;
    
    cur.set(); 
    int availabe_ones = n;
    int cnt = 0;
    int fin_ans = 0;
    bool first = 1;
    vb vis(m);
    while(cnt != n){
        int mx_ones = 0;
        bitset<510> target;
        int ind = -1;
        rep(i,0,m){
            if(vis[i]) continue;
            bitset<510> temp = b[i] & cur;
            int ones = temp.count();
            if (ones > mx_ones) {
                mx_ones = ones;
                target = b[i];
                ind = i;
            }
        }
        deb(mx_ones, ind)
        
        if(mx_ones==0){
            cout<<-1<<endl;
            return;
        }
        vis[ind] = 1;
        if(first) fin_ans += availabe_ones;
        if(!first){
            fin_ans += 2*mx_ones;
        }
        cnt += mx_ones;
        availabe_ones-=mx_ones;
        cur = cur & (~target);
        first = 0;
    }
    cout<<fin_ans<<endl;
    
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
