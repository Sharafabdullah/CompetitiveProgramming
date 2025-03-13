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

struct node{
    int ind, k, v;
    node(int ind, int k, int v): ind(ind), k(k), v(v){}
    node(){};
    bool operator<(const node& other) const {
        return this->k > other.k;  
    }
};

struct DSU{

public:
    vi parent,group;
    DSU(int n){
        parent = vi(n+1);
        group = vi(n+1, 1);
        iota(all(parent), 0);
    }
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
        
    }
    void merge(int u, int v){
        int l1 = find(u), l2 = find(v);
        if(l1 == l2) return;
        if(group[l1]>group[l2]) swap(l1,l2);
        parent[l1] = l2;
        group[l2]+= group[l1];
    }
    bool sameGroup(int u, int v){
        return find(u)==find(v);
    }
    int compSize(int u){
        return group[find(u)];
    }
};

void solve(){
    int q;
    cin>>n>>q;
    vector<array<ll,3>> edges(n-1);
    int a,b;
    rep(i,0,n-1){
        cin>>a>>b>>k; a--,b--;
        edges[i] = {k,a,b};
    }
    vector<node> queries(q);
    rep(i,0,q){
        cin>>k>>a; a--;
        queries[i] = node(i, k, a);
    }
    sort(all(queries));
    sort(all(edges), [&](auto& f, auto& s){
        return f[0] > s[0];
    });
    
    vi ans(q);
    DSU dsu(n);
    int eInd = 0;
    for(auto [i, curK, curV]: queries){
        while(eInd < edges.size() && edges[eInd][0] >= curK){
            dsu.merge(edges[eInd][1], edges[eInd][2]);
            eInd++;
        }
        ans[i] = dsu.compSize(curV)-1;

    }
    for(int x: ans) cout<<x<<endl;
}

int main(){
    FASTIO;
    #ifndef ONLINE_JUDGE
            freopen("mootube.in", "r", stdin);
            freopen("mootube.out", "w", stdout);
        #endif
    int t= 1;
    // cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}