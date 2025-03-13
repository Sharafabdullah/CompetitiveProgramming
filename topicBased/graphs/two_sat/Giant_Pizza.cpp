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

const int N = 1e5+10, M = 10;
int k,n,m;

vvi g(2*N),gt(2*N);

stack<int> st;
vb vis;
bool first = 1;
vi comb;
void dfs(int cur, int id=0){
    vis[cur] = 1;
    if(first){
        deb(cur)
        for(int ch: g[cur]){
            if(!vis[ch]) {deb(ch) dfs(ch);}
        }
        st.push(cur);
    }
    else{
        comb[cur] = id;
        for(int ch: gt[cur]){
            if(!vis[ch]) dfs(ch, id);
        }
    }
}

void solve(){
    cin>>k>>n;
    rep(i,0,k){
        char c1,c2; int n1,n2;
        cin>>c1>>n1>>c2>>n2;
        int b1 = c1=='+'?1:0;
        int b2 = c2=='+'?1:0;
        // deb(n*(b1-1) + n1);
        // deb(n*b2 + n2);
        // deb("++")
        g[n*(1-b1) + n1].pb(n*b2 + n2); //if not n1 -> n2
        gt[n*b2 + n2].pb(n*(1-b1) + n1);

        g[n*(1-b2)+n2].pb(n*b1 + n1); //if not n2 -> n1 (for sure)
        gt[n*b1 + n1].pb(n*(1-b2)+n2);
    }
    // deb(g)
    vis = vb(2*n+1);
    comb = vi(2*n+1);
    rep(i,1,2*n+1){
        if(!vis[i]) dfs(i);
    }
    vis = vb(2*n+1);
    int id = 1;
    first = 0;
    while(!st.empty()){
        int cur = st.top(); st.pop();
        deb(cur)
        if(!vis[cur]){
            dfs(cur, id++);
        }
    }
    int ans[n+1];
    rep(i,1,n+1){
        deb(i)
        deb(comb[i]) deb(comb[i+n])
        if(comb[i] == comb[i+n]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        else if(comb[i] < comb[i+n]){
            ans[i] = 1;
        }
        else ans[i] = 0;
    }
    rep(i,1,n+1) cout<<(ans[i]?'+':'-')<<" ";
    cout<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}