#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define sz(x)         ((int)(x).size())
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))


typedef long long ll;
typedef unsigned long long ull;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<bool>      vb;
typedef vector<vb>        vvb;
typedef vector<string>    vs;
typedef vector<int>       vi;
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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;
vi num,freq(1005);
set<int> ans;
map<vi,int> mp;
void dp(vi freq, int ind, int sum){
    ans.insert(sum);
    if(ind>=n) return;
    // if(mp[freq]) return;
    mp[freq] = 1;
    freq[num[ind]]++;
    dp(freq,ind+1, sum+num[ind]);
    freq[num[ind]]--;
    dp(freq, ind+1,sum);
}
void solve(){
    cin>>n; 
    num.resize(n); for(int& i: num) cin>>i;
    dp(freq, 1, 0);
    dp(freq, 1, num[0]);
    ans.erase(ans.begin());
    cout<<ans.size()<<endl;
    for(int i: ans) cout<<i<<" ";
    // deb(ans)
}

void solve2(){
    cin>>n;
    int sum = 0;
    vi v(n); for(int &i: v) {cin>>i;sum+=i;}
    bitset<1000000> vis;
    vis[0] = 1;
    for(int num: v){
        for(int i = sum; i>=num; i--){
            vis[i] = vis[i] |vis[i - num];
        }
    }
    cout<<vis.count()-1<<endl;
    rep(i,1,sum+1){
        if(vis[i]) cout<<i<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    solve2();
    

    return 0;
}