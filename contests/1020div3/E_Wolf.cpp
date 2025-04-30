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

void solve(){
    cin>>n>>k;
    vi v(n+1);
    map<int,int> mp_ind;
    rep(i,1,n+1){
        cin>>v[i];
        mp_ind[v[i]] = i;
    }
    deb(v)
    while(k--){
        int a,b,t;
        cin>>a>>b>>t; 
        int t_ind = mp_ind[t];
        if(t_ind < a || t_ind > b){
            cout<<-1<<" ";
            continue;
        }
        ll lo = a, hi = b;
        auto cmp = [&](ll md){
            return md >= t_ind;
        };
        //finds the first true given by cmp (lo). hi is the last false
        vector<pair<int,char>> move;
        while(lo<=hi){
            int md = (lo + hi)/2;
            if(md == t_ind) break;
            if(cmp(md)){ hi = md - 1; move.pb({md, 'l'});}
            else {lo = md+1; move.pb({md, 'r'});}
        }
        int want_g = 0, want_l = 0;
        deb(a,b)
        deb(move)
        int avail_g = n - t, avail_l = t - 1;
        for(auto [ind, c]: move){
            deb(ind, c, v[ind])
            if(c=='l') avail_g--;
            else avail_l--;
            if(c=='l' && v[ind] < t){
                want_g++;
            }
            if(c=='r' && v[ind] > t){
                want_l++;
            }
        }
        deb(want_g, want_l)
        if(want_g > n - t || want_l >= t || avail_g < 0 || avail_l < 0){
            cout<<-1<<" ";
        } else cout<<2 * max(want_g, want_l)<<" ";
    }
    cout<<endl;
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
