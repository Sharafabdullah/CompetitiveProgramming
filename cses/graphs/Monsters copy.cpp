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
// const string dir =""
const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 1001, M = 10;
int k,n,m;

vs g(N);
bool won = 0;
string ans;
void bfs(queue<pi>& q, vvi& times, bool a){
    int t= 1, sz = q.size();
    vvb vis(n, vb(m));
    vector<vector<pi>> father(n, vector<pi>(m));
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        sz--;
        deb(i) deb(j)
        if(won) break;
        auto valid = [&](int i, int j){
            // if(a && t >= times[i][j]) return false;
            return i>=0 && j>=0 && i<n && j<m && g[i][j]!='#' && !vis[i][j] && (!a || a&&t<times[i][j]);
        };
        rep(k,0,4){
            int ni = i + dx[k], nj = j + dy[k];
                deb('v')
            if(valid(ni,nj)){
                vis[ni][nj] = 1;
                if(!a) times[ni][nj] = min(t, times[ni][nj]);
                else{
                    father[ni][nj] = {i,j};
                }
                q.push({ni,nj});

                if(a && (ni==0 || nj == 0 || ni == n-1 || nj == m-1)){
                    won = 1;
                    while(g[ni][nj] != 'A' ){
                        int ii = father[ni][nj].first;
                        int jj = father[ni][nj].second;
                        if(ni == ii){
                            if(nj == jj - 1){
                                ans+='L';
                            }
                            else{
                                ans+='R';
                            }
                            nj = jj;
                        }
                        else{
                            if(ni == ii - 1){
                                ans+='U';
                            } else ans+='D';
                            ni = ii;
                        }
                    }
                }
            }
            if(won) break;
        }
        if(!sz){
            sz = q.size();
            t++;
        }
    }
}
void solve(){
    cin>>n>>m;
    rep(i,0,n) cin>>g[i];
    queue<pi> q;
    int ci,cj;
    vvi times(n, vi(m, inf));
    rep(i,0,n) rep(j,0,m) {
        if(g[i][j]=='M'){ q.push({i,j});times[i][j] = 0;}
        if(g[i][j]=='A') {ci = i, cj = j;}
        }
    bfs(q, times, 0);
    deb(times)
    deb(q.size())
    q.push({ci,cj});
    if(ci == 0 || cj == 0 || ci == n-1 || cj == m-1) won=1;
    bfs(q, times, 1);
    if(won){
        reverse(all(ans));
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    } else cout<<"NO"<<endl;
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