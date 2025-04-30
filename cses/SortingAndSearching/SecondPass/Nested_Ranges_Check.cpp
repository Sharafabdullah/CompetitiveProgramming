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

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve(){
    cin >> n;
    map<int,int> front_comp, back_comp;
    map<int,int> front_end, back_end;
    
    int f_ind = 1, b_int = 1;
    vector<tuple<int,int,int>> v;
    vector<int> ordered;
    rep(i,0,n){
        int a, b;
        cin >> a >> b;
        v.pb({a, b, i});
        ordered.pb(a);
        ordered.pb(b);
    }
    sort(all(ordered));
    int ind = 1;
    for(int elm: ordered){
        if(!front_comp.count(elm)){
            front_comp[elm] = ind;
            back_comp[ind] = elm;
            ind++;
        }
    }

    sort(all(v));


    for(auto& [f, s, i] : v){
        f = front_comp[f];
        s = front_comp[s];
    }
    vector<vi> begin_here(ind + 10);
    vector<vi> end_here(ind + 10);

    ordered_set<pi> current_set, finished_sets;

    for(int i = 0; i < n; i++){
        auto [f,s,ind] = v[i];
        begin_here[f].pb(i);
        end_here[s].pb(i);
    }

    set<int> contains, not_contains;

    vector<int> containes_out(n), contained_out(n);

    rep(i,0,ind + 10){
        for(auto finish_ind:end_here[i]){
            auto [f,s,i] = v[finish_ind];
            finished_sets.insert({f,finish_ind});
        }
        for(auto ordered_ind:end_here[i]){
            auto [f,s,org_i] = v[ordered_ind];
            containes_out[org_i] = finished_sets.size() - finished_sets.order_of_key({f,-inf}) - 1;
            contained_out[org_i] = current_set.order_of_key({f,inf})-1;
        }
        for(auto ordered_ind: end_here[i]){
            auto [f,s,org_i] = v[ordered_ind];
            current_set.erase({f, ordered_ind});
        }
        
        for(auto ordered_ind: begin_here[i]){
            auto [f,s,org_i] = v[ordered_ind];
            current_set.insert({f, ordered_ind});
        }
    }

    // rep(i,0,n){
    //     if(containes_out[i]) cout<<1<<" ";
    //     else cout<<0<<" ";
    // }
    // cout<<endl;
    // rep(i,0,n){
    //     if(contained_out[i]) cout<<1<<" ";
    //     else cout<<0<<" ";
    // } 
    rep(i,0,n) cout<<containes_out[i]<<" ";
    cout<<endl;
    rep(i,0,n) cout<<contained_out[i]<<" ";
}

void solve2(){
    cin>>n;
    vector<array<int,3>> v(n);
    rep(i,0,n){
        cin>>v[i][0]>>v[i][1];
        v[i][2] = i;
    }
    sort(all(v));
    
    multiset<int> finished_begin, current;

    for(auto [f,s,i]:v){

    }

}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
        // solve2();

    return 0;
}
