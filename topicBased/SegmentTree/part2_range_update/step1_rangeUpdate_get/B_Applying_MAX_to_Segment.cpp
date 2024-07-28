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

//! no lazy prop
struct SegTree{
    #define L 2*cur + 1
    #define R 2*cur + 2
    #define md (l+r)/2
private:
    ll merge(ll res, int curNode){
        return max(res, seg[curNode]);
    }
    void update(int l, int r, int cur, ll val, int lx, int rx){
        if(r < lx || l > rx) return;
        if(r<=rx && l>=lx){
            seg[cur] = merge(val, cur);
            return;
        }
        update(l, md, L, val, lx, rx);
        update(md+1, r, R, val, lx, rx);
    }

    ll query(int l, int r, int cur, int ind){
        if(l > ind || r< ind) return 0;
        if(l==r) {
            return seg[cur];
        }
        ll res = 0;
        if(md >= ind){
            res = query(l, md, L, ind);
        }
        else{
            res = query(md+1, r, R, ind);
        }
        return merge(res, cur);
    }

public:
    
    int sz=1; 
    vector<ll> seg;
    ll skip = 0;
    SegTree(int n){
        // int n = arr.size();
        while(sz<n) sz*=2; //after this-> sz is the size of last level of seg tree
        seg = vector<ll>(sz*2,skip);

    }
    void Rupdate(int l, int r, ll val){
        update(0, sz-1, 0, val, l, r);
    }

    ll query(int ind){
        return query(0, sz-1, 0, ind);
    }

#undef L
#undef R
#undef md
};


void solve(){
    int q;
    cin>>n>>q;
    SegTree s(n);
    while(q--){
        int op; cin>>op;
        if(op==1){
            int l,r, val; cin>>l>>r>>val;
            s.Rupdate(l, r-1, val);
        }
        else{
            cin>>k;
            cout<<s.query(k)<<endl;
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