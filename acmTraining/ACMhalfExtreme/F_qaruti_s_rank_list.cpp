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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve(){
    cin>>n;

    ordered_set<int> os;
    rep(i,1,n+1) os.insert(i);
    vi ans(n+1);
    rep(i,0,n){
        int id;
        cin>>k>>id;
        int it = *os.find_by_order(k-1);
        os.erase(os.find_by_order(k-1));
        ans[it] = id;
    }
    rep(i,1,n+1) cout<<ans[i]<<" ";
    cout<<endl;
}

struct LazySegmentTree{
    #define L (2*cur + 1)
    #define R (2*cur + 2)
    #define md ((l+r)/2)
private:
    vi seg, ops;
    int skip = inf, no_op = 0, sz = 1, n=0;

    void apply_update(int& a, int b){
        a += b;
    }
    int merge(int a, int b){
        return min(a,b);
    }
    
    void propagate(int l, int r, int cur){
        if(ops[cur]==no_op) return;
        apply_update(seg[cur], ops[cur]);
        if(l!=r){
            apply_update(ops[L], ops[cur]);
            apply_update(ops[R], ops[cur]);    
        }
        ops[cur]=no_op;
    }

    void update(int l, int r, int cur, ll val, int lx, int rx){
        propagate(l, r, cur);
        if(r < lx || l > rx) return;
        if(r<=rx && l>=lx){
            apply_update(ops[cur], val);
            propagate(l, r, cur); //to have seg[L] and seg[R] ready for the parent
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md+1, r, R, val, lx, rx);
        seg[cur] = merge(seg[L], seg[R]);
    }

    int query(int l, int r, int cur, int ind){
        propagate(l, r, cur);
        if(l==r){
            // seg[cur] = inf;
            // seg[l] = inf;
            return l;
        }
        propagate(l, md, L);
        propagate(md + 1, r, R);
        int ans;
        if(seg[R] <= ind) {
            ans =  query(md + 1, r, R, ind);
        } else ans = query(l, md, L, ind);
        seg[cur] = merge(seg[L], seg[R]);
        return ans;
    }

    void build(int l, int r, int cur, vi& arr){
        if(l==r){
            if(l<arr.size()) seg[cur] = arr[l];
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

        seg = vi(sz*2,skip);
        ops = vi(sz*2,no_op);
        build(1, sz-1, 0, arr);
    }
    void update(int l, int r, int val){
        update(1, sz-1, 0, val, l, r);
    }

    int query(int ind){
        deb(seg)
        int ans = query(1, sz-1, 0,ind);
        update(ans + 1, sz-1, -1);
        return ans;
    }

#undef L
#undef R
#undef md
};

void solve2(){
    cin>>n;
    vi a(n+1), ans(n+1); 
    rep(i,1,n+1) a[i]=i;
    LazySegmentTree sg(a);
    rep(i,0,n){
        int id;
        cin>>k>>id;
        int ind = sg.query(k);
        deb(ind)
        ans[ind] = id;
    }
    rep(i,1,n+1) cout<<ans[i]<<" ";
    cout<<endl;
}
int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        // solve();
        solve2();
    }
    

    return 0;
}