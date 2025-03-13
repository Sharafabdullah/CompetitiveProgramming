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


void solve(){
    int a,b;
    cin>>n>>a>>b;
    vi v(n);
    set<int> st;
    map<int, int> ind;
    rep(i,0,n){
        cin>>v[i];
        ind[v[i]] = i;
        st.insert(v[i]);
    }
    vi ans(n);
    rep(i,0,n){
        if(st.count(v[i])){
            if(st.count(b-v[i]) && st.count(a-v[i])){
                int nw = a - v[i];
                int nw2 = b - v[i];
                if(st.count(b-nw)){
                    ans[ind[b-v[i]]] = 0;
                    ans[ind[nw]] = ans[ind[b-nw]] = 0;
                    st.erase(nw);
                    st.erase(b-nw);
                    st.erase(b-v[i]);
                }
                else{
                    ans[ind[a-v[i]]] = 1;
                    ans[ind[nw2]] = ans[ind[a-nw2]] = 1;
                    st.erase(nw2);
                    st.erase(a-nw2);
                    st.erase(a-v[i]);
                }
            }
            else if(st.count(b-v[i])){
                ans[ind[v[i]]] = ans[ind[b-v[i]]] = 1;
                st.erase(b-v[i]);
            }
            else if(st.count(a-v[i])){
                ans[ind[v[i]]] = ans[ind[a-v[i]]] = 0;
                st.erase(a-v[i]);
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
            st.erase(v[i]);
        }
    }
    cout<<"YES"<<endl;
    rep(i,0,n) cout<<ans[i]<<" ";
}

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

void solve2(){
    int a,b;
    cin>>n>>a>>b;
    map<int,int> ind;
    // set<int> st;
    vi v(n); rep(i,0,n) cin>>v[i], ind[v[i]] = i;
    vb canA(n), canB(n);
    DSU dsu(n);
    rep(i,0,n){
        if(ind.count(a - v[i])){
            canA[i] = 1;
            dsu.merge(i, ind[a-v[i]]);
        }
        if(ind.count(b - v[i])){
            canB[i] = 1;
            dsu.merge(i, ind[b-v[i]]);
        }
    }
    vi component(n,3); //11 == both in b and a 
    rep(i,0,n){
        int cur = 0;
        if(canA[i]) cur|=1;
        if(canB[i]) cur|=2;
        int par = dsu.find(i);
        component[par] &= cur;
        if(!component[par]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    rep(i,0,n){
        int cur = component[dsu.find(i)];
        if(cur == 1){
            cout<<0<<" ";
        }
        else cout<<1<<" ";
    }
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        // solve();
        solve2();
    }
    

    return 0;
}