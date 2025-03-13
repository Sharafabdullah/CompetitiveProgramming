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

const int N = 104, M = 26;
int k,n,m;
vs v;
vvi g(M);

void solve(){
    cin>>n;
    vi sz(n);
    rep(i,0,n){
        string str; cin>>str;
        sz[i] = str.size();
        while(str.size()<N){
            str.pb('a'-1);
        }
        v.pb(str);
    }
    // deb(v)
    vi id(n,1);
    int cur = 2;
    vi inDeg(26);
    rep(i,0,(int)N){
        rep(j,1,n){
            if(v[j][i]=='a'-1 || v[j-1][i]=='a'-1) continue;
            bool same = 1;
            rep(k,0,i){
                if(v[j][k]!=v[j-1][k]) same = 0;
            }

            if(same && v[j][i]!=v[j-1][i]){
                g[v[j-1][i]-'a'].pb(v[j][i]-'a');
                inDeg[v[j][i]-'a']++;
            }

        }
        rep(j,1,n){
            if(id[j] == id[j-1] && v[j][i]!=v[j-1][i]){
                id[j] = cur++;
            }
            // else id[j] = cur;

        }
    }
    deb(id)
    deb(g)
    queue<int> q;
    rep(i,0,26){
        if(!inDeg[i]) q.push(i);
    }
    deb(q.size())
    string ans;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        ans.pb(cur+'a');
        for(int adj: g[cur]){
            inDeg[adj]--;
            if(!inDeg[adj]){
                q.push(adj);
            }
        }
    }
    deb(ans)
    if(ans.size() !=26){
        cout<<"Impossible"<<endl;
        return;
    }
    rep(i,1,n){
        bool same = 1;
        rep(j,0,sz[i]){
            if(v[i-1][j]!=v[i][j]) same = 0;
        }
        if (same && sz[i] < sz[i-1]) {
            cout << "Impossible" << endl;
            return;
        }

    }
    cout<<ans<<endl;
    
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