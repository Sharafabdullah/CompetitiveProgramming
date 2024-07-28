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

vector<vll> g(N);
vi vis(N);
vi parent(N);
int c =-1,e = -1;
void dfs(int cur){
    // deb(cur)
    for(int ch: g[cur]){
        // if(c!=-1) break;
        if(vis[ch]<=1){
            vis[ch] = 2;
            parent[ch] = cur;
            dfs(ch);
            vis[ch] = 1; //mark unstack
        }
        else if(vis[ch]==2){
           c= cur;
           e = ch;
        //    break;
        }
    }
}
void solve(){
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b; a--,b--;
        g[a].pb(b);
    }
    // deb(g)
    rep(i,0,n){
        if(vis[i]<=1){
            dfs(i);
            if(c!=-1){
                break;
            }
        }
    }
    deb(parent)
    if(c==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vi ans; 
        ans.pb(c+1);
        int f = c;
        deb(parent[c])
        deb(f) deb(c)
        c = parent[c];
        while(c!=f){
            ans.pb(c+1);
            c=parent[c];
        }
        ans.pb(f+1);
        reverse(all(ans));
        cout<<ans.size()<<endl;
        for(int i: ans) cout<<i<<" ";
    }
}

void solve2(){
    cin>>n>>m;
}

vb inStk(N);
stack<int> s;
bool dfs2(int cur){
    deb(cur)
    vis[cur] = 1;
    s.push(cur);
    inStk[cur] = 1;
    for(int ch: g[cur]){
        // deb(ch)
        if(!vis[ch]){
            if(dfs2(ch)){
                return true;
            }
        }
        if(inStk[ch]){
            s.push(ch);
            return true;
        }
    }

    inStk[cur] = 0;
    s.pop();
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    int a,b;
    while(m--){
        cin>>a>>b; a--,b--;
        g[a].pb(b);
    }
    // deb(g)
    bool f = 0;
    rep(i,0,n){
        if(!vis[i]){
            if(dfs2(i)){
                f =  1;
                break;
            }
        }
    }
    
    if(!f){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vi ans;
        int tmp = s.top();
        while(!s.empty()){
            ans.pb(s.top()); s.pop();
            if(ans.back()==tmp && ans.size()!=1){
                break;
            }
        }
        cout<<ans.size()<<endl;
        reverse(all(ans));
        for(int i: ans) cout<<i+1<<" ";
    }
    return 0;
}