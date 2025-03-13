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

struct LazySegmentTree {
    #define L (2*cur + 1)
    #define R (2*cur + 2)
    #define md ((l+r)/2)
private:
    struct Node{
        int mx0=-1,mx1=-1,mn0=inf,mn1=inf;
    };
    vector<Node> seg; vi ops;
    const Node skip; int no_op=0;
    int sz, n;

    inline void apply_update(Node& a, int b) {
        if(b%2){
            swap(a.mn0, a.mn1);
            swap(a.mx1, a.mx0);
        }
    }
    inline void apply_update2(int& a, int b) {
        a+=b;
    }

    inline Node merge(Node a, Node b) {
        Node ret;
        ret.mn0 = min(a.mn0, b.mn0);
        ret.mn1 = min(a.mn1, b.mn1);
        ret.mx0 = max(a.mx0, b.mx0);
        ret.mx1 = max(a.mx1, b.mx1);
        return ret;
    }

    inline void propagate(int l, int r, int cur) {
        if (ops[cur] == no_op) return;  // No update pending
        apply_update(seg[cur], ops[cur]);  // Apply update to current segment
        if (l != r) {  // If not a leaf node, propagate lazily
            apply_update2(ops[L], ops[cur]);
            apply_update2(ops[R], ops[cur]);
        }
        ops[cur] = no_op;  // Clear the operation after propagating
    }

    void update(int l, int r, int cur, int val, int lx, int rx) {
        propagate(l, r, cur);  // Ensure the current segment is up-to-date
        if (r < lx || l > rx) return;  // Out of range
        if (l >= lx && r <= rx) {  // Full segment overlap
            apply_update2(ops[cur], val);
            propagate(l, r, cur);  // Push the update immediately
            return;
        }
        int m = (l + r) / 2;
        update(l, m, L, val, lx, rx);
        update(m + 1, r, R, val, lx, rx);
        seg[cur] = merge(seg[L], seg[R]);  // Recalculate the parent node
    }

    Node query(int l, int r, int cur, int lx, int rx) {
        propagate(l, r, cur);  // Ensure the current segment is up-to-date
        if (r < lx || l > rx) return skip;  // Out of range
        if (l >= lx && r <= rx) {  // Full segment overlap
            return seg[cur];
        }
        int m = (l + r) / 2;
        return merge(query(l, m, L, lx, rx), query(m + 1, r, R, lx, rx));
    }

    void build(const string& arr) {
        for (int i = 0; i < n; ++i){
            if(arr[i]=='1'){
                seg[sz - 1 + i].mn1 = i;
                seg[sz - 1 + i].mx1 = i;
            }
            else{
                seg[sz - 1 + i].mn0 = i;
                seg[sz - 1 + i].mx0 = i;
            }
        }
        for (int i = sz - 2; i >= 0; --i) seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
    }

public:
    LazySegmentTree(const string& arr) : n(arr.size()) {
        sz = 1;
        while (sz < n) sz *= 2;  // Round up to the next power of two
        seg.assign(2 * sz, skip);  // Segment tree initialized to `skip`
        ops.assign(2 * sz, no_op);  // Lazy propagation array initialized to `no_op`
        build(arr);
    }

    void update(int l, int r, int val) {
        update(0, sz - 1, 0, val, l, r);
    }

    int query(int l, int r) {
        Node ret = query(0, sz - 1, 0, l, r);
        // cout<<ret.mn0<<" "<<ret.mx0<<" | "<<ret.mn1<<" "<<ret.mx1<<endl;
        if(ret.mx0 == -1 || ret.mn0 == -1  || ret.mn0 == inf) return 0;
        return ((ret.mx0+1) % (ret.mn0+1)) == 0;
    }
};

void solve(){
    cin>>n;
    string s; cin>>s;
    LazySegmentTree sg(s);
    int q;
    cin>>q;
    while(q--){
        int a,b; cin>>a>>b; a--,b--;
        sg.update(a,b,1);
        if(sg.query(0, n-1)){
            cout<<"YES"<<endl;
        } else cout<<"NO"<<endl;
    }
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