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

const int N = 5e5+10, M = 10;
int k,n,m;

map<int, pair<int,bool>> g[N];
int vis[N], inStack[N];
vi ans;
stack<int> st;

int s=-1,e=-1;
void dfs(int cur, int par){
    vis[cur]++;
    st.push(cur);
    inStack[cur]++;
    for(auto [ch, info]: g[cur]){
        if(s!=-1) break;
        if(ch==par) continue;
        auto [rep, spare] = info;
        if(rep % 2 ==0 && spare==0) continue;

        if(vis[ch]<rep) dfs(ch, cur);
        else if(inStack[ch]>=rep){
            s=ch;
            ans.pb(ch);
            while(!st.empty() && st.top()!=s){
                ans.pb(st.top());
                st.pop();
            }
            ans.pb(ch);
        }
    }
    if(!st.empty()) st.pop();
    inStack[cur]--;
}

void solve(){
    cin>>n>>m;
    rep(i,1,n+1) g[i].clear();
    clr(vis); clr(inStack);
    ans.clear();
    while(!st.empty()) st.pop();

    s=-1, e=-1;
    int f,t,c;
    while(m--){
        cin>>f>>t>>c;
        g[f][t].first++;
        if(!c) g[f][t].second==1;

        g[t][f].first++;
        if(!c) g[t][f].second==1;
    }
    dfs(1,0);
    if(s==-1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<ans.size()-1<<endl;
        for(int i: ans) cout<<i<<" ";
        cout<<endl;
    }
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}