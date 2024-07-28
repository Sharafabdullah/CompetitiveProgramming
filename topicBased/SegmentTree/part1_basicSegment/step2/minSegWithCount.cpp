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



struct SegTree{
    #define L 2*cur + 1
    #define R 2*cur + 2
    #define md (l+r)/2
private:
    struct Node{
        ll val, cnt;
        Node(ll fst, ll sec): val(fst), cnt(sec){}
    };
    Node merge(Node& x, Node& y){
        if(x.val < y.val){
            return x;
        }
        else if(x.val > y.val){
            return y;
        }
        return {x.val, x.cnt + y.cnt};
    }
    void build(int l, int r, int cur, vi& org){
        if(l==r){
            if(l<org.size()){
                seg[cur]=Node(org[l], 1);
            }
            else{
                seg[cur] = Node(inf, 1);
            }
            return;
        }
        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[cur] =merge( seg[L] , seg[R]);
    }

    void update(int l, int r, int cur, ll val, int ind){
        if(l==r){
            seg[cur] = Node{val,1};
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
    Node skip = Node(inf, 0);
    SegTree(vi& arr){
        int n = arr.size();
        while(sz<n) sz*=2; //after this-> sz is the size of last level of seg tree
        seg = vector<Node>(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    pi query(int l, int r){
        Node res= query(0, sz-1, 0, l, r);
        return {res.val, res.cnt};
    }

#undef L
#undef R
#undef md
};


void solve(){
    // vi a = {2,5,31,1,5,1};
    cin>>n>>k;
    vi a(n); rep(i,0,n) cin>>a[i];

    SegTree s(a);
    // deb(s.seg)
    int op;
    while(k--){
        cin>>op;
        if(op==1){
            int i, v; cin>>i>>v;
            s.update(i, v);
        }
        else{
            int l,r; cin>>l>>r;
            pi ans = s.query(l, r-1);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
    // deb(s.seg);
    // deb(s.query(1, 2))
    // s.update(1, 100);
    // deb(s.query(1,2))
    
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}