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
typedef vector<ll>       vi;
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
// void _print(string t) {cerr << t;}
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


struct SegTree{
    #define L 2*cur + 1
    #define R 2*cur + 2
    #define md (l+r)/2
private:
    struct Node{
        ll mx, sum, pref, suf;
        Node(){}
        Node(ll mx, ll sum, ll pref, ll suf): mx(mx), sum(sum), pref(pref), suf(suf){}
    };
    Node merge(Node& x, Node& y){
        Node ret;
        ret.sum = x.sum + y.sum;
        ret.pref = max(0LL, max(x.pref, x.sum + y.pref));
        ret.suf = max(0ll, max(y.suf, y.sum + x.suf));
        ret.mx = max({x.mx, y.mx, x.suf+y.pref});
        return ret;
    }
    void build(int l, int r, int cur, vi& org){
        if(l==r){
            if(l<org.size()){
                seg[cur]=Node(max(0ll,org[l]), org[l], max(0ll,org[l]),max(0ll, org[l]) );
            }
            else{
                seg[cur] = skip;
            }
            return;
        }
        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[cur] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int cur, ll val, int ind){
        if(l==r){
            seg[cur] = Node(max(0ll,val), val, max(0ll,val),max(0ll, val) );
            return;
        }
        if(ind<=md){
            update(l, md, L, val, ind);
        }
        else{
            update(md+1, r, R, val, ind);
        }
        seg[cur] = merge(seg[L], seg[R]);
    }

    Node query(int l, int r, int cur, int lq, int rq){
        if(r<lq || l > rq){
            return skip;
        }
        if(l>=lq && r<=rq){
            return seg[cur];
        }
        Node lft = query(l, md, L, lq,rq);
        Node rght = query(md+1, r, R, lq,rq);
        return merge(lft, rght);
    }

public:
    
    int sz=1; 
    vector<Node> seg;
    Node skip = Node(-inf, -inf,-inf,-inf);
    SegTree(vi& arr){
        int n = arr.size();
        while(sz<n) sz*=2; //after this-> sz is the size of last level of seg tree
        seg = vector<Node>(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    ll query(){
        Node res= seg[0];
        return res.mx;
    }

#undef L
#undef R
#undef md
};


void solve(){
    ordered_set<int> o;
    
    cin>>n>>k;
    vi a(n); rep(i,0,n) cin>>a[i];

    SegTree s(a);

    int op;
    cout<<s.query()<<endl;
    while(k--){
        ll ind, val;
        cin>>ind>>val;
        s.update(ind, val);
        cout<<s.query()<<endl;
    }
    
}

int main(){
    FASTIO;

    int t= 1;
    while(t--) solve();
    

    return 0;
}