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
string s = "DURL";

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 1001, M = 10;
int k,n,m;

vector<string> g(N);

void solve(){
    cin>>n>>m;
    rep(i,0,n) cin>>g[i];
    vvi vis(n, vi(m));
    vector<vector<char>> path(n, vector<char>(m,'.'));
    deque<pi> q;
    rep(i,0,n){
        rep(j,0,m){
            if(g[i][j]=='M'){ vis[i][j]  = -1; q.pb({i,j});}
            if(g[i][j]=='A'){ vis[i][j]  = 1; q.pb({i,j});}
        }
    }
    bool won=0;
    string ans;
    while(!q.empty()){
        int sz = q.size();
        vector<pi> as;
        auto isValid = [&](int r, int c){
            return r>=0 && c>=0 && r<n && c<m && !vis[r][c] && g[r][c] !='#';
        };
        auto vis4 = [&](int r,int c, int v){
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dy[i], nc = c+dx[i];
                if((nr==n || nc==m || nr<0 || nc<0) && v==1){
                    won = 1;
                }
                if(isValid(nr,nc)){
                    q.pb({nr, nc});
                    if(v==1) path[nr][nc] = s[i];
                    vis[nr][nc] =v;
                }
            }
        };
        for (int i = 0; i < sz; i++)
        {
            auto [r,c] = q.front(); q.pop_front();
            if(vis[r][c]==1){
                as.pb({r,c});
            }
            if(vis[r][c]==-1){
                vis4(r,c, -1);
            }
        }
        for(auto [r,c]: as){
            vis4(r,c,1);
            if(won) {
                while(path[r][c]!='.'){
                    ans.pb(path[r][c]);
                    // cout<<r<<" "<<c<<endl;
                    if(ans.back()=='R') c--;
                    if(ans.back()=='L') c++;
                    if(ans.back()=='D') r--;
                    if(ans.back()=='U') r++;
                    if(g[r][c]=='A') break;
                }
                break;
            }
        } 
        if(won) break;
    }
    if(won){
        cout<<"YES"<<endl;
        reverse(all(ans));
        cout<<ans.size()<<endl;
        if(ans.size()>0)cout<<ans<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    // deb(path)
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}