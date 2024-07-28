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

struct SegTree{
    #define L 2*cur + 1
    #define R 2*cur + 2
    #define md (l+r)/2
private:
    struct Node{
        ll mx,idx;
        Node(){}
        Node(ll fst, ll sec): mx(fst), idx(sec){}
    };
    Node merge(Node& x, Node& y){
        Node ret;
        if(x.mx >= y.mx){
            ret.mx = x.mx;
            ret.idx = x.idx;
        }
        else{
            ret.mx = y.mx;
            ret.idx = y.idx;
        }
        return ret;
    }
    void build(int l, int r, int cur, vi& org){
        if(l==r){
            if(l<org.size()){
                seg[cur]=Node(org[l], l);
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
            seg[cur] = Node(val, ind);
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

    Node query(int l, int r, int cur, int x, int least){
        if(r < least || seg[cur].mx < x){
            return Node(0,-1);
        }
        if(l==r){
            if(seg[cur].mx >= x){
                return Node(0, l);
            }
            else return Node(0,-1);
        }
        Node lft = query(l, md, L, x,least);
        if(lft.idx == -1 ){
            return query(md+1, r, R, x, least);
        } else return lft;
    }

public:
    
    int sz=1; 
    vector<Node> seg;
    Node skip = Node(-inf, 0);
    SegTree(vi& arr){
        int n = arr.size();
        while(sz<n) sz*=2; //after this-> sz is the size of last level of seg tree
        seg = vector<Node>(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    void update(int ind, ll val){
        update(0, sz-1, 0, val, ind);
    }

    int query(int x, int l){
        Node res= query(0, sz-1, 0, x, l);
        return res.idx;
    }

#undef L
#undef R
#undef md
};

void solve(){
    cin>>n>>m;
    vi a(n); rep(i,0,n) cin>>a[i];
    SegTree s(a);
    while(m--){
        int op; cin>>op;
        if(op==1){
            int ind, val; cin>>ind>>val;
            s.update(ind, val);
        }
        else{
            int l;
            cin>>k>>l;
            cout<<s.query(k,l)<<endl;
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