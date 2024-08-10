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
    vector<pi> seg; vi ops;
    pi skip = {0, -inf}; int no_op = 0, sz = 1, n=0;

    void apply_update(int& a, int b){
        a += b;
    }
    pi merge(pi a, pi b){
        if(b.second>=a.second) return b;
        return a;
    }
    
    void propegate(int l, int r, int cur){
        if(ops[cur]==no_op) return;
        apply_update(seg[cur].second, ops[cur]);
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

    int query(int l, int r, int cur, int ind){
        propegate(l, r, cur);
        if(l==r){
            int ret = seg[cur].first;
            seg[cur] = skip;
            update(l+1, n-1, -1);
            return ret;
        }
        int ret = 0;
        propegate(l, md, L);
        propegate(md+1, r, R);
        if(ind<=seg[L].second){
            ret = query(l, md, L, ind);
        } else if(seg[R].second >=0) ret = query(md+1, r, R, ind);
        seg[cur] = merge(seg[L], seg[R]);
        return ret;
    }

    void build(int l, int r, int cur, vi& arr){
        if(l==r){
            if(l<arr.size()) {
                seg[cur].first = arr[l];
                seg[cur].second = l;
                deb(seg[cur])
            }
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

        seg = vector<pi>(sz*2,skip);
        ops = vi(sz*2,no_op);
        build(0, sz-1, 0, arr);
    }
    void update(int l, int r, int val){
        update(0, sz-1, 0, val, l, r);
    }

    int query(int ind){
        return query(0, sz-1, 0,ind);
    }

#undef L
#undef R
#undef md
};

void solve(){
    cin>>n;
    vi a(n); rep(i,0,n) cin>>a[i];
    LazySegmentTree sg(a);
    rep(i,0,n){
        int p; cin>>p;p--;
        cout<<sg.query(p)<<" ";
    }
    
}

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve2(){
    cin>>n;
    ordered_set<int> o;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
        o.insert(i);
    }
    rep(i,0,n){
        int p; cin>>p; p--;
        auto k = o.find_by_order(p);
        cout<<a[*k]<<" ";
        o.erase(k);
    }
}

struct SegTree{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
public:
    vi seg;
    ll skip = 0,sz = 1;
    ll merge(ll x, ll y){
        return x + y;
    }
    void build(int l, int r, int node, vi& org){
        if(l==r){
            if(l< org.size()) seg[node] = l;
            return;}

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int node, ll val, int ind){
        if(l==r){
            seg[node]-=val;
            return;
        }

        if(ind >= l && ind<=seg[node]) update(l, md, L, val, ind);
        else update(md+1, r, R, val, ind);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    ll get(int l, int r, int node, int ind){
        if(l==r){
            return seg[l];
        }
        int res;
        if(ind <= seg[L]){
            res = get(l, md, L, ind);
        } else res= get(md+1, r, R, ind);
        seg[node] = merge(seg[L], seg[R]);
        return res;
    }

public:
    SegTree(vi& arr){
        int n = arr.size();
        while(sz<n) sz*=2;
        seg = vi(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    ll get(int ind){
        return get(0, sz-1, 0, ind);
    }
#undef L
#undef R
#undef md
};

void solve3(){
    cin>>n;
    vi a(n); rep(i,0,n) cin>>a[i];
    SegTree sg(a);
    deb(sg.seg)
    rep(i,0,n){
        int p; cin>>p;p--;
        deb(p)
        p = sg.get(p);
        deb(p)
        cout<< a[p]<<" ";
        sg.update(p, 1);
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