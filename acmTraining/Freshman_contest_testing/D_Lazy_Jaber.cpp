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
#define coutfloat(n,d)     cout << fixed << setprecision(d) << n << endl
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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;

vi a;
vector<vector<int>> nxt;
vi flipped;
bool check(int start, int end, int bit){
    if(bit<0 ) return true;
    deb(bit)
    if (flipped[bit] == -1) {
        if( ((a[start] >> bit) & 1) && end >= nxt[start][bit]){
            flipped[bit] = 1;
        } 
        else flipped[bit] = 0;
        // deb(flipped[bit])
    } else {
        if (flipped[bit] == 1 && ((a[start] >> bit) & 1) == 0 && end >= nxt[start][bit]) return false;
        if (flipped[bit] == 0 && ((a[start] >> bit) & 1) == 1 && end >= nxt[start][bit]) return false;
    }
    if(nxt[start][bit]==n || start == end){
        return check(start, end, bit-1);
    }
    if(nxt[ nxt[start][bit] ][bit] -1>= end){
        
        return check(start, nxt[start][bit]-1, bit-1)&& check(nxt[start][bit], end, bit-1);
    }
    return false;
}


void solve(){
    cin>>n;
    a = vi(n);
    rep(i,0,n) cin>>a[i];

    nxt = vvi(n + 2, vector<int>(35,n));

    flipped = vi(33,-1);
    deb(check(0,2,32));
    deb(flipped)
    for (int i = n - 1; i >= 0; i--)
    {
        nxt[i] = nxt[i + 1];
        for (int j = 0; j <= 32; j++)
        {
            ll bit = 1LL << j;
            if((bit & a[i]) != (bit & a[i + 1]))
                nxt[i][j] = i + 1;
        }
    }
    ll ans = 0;
    for(int i = 0; i<n;i++){
        int lo = i, hi = n - 1;
        int cur = -1;

        while(lo<=hi){
            int md = (hi + lo) / 2;
            flipped = vi(33,-1);
            bool tmp = check(i, md, 31);
            deb(flipped)
            deb(i)
            deb(md) 
            deb(tmp) 
            flipped = vi(33,-1);
            deb(check(i,md,31))
            if(tmp){
                cur = md;
                lo = md + 1;
            }
            else hi = md - 1;
        }
        deb(i)
        deb(cur)
        ans += cur - i +1;
    }
    cout<<ans<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}