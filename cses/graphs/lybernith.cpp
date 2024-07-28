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
const char dr[]={ 'R','L','D','U'};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 1001, M = 10;
int k,n,m;
vs g(N);
vvb vis;
bool found = 0;
bool isValid(int i,int j){
    return !(i<0|| i>=n || j<0||j>=m || g[i][j]=='#' || vis[i][j]);
}
string ans = "";
void dfs(int x, int y,string cur){
    vis[x][y]=1;
    if(g[x][y]=='B') {
        if(ans==""|| cur.size()>ans.size()){
            ans = cur;
            return;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x+dx[i], ny = y+dy[i];
        if(isValid(nx,ny)){
            cur.pb(dr[i]);
            dfs(nx,ny,cur);
            cur.pop_back();
        }
    }
    vis[x][y]=0;
}

void solve(){
    cin>>n>>m;
    g.assign(n,"");
    vis.assign(n,vb(m));
    rep(i,0,n) cin>>g[i];
    int x,y;
    rep(i,0,n){
        rep(j,0,m){
            if(g[i][j]=='A'){
                x=i;y=j;
            }
        }
    }

    // cout<<x<<" " <<y<<endl;
    dfs(x,y,"");
    if(ans.size()>0){
        // reverse(all(ans));
        cout<<"YES"<<endl;
        cout<<ans.length()<<endl;
        cout<<ans<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

void solve2(){
    cin>>n>>m;
    g.assign(n,"");
    vis.assign(n,vb(m));
    vector<vector<char>> dd(n+1,vector<char>(m+1,'.'));

    rep(i,0,n) cin>>g[i];
    int x,y;
    rep(i,0,n) rep(j,0,m) if(g[i][j]=='A') {x=i; y=j;}

    queue<pi> q;
    q.push({x,y});
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        if(g[i][j]=='B'){
            while(1){
                // deb(ans);
                ans.pb(dd[i][j]);
                // cout<<i<<","<<j<<": "<<dd[i][j]<<endl;
                if(ans.back()=='R'){ j--;}
                if(ans.back()=='L'){ j++; }

                if(ans.back()=='D'){ i--;}
                if(ans.back()=='U'){ i++;}
                if(i==x && j==y) break;
            }
            break;
        }
        if(i+1<n && g[i+1][j]!='#' && !vis[i+1][j]){
            q.push({i+1, j});
            dd[i+1][j]='D';
            vis[i+1][j]=1;
        }
        if(i-1>=0 && g[i-1][j]!='#' && !vis[i-1][j]){
            q.push({i-1, j});
            dd[i-1][j]='U';
            vis[i-1][j]=1;
        }
        if(j+1<m && g[i][j+1]!='#' && !vis[i][j+1]){
            q.push({i, j+1});
            dd[i][j+1]='R';
            vis[i][j+1]=1;
        }
        if(j-1>=0&& g[i][j-1]!='#' && !vis[i][j-1]){
            q.push({i, j-1});
            dd[i][j-1]='L';
            vis[i][j-1]=1;
        }
    }
    // deb(dd)
    // deb(ans)
    if(ans.size()>0){
        cout<<"YES"<<endl;
        reverse(all(ans));
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }else cout<<"NO"<<endl;
    // cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    solve2();

    

    return 0;
}