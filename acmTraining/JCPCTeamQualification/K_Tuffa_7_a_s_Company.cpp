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

const ull inf = ULLONG_MAX;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;
vi v;
template <class T> struct SegmentTree{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vector<T> seg;
    // vi org;
    T skip = 0;
    int sz = 1;
    T merge(T x, T y){
        return max(x, y);
    }
    void build(int l, int r, int node, vi& org){
        if(l==r){ if(l<org.size()) seg[node]=org[l]; return;}

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int node, T val, int ind){
        if(l==r){
            seg[node] = val;
            return;
        }

        if(ind<=md) update(l, md, L, val, ind);
        else update(md+1, r, R, val, ind);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    T query(int l, int r, int node, int lq, int rq, int val){
        if(l==r){
            if(l >= v.size() || l < lq) return -1;
            // deb(v[l])

            if(v[l] >= val) return l;
            else return -1;
        }
        int left = query(l, md, L, lq,rq, val);
        if(seg[L]>=val && left != -1){
            return left;
        }
        else return query(md+1, r, R, lq, rq, val);
    }

public:
    SegmentTree(vi& arr){
        while(sz<(int)arr.size()) sz*=2;
        seg = vector<T>(sz*2,skip);
        // this->org = org;
        build(0, sz-1, 0, arr);
    }
    SegmentTree(){
    }
    
    void update(int ind, T val){
        update(0, sz-1, 0, val, ind);
    }

    T query(int l, int r, int val){
        // deb(val)
        return query(0, sz-1, 0, l, r, val);
    }
#undef L
#undef R
#undef md
};

ll dp[N];
ull dfs(int ind, ull taken, SegmentTree<ll>& sg, map<int, ull>& min_taken){
    if(ind>=n) return 0;

    if (min_taken.count(ind) && taken >= min_taken[ind]) {
        return dp[ind];
    }
    // min_taken[ind] = taken;
    ull ans = dfs(ind+1, taken, sg, min_taken);
    if(taken > ULLONG_MAX / v[ind]*(ld)1.0) { 
        return dp[ind] = ans;
    }

    ull looking = taken * v[ind];
    deb(ind) deb(taken) deb(looking)
    int nind = sg.query(ind+1, n-1, looking);
    if(nind!=-1) ans = max(ans, dfs(nind, looking, sg, min_taken) + 1);
    return dp[ind] = ans;
}  


void solve(){
    cin>>n>>m;
    v = vi(n); rep(i,0,n) cin>>v[i];
    rep(i,0,n+10){
        dp[i] = 0;
    }
    SegmentTree<ll> sg(v);
    map<int, ull> min_taken;
    ull ans =  dfs(0,m, sg, min_taken);
    cout<<ans<<endl;
    
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}