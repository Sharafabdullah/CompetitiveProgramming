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

const int N = 5e4+10, M = 2e5+10;

int k,n,m;


int sz = 175;
struct query{
    int l,r,ind,b;
    query(){};
    query(int l, int r, int ind):l(l), r(r), ind(ind){
        b= l/sz;
    }
    bool operator<(const query& other) const{
        if(b==other.b) return r < other.r;
        return b < other.b;
    }
};
//! Need initilization!
vector<query> qu;
vi freq, v; vll ans;
ll cur = 0;

void init(int n, int q){
    qu = vector<query>(q);
    ans = vll(q);
    freq = vi(1e6+100);
    sz = sqrt(n) + 10;
    // v = vi(n);
    cur = 0;
}

void add(int ind){
    if(!freq[v[ind]])cur++;
    freq[v[ind]]++;
}

void remove(int ind){
    freq[v[ind]]--;
    if(!freq[v[ind]]) cur--;
}

void mo_process(){
    sort(qu.begin(), qu.begin()+k);
    int l = 1, r = 0;
    rep(i,0,k){
        while(l < qu[i].l) remove(l++);
        while(l > qu[i].l) add(--l);
        while(r < qu[i].r) add(++r);
        while(r > qu[i].r) remove(r--);
        ans[qu[i].ind] = cur;
    }
}

void solve(){
    cin>>n;
    v = vi(n);
    rep(i,0,n) {cin>>v[i];}
    cin>>k;
    init(n,k);
    rep(i,0,k){
        int l,r; cin>>l>>r;
        qu[i] = query(--l,--r,i);
    }
    mo_process();
    rep(i,0,k){
        cout<<ans[i]<<endl;
    }
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