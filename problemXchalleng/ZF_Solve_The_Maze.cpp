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
#define coutfloat(n,d)     cout << fixed << setprecision(d) << n << endl
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

vector<string> mz;

void solve(){
    cin>>n>>m;
    mz = vector<string>(n);
    rep(i,0,n) cin>>mz[i];
    auto valid = [&](int r, int c){
        if(r >= n || r< 0 || c>=m || c<0 || mz[r][c]=='B') return 0;
        if(mz[r][c]=='G') return 2;
        return 1;
    };
    
    vector<pi> goods;
    rep(i,0,n){
        rep(j,0,m){
            if(mz[i][j]=='B'){
                rep(k,0,4){
                    int ni = i+dx[k], nj = j + dy[k];
                    int val =valid(ni,nj);
                    if(val==1){
                        mz[ni][nj] = '#';
                    }
                    if(val==2){
                        cout<<"No"<<endl;
                        return;
                    }
                }
            }
            if(mz[i][j]=='G'){
                goods.pb({i,j});
            }
        }
    }
    deb(mz)
    vector<vb> vis(n, vb(m));
    vvi can(n, vi(m));
    can[n-1][m-1] =1;
    auto dfs = [&](auto self, int r, int c){
        if(r==n-1 && c == m-1) {return true;}
        if(can[r][c]) {
            // if(can[r][c]==1) return true;
            // else if(can[r][c]==2) return false;
            return true;
        }
        vis[r][c] = 1;
        bool f= 0;
        rep(i,0,4){
            int nr = r + dx[i], nc = c + dy[i];
            if(nr < n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc] && mz[nr][nc]!='#'){
                if( self(self, nr,nc)) {
                    f = 1;
                    can[r][c] = 1;
                    return true;
                }
            }
        }
        // if(!f && !can[r][c]) can[r][c] = 2;
        return false;
    };
    // vis.assign(n, vb(m,0));
    for(auto [r,c]:goods){
        deb(r) deb(c)
        if(!dfs(dfs, r,c)){
            cout<<"No"<<endl;
            return;
        }
        vis.assign(n, vb(m,0));
    }
    cout<<"Yes"<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}