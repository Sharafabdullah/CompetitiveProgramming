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

void solve(){
    cin>>n;
    vi a(n); 
    vi cnt(3);
    int sum = 0;
    vector<set<int>> nums(3);
    rep(i,0,n){
        cin>>a[i];
        cnt[a[i]]++;
        nums[a[i]].insert(i);
        sum+=a[i];
    }
    int ans = 0;
    vector<pi> ansV;
    for(int i = n - 1; i> n - 1 - cnt[2]; i--){
        if(!a[i]){
            if(nums[1].size()&&(*nums[1].begin())<i){
                ans++;
                ansV.push_back({i + 1, *(nums[1].begin())+1});
                a[*nums[1].begin()]--;
                nums[1].erase(nums[1].begin());
                a[i]++;
            }
        }
        if(a[i]==1){
            if(nums[2].size()&&(*nums[2].begin())<i){
                ans++;
                ansV.push_back({i+1, (*nums[2].begin())+1});
                a[*nums[2].begin()]--;
                nums[1].insert(*nums[2].begin());
                nums[2].erase(nums[2].begin());
                a[i]++;
            }
        }
    }
    deb(ans)

    for(int i = n - 1 - cnt[2]; i>n-1-cnt[2] - cnt[1]; i--){
        deb(i)
        if(a[i]==0){
            if(nums[1].size()&&(*nums[1].begin())<i){
                ans++;
                a[*nums[1].begin()]--;
                ansV.push_back({i + 1, *nums[1].begin()+1});
                nums[1].erase(nums[1].begin());
            }
        }
    }
    cout<<ans<<endl;
    for(auto [f,s]: ansV){
        cout<<f<<" "<<s<<endl;
    }

}

int main(){
    FASTIO;

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
