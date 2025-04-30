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

const ll inf = 1e17+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;
vll costI, costJ;
vector<vll> a;
vector<vll> dp1, dp2;

ll dfs1(int ind, int must_take, int must_not_take){
    int sec_dim = (int)must_take * 2 + must_not_take;
    if(must_not_take && must_take) return inf + 1;
    if(ind >= n){
        return 0;
    }
    if(dp1[ind][sec_dim]!=inf) return dp1[ind][sec_dim];

    bool next_eq = 0, next_greater_one = 0, next_less_one = 0;
    rep(j,0,n){
        if(ind + 1 >= n) continue;
        if(a[ind][j] == a[ind+1][j]) next_eq = 1;
        if(a[ind][j] == a[ind+1][j] - 1) next_greater_one = 1;
        if(a[ind][j] == a[ind+1][j] + 1) next_less_one = 1;
    }

    if(next_eq && next_greater_one && next_less_one){
        return dp1[ind][sec_dim] = inf + 1;
    }
    ll ans = 0;

    if(must_not_take){
        if(next_eq && next_less_one) ans = inf + 1;
        else if(next_eq){
            ans = dfs1(ind + 1, 1, 0);
        }
        else if(next_less_one){
            ans = dfs1(ind + 1, 0, 1);
        }
        else ans = dfs1(ind + 1, 0,0);
        return  dp1[ind][sec_dim] = ans;
    }
    if(must_take){
        if(next_eq && next_greater_one) ans = inf + 1;
        else if(next_eq){
            ans = dfs1(ind + 1, 0, 1) + costI[ind];
        }
        else if(next_greater_one){
            ans = dfs1(ind + 1, 1, 0) + costI[ind];
        }
        else{
            ans =  dfs1(ind + 1, 0, 0) + costI[ind];
        }
        return dp1[ind][sec_dim] = ans;
    }

    if(next_eq){
        if(next_greater_one) ans = dfs1(ind + 1, 1, 0);
        else if(next_less_one) ans = dfs1(ind + 1, 0, 1) + costI[ind];
        else ans = min(dfs1(ind + 1, 0, 1) + costI[ind], dfs1(ind + 1, 1, 0));
        return dp1[ind][sec_dim] = ans;
    }
    if(next_greater_one && next_less_one){
        return dp1[ind][sec_dim] =min(dfs1(ind + 1, 0, 1), dfs1(ind + 1, 1, 0) + costI[ind]);
    }
    else if(next_less_one){
        return dp1[ind][sec_dim] = 
        min(dfs1(ind + 1, 0 , 0) + costI[ind], dfs1(ind + 1, 0, 1));
    }
    else if(next_greater_one){
        return dp1[ind][sec_dim] = 
        min(dfs1(ind + 1, 1 , 0) + costI[ind], dfs1(ind + 1, 0, 0));
    }
    else return dp1[ind][sec_dim] = dfs1(ind + 1, 0, 0);
}

ll dfs2(int ind, int must_take, int must_not_take){
    int sec_dim = (int)must_take * 2 + must_not_take;
    if(must_not_take && must_take) return inf + 1;
    if(ind >= n){
        return 0;
    }
    if(dp2[ind][sec_dim]!=inf) return dp2[ind][sec_dim];

    bool next_eq = 0, next_greater_one = 0, next_less_one = 0;
    rep(i,0,n){
        if(ind + 1 >= n) continue;
        if(a[i][ind] == a[i][ind + 1]) next_eq = 1;
        if(a[i][ind] == a[i][ind + 1] - 1) next_greater_one = 1;
        if(a[i][ind] == a[i][ind + 1] + 1) next_less_one = 1;
    }

    if(next_eq && next_greater_one && next_less_one){
        return dp2[ind][sec_dim] = inf+1;
    }
    ll ans = 0;

    if(must_not_take){
        if(next_eq && next_less_one) ans = inf+1;
        else if(next_eq){
            ans = dfs2(ind + 1, 1, 0);
        }
        else if(next_less_one){
            ans = dfs2(ind + 1, 0, 1);
        }
        else ans = dfs2(ind + 1, 0,0);
        return  dp2[ind][sec_dim] = ans;
    }
    if(must_take){
        if(next_eq && next_greater_one) ans = inf+1;
        else if(next_eq){
            ans = dfs2(ind + 1, 0, 1) + costJ[ind];
        }
        else if(next_greater_one){
            ans = dfs2(ind + 1, 1, 0) + costJ[ind];
        }
        else{
            ans =  dfs2(ind + 1, 0, 0) + costJ[ind];
        }
        return dp2[ind][sec_dim] = ans;
    }

    if(next_eq){
        if(next_greater_one) ans = dfs2(ind + 1, 1, 0);
        else if(next_less_one) ans = dfs2(ind + 1, 0, 1) + costJ[ind];
        else ans = min(dfs2(ind + 1, 0, 1) + costJ[ind], dfs2(ind + 1, 1, 0));
        return dp2[ind][sec_dim] = ans;
    }
    if(next_greater_one && next_less_one){
        return dp2[ind][sec_dim] =min(dfs2(ind + 1, 0, 1), dfs2(ind + 1, 1, 0) + costJ[ind]);
    }
    else if(next_less_one){
        return dp2[ind][sec_dim] = 
        min(dfs2(ind + 1, 0 , 0) + costJ[ind], dfs2(ind + 1, 0, 1));
    }
    else if(next_greater_one){
        return dp2[ind][sec_dim] = 
        min(dfs2(ind + 1, 1 , 0) + costJ[ind], dfs2(ind + 1, 0, 0));
    }
    else return dp2[ind][sec_dim] = dfs2(ind + 1, 0, 0);
}

void solve(){
    cin>>n;
    a = vector<vll>(n, vll(n));
    dp1 = vector<vll>(n + 10, vll(4, inf));
    dp2 = vector<vll>(n + 10, vll(4, inf));
    rep(i,0,n){
        rep(j,0,n){
            cin>>a[i][j];
        }
    }
    costI = vll(n);
    costJ = vll(n);
    rep(i,0,n) cin>>costI[i];
    rep(i,0,n) cin>>costJ[i];
    ll ans = dfs2(0,0,0);
    ans += dfs1(0, 0, 0);
    cout<<(ans>=inf?-1:ans)<<endl;
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
