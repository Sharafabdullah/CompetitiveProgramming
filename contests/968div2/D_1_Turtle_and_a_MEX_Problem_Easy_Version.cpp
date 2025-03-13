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

void dfs(int cur, vb& vis, vi& val, vvi& g){
    vis[cur] = 1;
    for(int ch: g[cur]){
        if(!vis[ch]){
            dfs(ch, vis,val,g);
            val[cur] = max(val[cur], val[ch]);
        }
    }
}
void solve(){
    cin>>n>>m;
    vector<pi> v(n);
    int mxs = 0, mxe = 0;

    rep(i,0,n){
        int l; cin>>l;
        vi tmp(l);
        rep(j,0,l) cin>>tmp[j];
        sort(all(tmp));
        bool f = 1;int ind =0, end = 1;
        
        tmp.erase(unique(all(tmp)), tmp.end());
        l = tmp.size();
        if(tmp[0]==0){
            ind = 1;
            end = 2;
        }
        else{
            f = 0;
            if(tmp[0]==1){
                ind = 0;
                end = 2;
            }
            else{
                ind = 0;
                end = 1;
            }
        }
        int cur = 0;
        rep(i,1,l){
            if(tmp[i] - tmp[i-1]==1){
                cur++;
                end = cur;
            }
            else{
                if(f&& tmp[i]-tmp[i-1] == 2){
                    f = 0;
                    ind = cur;
                    cur++;
                    end = cur;
                }
                else{
                    f=0;
                    ind = cur;
                    end = cur+1;
                    break;
                }
            }
        }
        v[i] = {ind, end};
        mxs = max(mxs,ind);
        mxe = max(mxe,end);
    }
    deb(v)
    vvi g(mxe+1);
    ll ans = 0;
    vi val(mxe+1);
    vb vis(mxe+1);
    for(auto [f,s]: v){
        g[f].pb(s);
        val[f] = max(val[f], s);
    }
    for(auto [f,s]: v){
        if(!vis[f]){
            vis[f] = 1;
            dfs(f, vis, val,g);
        }
    }
    
}


void solve2(){
    cin>>n>>m;
    int mx = 0;
    rep(i,0,n){
        int l; cin>>l;
        vi a(l);
        map<int,int> mp;
        rep(i,0,l) {cin>>a[i];mp[a[i]]++;}
        int ind = 0, mex = 0, cnt= 0;
        while(cnt<2){
            if(!mp.count(mex)){
                cnt++;
            }
            mex++;
        }
        mex--;
        mx = max(mx, mex);
    }
    deb(mx)
    ll ans =0;
    if(m <= mx){
        ans = 1ll*(m+1) *(mx);
        deb(ans)
    }
    else{
        ans = 1ll*(mx+1)*mx;

        ll sum = 1ll * m*(m+1)/2 - 1ll * mx*(mx+1)/2;
        deb(sum)
        deb(ans)
        ans += sum;
    }
    cout<<ans<<endl;
}
int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        // solve();
        solve2();
    }
    

    return 0;
}