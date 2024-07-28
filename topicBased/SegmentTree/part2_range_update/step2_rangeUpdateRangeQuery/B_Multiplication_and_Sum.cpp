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

//! without lazy propogation
struct SegTree{
    #define L 2*cur + 1
    #define R 2*cur + 2
    #define md (l+r)/2
private:
    void apply_update(ll& a, ll b){
        a = (a*b)%mod;
    }
    ll calc_op(ll a, ll b){
        return (a+b)%mod;
    }
    void update(ll l, ll r, ll cur, ll val, ll lx, ll rx){
        if(r < lx || l > rx) return;
        if(r<=rx && l>=lx){
            apply_update(seg[cur], val);
            apply_update(ops[cur], val);
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md+1, r, R, val, lx, rx);
        seg[cur] = calc_op(seg[L], seg[R]);
        apply_update(seg[cur], ops[cur]);
    }

    ll query(ll l, ll r, ll cur, ll lx, ll rx){
        if(r<lx || l > rx) return 0;
        if(l>=lx && r<=rx){
            return seg[cur];
        }
        ll res = calc_op(query(l, md, L, lx, rx), query(md+1, r, R, lx, rx));
        apply_update(res, ops[cur]);
        return res;
    }

    void build(ll l, ll r, ll cur){
        if(l==r){
            seg[cur] = 1;
            return;
        }
        build(l, md, L);
        build(md+1, r, R);
        seg[cur] = calc_op(seg[R], seg[L]);
    }

public:
    
    ll sz=1; 
    vector<ll> seg, ops;
    ll skip = 0;
    SegTree(ll n){
        // int n = arr.size();
        while(sz<n) sz*=2; //after this-> sz is the size of last level of seg tree
        seg = vector<ll>(sz*2,0);
        ops = vector<ll>(sz*2,1);
        build(0, sz-1, 0);
    }
    void Rupdate(ll l, ll r, ll val){
        update(0, sz-1, 0, val, l, r);
    }

    ll query(ll l, ll r){
        return query(0, sz-1, 0,l, r);
    }

#undef L
#undef R
#undef md
};

//! with lazy propogation - can be done without
struct PropSegTree{
    #define L 2*cur + 1
    #define R 2*cur + 2
    #define md (l+r)/2
private:
    void apply_update(ll& a, ll b){
        a = (a*b)%mod;
    }
    ll calc_op(ll a, ll b){
        return (a+b)%mod;
    }
    void propegate(int l, int r, int cur){
        if(ops[cur]==1) return;
        if(l==r){
            apply_update(seg[cur], ops[cur]);
            ops[cur] = 1;
            return;
        }
        apply_update(ops[L], ops[cur]);
        apply_update(ops[R], ops[cur]);
        apply_update(seg[cur], ops[cur]);
        ops[cur]=1;
    }
    void update(ll l, ll r, ll cur, ll val, ll lx, ll rx){
        propegate(l, r, cur);
        if(r < lx || l > rx) return;
        if(r<=rx && l>=lx){
            // apply_update(seg[cur], val);
            apply_update(ops[cur], val);
            propegate(l, r, cur); //to have seg[L] and seg[R] ready for the parent
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md+1, r, R, val, lx, rx);
        seg[cur] = calc_op(seg[L], seg[R]);
    }

    ll query(ll l, ll r, ll cur, ll lx, ll rx){
        propegate(l, r, cur);
        if(r<lx || l > rx) return 0;
        if(l>=lx && r<=rx){
            return seg[cur];
        }
        ll res = calc_op(query(l, md, L, lx, rx), query(md+1, r, R, lx, rx));
        // apply_update(res, ops[cur]); 
        //* When doing lazy prop - it's ensured that seg will contain the correct answer
        return res;
    }

    //* We can do updates in a for loop when init the segTree
    void build(ll l, ll r, ll cur){
        if(l==r){
            seg[cur] = 1;
            return;
        }
        build(l, md, L);
        build(md+1, r, R);
        seg[cur] = calc_op(seg[R], seg[L]);
    }

public:
    
    ll sz=1; 
    vector<ll> seg, ops;
    ll skip = 0;
    PropSegTree(ll n){
        // int n = arr.size();
        while(sz<n) sz*=2; //after this-> sz is the size of last level of seg tree
        seg = vector<ll>(sz*2,0);
        ops = vector<ll>(sz*2,1);
        build(0, sz-1, 0);
    }
    void Rupdate(ll l, ll r, ll val){
        update(0, sz-1, 0, val, l, r);
    }

    ll query(ll l, ll r){
        return query(0, sz-1, 0,l, r);
    }

#undef L
#undef R
#undef md
};


void solve(){
    int q;
    cin>>n>>q;
    PropSegTree s(n);
    deb(s.seg)
    while(q--){
        int op; cin>>op;
        if(op==1){
            ll l,r, val; cin>>l>>r>>val;
            s.Rupdate(l, r-1, val);
        }
        else{
            ll l,r;
            cin>>l>>r;
            cout<<s.query(l,r-1)<<endl;
        }
    }
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}


