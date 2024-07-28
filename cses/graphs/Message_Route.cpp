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

const int N = 1e5+1, M = 10;
int k,n,m;
vvi g(N);
vi parent(N,-1);
vb vis(N);

void solve(){
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<pair<int, bitset<N>>> q;
    bitset<N> e;
    e[0] = 1;
    q.push({0, e});

    while(!q.empty()){
        auto [cur, b] = q.front(); q.pop();
        if(cur==n-1){
            e = b;
            break;
        }
        for(auto nb: g[cur]){
            if(!vis[nb]){
                vis[nb] =1;
                b[nb]=1;
                q.push({nb, b});
                b[nb]=0;
            }
        }
    }
    if(e.count()<=1) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<e.count()<<endl;;
    for (int i = 0; i < N; i++)
    {
        if(e[i]){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    
    
}

void solve2(){
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<pair<int, vector<int>>> q;
    vi e;
    e.pb(0);
    q.push({0, e});

    while(!q.empty()){
        auto [cur, b] = q.front(); q.pop();
        if(cur==n-1){
            e = b;
            break;
        }
        for(auto nb: g[cur]){
            if(!vis[nb]){
                vis[nb] =1;
                b.pb(nb);
                q.push({nb, b});
                b.pop_back();
            }
        }
    }
    if(e.size()<=1) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<e.size()<<endl;;
    for(int i: e){
        cout<<i+1<<" ";
    }
    cout<<endl;
    
}
void solve3(){
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur==n-1){

            break;
        }
        for(auto nb: g[cur]){
            if(!vis[nb]){
                vis[nb] =1;
                parent[nb] = cur;
                q.push(nb);
            }
        }
    }
    vi ans;
    int cur = n-1;
    deb(parent)
    if(parent[cur]==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        while(parent[cur]!=-1){
            ans.pb(cur);
            cur = parent[cur];
        }
        cout<<ans.size()+1<<endl;
        cout<<"1 ";
        while(ans.size()){
            cout<<ans.back()+1<<" ";
            ans.pop_back();
        }

    }
    

    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    // solve2();
    solve3();
    

    return 0;
}