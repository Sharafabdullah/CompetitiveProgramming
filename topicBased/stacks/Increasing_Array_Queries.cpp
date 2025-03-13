#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")


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

struct LazySegmentTree {
    #define L (2*cur + 1)
    #define R (2*cur + 2)
    #define md ((l+r)/2)
private:
    vll seg, ops;
    const int skip = 0, no_op = 0;
    int sz, n;

    inline void apply_update(ll& a, ll b) {
        a = b;
    }

    inline ll merge(ll a, ll b) {
        return a + b;
    }

    inline void propagate(int l, int r, int cur) {
        if (ops[cur] == no_op) return;  // No update pending
        seg[cur] = ops[cur] * (r - l + 1);  // Apply update to current segment
        
        if (l != r) {  // If not a leaf node, propagate lazily
            apply_update(ops[L], ops[cur]);
            apply_update(ops[R], ops[cur]);
        }
        ops[cur] = no_op;  // Clear the operation after propagating
    }

    void update(int l, int r, int cur, ll val, int lx, int rx) {
        propagate(l, r, cur);  // Ensure the current segment is up-to-date
        if (r < lx || l > rx) return;  // Out of range
        if (l >= lx && r <= rx) {  // Full segment overlap
            apply_update(ops[cur], val);
            propagate(l, r, cur);  // Push the update immediately
            return;
        }
        int m = (l + r) / 2;
        update(l, m, L, val, lx, rx);
        update(m + 1, r, R, val, lx, rx);
        seg[cur] = merge(seg[L], seg[R]);  // Recalculate the parent node
    }

    ll query(int l, int r, int cur, int lx, int rx) {
        propagate(l, r, cur);  // Ensure the current segment is up-to-date
        if (r < lx || l > rx) return skip;  // Out of range
        if (l >= lx && r <= rx) {  // Full segment overlap
            return seg[cur];
        }
        int m = (l + r) / 2;
        return merge(query(l, m, L, lx, rx), query(m + 1, r, R, lx, rx));
    }

     void build(int l, int r, int cur,const vi& arr){
        if(l==r){
            if(l<arr.size()) seg[cur] = arr[l];
            return;
        }
        build(l, md, L, arr);
        build(md+1, r, R, arr);
        seg[cur] = merge(seg[R], seg[L]);
    }

public:
    LazySegmentTree(const vi& arr) : n(arr.size()) {
        sz = 1;
        while (sz < n) sz *= 2;  // Round up to the next power of two
        seg.assign(2 * sz, skip);  // Segment tree initialized to `skip`
        ops.assign(2 * sz, no_op);  // Lazy propagation array initialized to `no_op`
        build(0, sz-1, 0, arr);
    }

    void update(int l, int r, ll val) {
        update(0, sz - 1, 0, val, l, r);
    }

    ll query(int l, int r) {
        return query(0, sz - 1, 0, l, r);
    }
};

struct Node{
    int l,r,ind;
    bool const operator<(const auto& other){
        return l > other.l;
    }
};

using namespace chrono; steady_clock::time_point tstt,endt;
void start(){tstt = steady_clock::now();}
void end(int i = 0){
    if(!i) cout<<"Time: "<<duration_cast<microseconds>(steady_clock::now()- tstt).count()<<char(230)<<"s"<<endl;
    else cout<<"Time: "<<duration_cast<milliseconds>(steady_clock::now()- tstt).count()<<"ms"<<endl;}

void solve(){
    cin>>n>>k;
    vi a(n); 
    LazySegmentTree sg(a);


    rep(i,0,n) cin>>a[i];
    a.pb(inf);
    vll pref(n+1);
    rep(i,0,n) pref[i+1] = pref[i] + a[i];

    vector<Node> q;
    rep(i,0,k){
        int l,r;
        cin>>l>>r;
        q.pb({--l,--r,i});
    }
    start();
    sort(all(q));
    
    stack<pi> st;
    int curq = 0;
    vll ans(k);
    for(int i = n; i>=0; i--){
        int end = i;
        while(!st.empty() && a[i] >= st.top().first){
            end = st.top().second;
            st.pop();
        }
        end = st.empty()? n: st.top().second-1;
        st.push({a[i], i});
        sg.update(i, end, a[i]);
        while(curq < k && q[curq].l == i){
            ans[q[curq].ind] = sg.query(i, q[curq].r) - (pref[q[curq].r+1] - pref[i]);
            curq++;
        }
    }
    rep(i,0,k) cout<<ans[i]<<endl;
    end();
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