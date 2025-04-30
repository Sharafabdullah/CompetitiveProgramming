#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")


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


const ll inf = 1e18+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;

void solve(){
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> g(n+1);
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
    }
    // Previously: vector<vll> v(2, vll(n+1, inf));
    vector<vll> v(n+1, vll(2, inf));
    
    priority_queue<array<ll,3>, deque<array<ll,3>>, greater<>> pq; 
    // Initially, node 1, type 0 has cost 0
    pq.push({0, 1, 0});
    while(!pq.empty()){
        auto [c_cost, c_node, type] = pq.top();
        pq.pop();

        if(v[c_node][type] < c_cost) continue;

        if(c_node == n) break;

        for(auto [dst, cost]: g[c_node]){
            if(type){
                if(v[dst][1] <= cost + c_cost) continue;
                v[dst][1] = cost + c_cost;
                pq.push({cost + c_cost, dst, 1});
            }
            else{
                if(v[dst][0] > cost + c_cost) {
                    v[dst][0] = cost + c_cost;
                    pq.push({cost + c_cost, dst, 0});
                }
                if(v[dst][1] > cost/2 + c_cost) {
                    v[dst][1] = cost/2 + c_cost;
                    pq.push({cost/2 + c_cost, dst, 1});
                }
            }
        }
    }
    cout<<v[n][1]<<endl;
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
