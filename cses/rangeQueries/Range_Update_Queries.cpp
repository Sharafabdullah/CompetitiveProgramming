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
public:
    vll seg, lazy;
    ll skip = 0, no_op = 0, sz = 1;

    void apply_update(ll& a, ll b){
        a += b;
    }
    ll merge(ll a, ll b){
        return max(a,b);
    }
    //! update should be distributive on the merge -> to make merging easy
    //* Examples: modify with mul and merge sum -> sum every element of the segment after update will simply be the sum of parent node * update
    //*2- addition to modify and to find min in range -> new min after modify is old min added by the modified val
    //* 3- or to modify and AND to range -> AND of childes then OR by value == OR by value then AND the children

    //! counter example: sum to modify and sum to range -> sum of the parent will depend on how many valid leafs this node has

    void propegate(ll l, ll r, ll cur){
        if(lazy[cur]==no_op) return;
        apply_update(seg[cur], lazy[cur]);
        if(l!=r){
            apply_update(lazy[L], lazy[cur]);
            apply_update(lazy[R], lazy[cur]);    
        }
        lazy[cur]=no_op;
    }
    void update(ll l, ll r, ll cur, ll val, ll lx, ll rx){
        propegate(l, r, cur);
        if(r < lx || l > rx) return;
        if(r<=rx && l>=lx){
            apply_update(lazy[cur], val);
            propegate(l, r, cur); //to have seg[L] and seg[R] ready for the parent
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md+1, r, R, val, lx, rx);
        seg[cur] = merge(seg[L], seg[R]);
    }

    ll query(ll l, ll r, ll cur, ll lx, ll rx){
        propegate(l, r, cur);
        if(r<lx || l > rx) return skip;
        if(l>=lx && r<=rx){
            deb(l) deb(r)
            deb(cur)
            return seg[cur];
        }
        ll res = merge(query(l, md, L, lx, rx), query(md+1, r, R, lx, rx));

        return res;
    }

    //* We can do updates in a for loop when init the segTree
    void build(int l, int r, int cur, vi& a){
        if(l==r){
            deb(l)
            seg[cur] = a[l];
            return;
        }
        build(l, md, L,a);
        build(md+1, r, R,a);
        seg[cur] = merge(seg[R], seg[L]);
    }

public:

    PropSegTree(vi& a){
        n = a.size();
        while(sz<n) sz*=2; //after this-> sz is the size of last level of seg tree
        seg = vll(sz*2,skip);
        lazy = vll(sz*2,no_op);
        build(0, sz-1, 0, a);
    }
    void update(int l, int r, int val){
        update(0, sz-1, 0, val, l, r);
    }

    ll query(int l, int r){
        return query(0, sz-1, 0,l, r);
    }

#undef L
#undef R
#undef md
};


void solve(){
    cin>>n>>m;
    vi a(n); rep(i,0,n) cin>>a[i];
    PropSegTree sg(a);
    deb(sg.seg)
    while(m--){
        int op; cin>>op;

        if(op==2){
            cin>>k; k--;
            cout<<sg.query(k,k)<<endl;
        }
        else{
            int a,b,u; cin>>a>>b>>u;a--,b--;
            sg.update(a,b, u);
        }
    }
}

ll bit[N];

void add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

ll get(ll idx) {
    ll ret = 0;
    for (; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

void solve2(){
    cin>>n>>m;
    vi a(n); rep(i,0,n) cin>>a[i];
    memset(bit, 0, sizeof(bit));
    rep(i,1,n+1){
        range_add(i,i, a[i-1]);
    }
    while(m--){
        int op; cin>>op;

        if(op==2){
            cin>>k;;
            cout<<get(k)<<endl;
        }
        else{
            int a,b,u; cin>>a>>b>>u;
            range_add(a,b, u);
        }
    }
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    solve2();
    

    return 0;
}