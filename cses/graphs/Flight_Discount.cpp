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
// #define int long long

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e18+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
ll k,n,m;

struct state{
    ll to;
    ll cost;
    bool cuponUsed;
    state(ll t, ll c, ll u):to(t), cost(c), cuponUsed(u){
    }
    bool operator>(const state& s) const {
        return s.cost < this->cost;
    }
};

void solve(){
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> g(n);
    rep(i,0,m){
        int a,b,c;
        cin>>a>>b>>c; a--,b--;
        g[a].pb({b, c});
    }
    priority_queue<state, vector<state>, greater<state>> pq;
    vll used(n, inf), unused(n, inf);

    state tmp = state(0, 0, 0);
    pq.push(tmp);
    // cout<<"YY"<<endl;
    while(!pq.empty()){
        auto [node, d, f] = pq.top(); pq.pop();
        if(f==1){
            if(d > used[node])continue;
        }
        if(f==0){
            if(d > unused[node]) continue;
        }
        for(auto [to, c]: g[node]){

            if(f==1 && c + d < used[to] ){
                used[to] = c+d;
                pq.push(state(to, c+d, 1));
            }
            if(f==0){
                if(d + c/2 < used[to]){
                    used[to] = d + c/2;
                    pq.push(state(to, d+c/2, 1));
                }
                if(d+c <unused[to]){
                    unused[to] = d+c;
                    pq.push(state(to, d+c, 0));
                }
            }
        }
    }
    cout<<used[n-1]<<endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();

    

}