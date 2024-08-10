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

struct LazySegmentTree{
    //* update should be distributive on the calc -> to make merging easy
    // Examples: modify with mul and calc sum -> sum every element of the segment after update will simply be the sum of parent node * update
    //2- addition to modify and to find min in range -> new min after modify is old min added by the modified val
    // 3- or to modify and AND to range -> AND of childes then OR by value == OR by value then AND the children

    // counter example: sum to modify and sum to range -> sum of the parent will depend on how many valid leafs this node has - must multiply each segment by how many elements it has (r - l + 1)
    #define L (2*cur + 1)
    #define R (2*cur + 2)
    #define md ((l+r)/2)
private:
    vi seg, ops;
    int skip = inf, no_op = -1, sz = 1, n=0;

    void apply_update(int& a, int b){
        a = b;
    }
    int merge(int a, int b){
        return min(a,b);
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

    void update(int l, int r, int cur, ll val, int lx, int rx){
        propegate(l, r, cur);
        if(r < lx || l > rx) return;
        if(r<=rx && l>=lx){
            apply_update(ops[cur], val);
            propegate(l, r, cur); //to have seg[L] and seg[R] ready for the parent
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md+1, r, R, val, lx, rx);
        seg[cur] = merge(seg[L], seg[R]);
    }

    int query(int l, int r, int cur, int lx, int rx){
        propegate(l, r, cur);
        if(r<lx || l > rx) return skip;
        if(l>=lx && r<=rx){
            return seg[cur];
        }
        return merge(query(l, md, L, lx, rx), query(md+1, r, R, lx, rx));
        //* When doing lazy prop - it's ensured that seg will contain the correct answer
    }

    void build(int l, int r, int cur, vi& arr){
        if(l==r){
            if(l<n) seg[cur] = arr[l];
            else seg[cur] = skip;
            return;
        }
        build(l, md, L, arr);
        build(md+1, r, R, arr);
        seg[cur] = merge(seg[R], seg[L]);
    }

public:
    LazySegmentTree(vi& arr){
        n = arr.size();
        while(sz<n) sz*=2; 

        seg = vi(sz*2);
        ops = vi(sz*2,no_op);
        build(0, sz-1, 0, arr);
    }
    void update(int l, int r, int val){
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
    cin>>n>>m;
    vi a(n);
    LazySegmentTree sg(a);
    deb(sg.seg)
    while(m--){
        int op; cin>>op;
        if(op==1){
            int l,r,v; cin>>l>>r>>v;
            sg.update(l, r-1, v);
        }
        else{
            int l,r; cin>>l>>r;
            cout<<sg.query(l,r-1)<<endl;
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