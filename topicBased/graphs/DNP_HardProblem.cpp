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

const int N = 2e5, M = 10;
int k,n,m;
vb col(N,0);
vb vis(N,0);
vvi adj(N);
bool possible = 1;
void dfs(int node, int c) {
    // deb(c)
    // deb(node)
    if(vis[node]) return;
    vis[node] = 1;
    col[node] = c;
    // deb(node)
    // cout<<"C: "<<c<<endl;
    for(int nbhd: adj[node]){
        if(!vis[nbhd]){
            // cout<<"Inside rec:"<<endl;
            if(c) c=0; else c=1;
            // cout<<c<<endl;
            dfs(nbhd, c);
        }
        else{
            if(c == col[nbhd]){
                // cout<<"At not possible: "<<c<<endl;
                deb(nbhd) deb(node)
                possible = 0;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     deb(adj[i])
    // }
    
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            // cout<<"Start from: "<<i<<endl;
            dfs(i, 0);
        }
    }
    if(possible){
        int col1=0, col2=0;
        for (int i = 0; i < n; i++)
        {
            col1 += (col[i]==0);
            col2+= col[i];
        }
        cout<<col1<<endl;
        for (int i = 0; i < n; i++)
        {
            if(col[i]==0){
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
        cout<<col2<<endl;
        for (int i = 0; i < n; i++)
        {
            if(col[i]){
                cout<<i+1<<" ";
            }
        }
        
        
    }else cout<<-1<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}