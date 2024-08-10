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

struct PropSegTree{
    #define L (2*cur + 1)
    #define R (2*cur + 2)
    #define md ((l+r)/2)
private:
    void apply_update(int& a, int b){
        a += b;
    }
    int calc_op(int a, int b){
        return max(a,b);
    }


    void propegate(int l, int r, int cur){
        if(ops[cur]==no_op) return;
        apply_update(seg[cur], ops[cur]);
        if(l!=r){
            apply_update(ops[L], ops[cur]);
            apply_update(ops[R], ops[cur]);    
        }
        ops[cur]=no_op;
    }
    void update(int l, int r, int cur, int val, int lx, int rx){
        propegate(l, r, cur);
        if(r < lx || l > rx) return;
        if(r<=rx && l>=lx){
            apply_update(ops[cur], val);
            propegate(l, r, cur); //to have seg[L] and seg[R] ready for the parent
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md+1, r, R, val, lx, rx);
        seg[cur] = calc_op(seg[L], seg[R]);
    }

    int query(int l, int r, int cur, int lx, int rx){
        propegate(l, r, cur);
        if(r<lx || l > rx) return skip;
        if(l>=lx && r<=rx){
            return seg[cur];
        }
        int res = calc_op(query(l, md, L, lx, rx), query(md+1, r, R, lx, rx));
        //* When doing lazy prop - it's ensured that seg will contain the correct answer
        return res;
    }

    //* We can do updates in a for loop when init the segTree
    void build(int l, int r, int cur){
        if(l==r){
            seg[cur] = 0;
            return;
        }
        build(l, md, L);
        build(md+1, r, R);
        seg[cur] = calc_op(seg[R], seg[L]);
    }

public:
    vi seg, ops;
    int skip = 0, no_op = 0, sz = 1;
    PropSegTree(int n){
        while(sz<n) sz*=2; //after this-> sz is the size of last level of seg tree
        seg = vi(sz*2,skip);
        ops = vi(sz*2,no_op);
        // build(0, sz-1, 0);
    }
    void Rupdate(int l, int r, int val){
        update(0, sz-1, 0, val, l, r);
    }

    int query(int l, int r){
        return query(0, sz-1, 0,l, r);
    }

#undef L
#undef R
#undef md
};

void solve(){
    int q; cin>>n>>q;
    vi a(n); rep(i,0,n) cin>>a[i];
    PropSegTree sg(n);
    while(q--){
        int a,b; cin>>a>>b; a--,b--;
        sg.Rupdate(a,b,1);
    }
    vi rp(n);
    rep(i,0,n) {
        rp[i] = sg.query(i,i);
    }
    sort(all(rp));
    sort(all(a));
    ll ans = 0;
    rep(i,0,n){
        ans += 1ll * rp[i] * a[i];
    }
    cout<<ans<<endl;
}
void solve2(){
    int q; cin>>n>>q;
    vi a(n), diff(n+1), b(n); rep(i,0,n) cin>>a[i];
    while(q--){
        int a,b; cin>>a>>b; a--,b--;
        diff[a] ++;
        diff[b+1]--;
    }
    b[0] = diff[0];
    rep(i,1,n){
        b[i] =b[i-1]+diff[i];
    }
    sort(all(b)); sort(all(a));
    ll ans = 0;
    rep(i,0,n) ans += 1ll * a[i] * b[i];
    cout<<ans<<endl;
}

ll bit[N];
void add(int i, int v) {
    while(i <= n) {
        bit[i] += v;
        i += i&(-i);
    }
}

int get(int i) {
    int res = 0;
    while(i > 0) {
        res += bit[i];
        i -= i&(-i);
    }
    return res;
}
int get(int l, int r) {
    return get(r)-get(l-1);
}

void solve3(){
    cin>>n>>m;
    memset(bit, 0, sizeof(bit));
    vi a(n); rep(i,0,n) cin>>a[i];
    while(m--){
        int a,b; cin>>a>>b;a--,b--;
    }
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    // solve2();
    solve3();
    

    return 0;
}