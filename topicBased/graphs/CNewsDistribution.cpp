#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define sz(x)         ((int)(x).size())
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))


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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const ll N = 5e5+100, M = 10;
ll k,n,m;
vb vis(N, false);

vi bfs(ll s, vector<vector<ll>>& adj) {
    deque<int> q;
    q.push_back(s);
    vis[s] = 1;
    int d= -1; vi comp;
    while (!q.empty()) {
        int sz = q.size();
        d++;
        for (int i = 0; i < sz; i++)
        {
            int cur = q.front();
            q.pop_front();
            comp.pb(cur);
            // if(cur == e){
            //     cout<<"found at depth: "<<d<<endl;
            // }
            for(int nbhd: adj[cur]){
                if(!vis[nbhd]){
                    vis[nbhd ] =1;
                    q.pb(nbhd);
                }
            }
        }
    }
    return comp;
}


void solve(){
    cin>>n>>m;
    vector<vll> adj(n);
    int tmp;
    while(m--){
        cin>>k;
        // vi a(k);
        int prev, cur;
        if(k>0){ cin>>prev; prev--;}
        for(int i=1; i<k; i++){
            cin>>cur; cur--;
            deb(cur)
            adj[prev].pb(cur);
            adj[cur].pb(prev);
        }
        // deb(a);
    }
    // deb(adj)
    vi ans(n,1);
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            vi comp = bfs(i, adj);
            for(int node: comp){
                ans[node] = comp.size();
            }
        }
    }
    rep(i,0,n){
        cout<<ans[i]<<" ";
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}