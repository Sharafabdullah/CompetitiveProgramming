#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repd(i, a, b) for (int i = a; i >= b; --i)
#define pb            push_back
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
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
#define deb(...) cerr << "[" << #__VA_ARGS__ << "] = "; _print(__VA_ARGS__); cerr << endl;
#else
#define deb(...)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(const char* s) {cerr << s;}


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename... Args>
void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
char      dr[] = {'R', 'L', 'D', 'U'};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;

vector<string> g;
bool can = 0;
vector<vb> vis;
vvi m_time;
string path;

void dfs(int i, int j, int depth){
    vector<vector<pi>> parent(n, vector<pi>(m));
    queue<pi> q, nq;
    q.push({i,j});
    vis[i][j] = 1;
    int fi, fj;
    while(!q.empty()){
        auto [ci, cj] = q.front(); q.pop();
        deb(ci,cj,depth)
        rep(dir, 0,4){
            int ni = ci + dx[dir], nj = cj + dy[dir];
            if(ni < 0 || ni >= n || nj<0 || nj>=m){
                can = 1;
                fi = ci;
                fj = cj;
                break;
            }
            if(depth >= m_time[ni][nj] || g[ni][nj] == '#' || vis[ni][nj]) continue;
            parent[ni][nj] = {ci, cj};
            vis[ni][nj] = 1;
            nq.push({ni,nj});
        }
        if(q.empty()){
            while(!nq.empty()){
                q.push(nq.front());
                deb(nq.front())
                nq.pop();
            }
            depth++;
        }
    }
    if(can){
        pi cur = {fi, fj};
        while(cur != make_pair(i,j)){
            pi par = parent[cur.first][cur.second];
            if(par.first - cur.first == 1) path.pb('U');
            if(par.first - cur.first == -1) path.pb('D');
            if(par.second - cur.second == -1) path.pb('R');
            if(par.second - cur.second == 1) path.pb('L');
            cur = par;
        }
        reverse(all(path));
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n);
    rep(i,0,n) cin>>g[i];
    int ax, ay;
    m_time = vvi(n, vi(m, inf));
    vis = vector(n, vb(m,0));
    queue<pi> q, nq;
    rep(i,0,n){
        rep(j,0,m){
            if(g[i][j]=='A'){
                ax = i, ay = j;
            }
            if(g[i][j]=='M'){
                m_time[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    int d = 1;
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        rep(dir,0,4){
            int ni = i + dx[dir], nj = j + dy[dir];
            if(ni < 0 || ni >= n || nj<0 || nj>=m || m_time[ni][nj]!=inf || g[ni][nj]=='#') continue;
            m_time[ni][nj] = d;
            nq.push({ni,nj});
        }
        if(q.empty()){
            while(!nq.empty()){
                q.push(nq.front());
                nq.pop();
            }
            d++;
        }
    }
    dfs(ax, ay, 1);

    if(!can) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
