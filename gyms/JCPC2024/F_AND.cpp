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
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


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
int x,a,b;

vector<pi> ans;
vector<pi> rec(int i, vector<pi> v){
    if(i<0 || (v.size()>ans.size() && !ans.empty())){
        return v;
    }
    deb(i) deb(v)
    if((x>>i)&1){
        deb(i)
        if(!((a>>i)&1)) v.pb({0,i});
        if(!((b>>i)&1)) v.pb({1,i});
        vector<pi> ret = rec(i-1,v);
        if(ans.size()>ret.size()) return ans = ret;
        else return ret;
    }
    else{
        vector<pi> tmp = v;
        if(!((a>>i)&1)) tmp.pb({0,i});
        if(!((b>>i)&1)) tmp.pb({1,i});
        // if(tmp.size() < ans.size()) ans = tmp;
        vector<pi> ret = rec(i-1, v);
        // if(ret.size() < ans.size()) ans = ret;
        if(ans.size()==0) ans = tmp;
        if(tmp.size() < ans.size()) return ans = tmp;
        if(ret.size() < ans.size()) return ans = ret;
        else return ans;
    }
}

void solve(){
    cin>>a>>b>>x;
    vector<pi> tmp;
    ans = rec(30,tmp);
    cout<<ans.size()<<endl;
    for(auto [type, ind]: ans){
        cout<<(type?"b":"a")<<" "<<ind<<endl;
    }
    
}

int main(){
    FASTIO;

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
