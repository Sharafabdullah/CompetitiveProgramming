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

const int N = 3e5, M = 10;
int k,n,m;


const int S = 70;
const int MAXQ = 160;

int queries_made_no = 0;
bool ask(int u) {
  cout << "? " << u << endl;
  fflush(stdout);
  bool yes;
  cin >> yes;
  queries_made_no += !yes;
  return yes;
}
void answer(int u) {
  cout << "! " << u << endl;
  fflush(stdout);
}

void solve() {
  queries_made_no = 0;
  
  int n;
  cin >> n;
  
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  deb(adj)
  int leaf = 0;
  vector<int> max_depth(n + 1);
  auto dfs = [&](auto &self, int u, int p) -> void {
    if (u != 1 && (int)adj[u].size() == 1) {
      leaf = u;
    }
    
    max_depth[u] = 1;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      self(self, v, u);
      max_depth[u] = max(max_depth[u], max_depth[v] + 1);
    }
  };
  dfs(dfs, 1, 0);
  
  vector<int> path;
  auto make_path = [&](auto &self, int u, int p) -> void {
    path.pb(u);
    
    vector<int> good;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      
      if (max_depth[v] >= S) {
        good.pb(v);
      }
    }
    
    if ((int)good.size() == 1) { // oops
      self(self, good[0], u);
      return;
    }
    for (int v : good) {
      if (ask(v)) {
        self(self, v, u);
        break;
      }
    }
  };
  make_path(make_path, 1, 0);
  
  if (ask(leaf)) {
    answer(leaf);
    return;
  }
  while (queries_made_no < S + 10) {
    ask(leaf);
  }
  
  int k = path.size();
  int st = 0, dr = k - 1;
  while (st < dr) {
    int mid = (st + dr + 1) / 2;
    
    if (ask(path[mid])) {
      st = mid;
    } else {
      dr = max(mid - 2, 0);
      st = max(st - 1, 0);
    }
  }
  
  answer(path[st]);
}

int32_t main() {
    // FASTIO;
  int T;
  cin >> T;
  
  while (T--) {
    solve();
    cout << endl;
  }
}

