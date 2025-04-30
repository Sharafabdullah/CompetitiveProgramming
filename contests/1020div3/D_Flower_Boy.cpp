#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repd(i, a, b) for (int i = a-1; i >= b; --i)
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

void solve(){
    cin>>n>>m;
    vi a(n), b(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
    auto fun= [&](vi& a, vi& b){ 
        int skipped = 0, i = n-1, j = m - 1;
        int ind = n-1;
        deb(a)
        int ans = 0;
        while(i >= 0 && j >= 0){
            if(a[i]>=b[j]){
                i--,j--;
                ind = i;
            }
            else{
                i--;
            }
            if(j >= 0 && i < 0 && skipped==0){    
                ans = b[j];
                j--;
                skipped = 1;
                i = ind;
            }
        }
        deb(i,j)
        if(j!=-1) ans = inf;
        return ans;
    };
    ll ans = fun(a,b);
    reverse(all(a));
    reverse(all(b));
    ans = min(ans, (ll)fun(a,b));
    if(ans!=inf){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

void solve2(){
    cin >> n >> m;
    vi a(n), b(m);
    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];

    // 1) Build posL[j] = index in a where we match b[0..j] greedily from the left
    const int INF = n + 5;
    vector<int> posL(m, INF);
    {
        int i = 0;
        rep(j,0,m){
            while(i < n && a[i] < b[j]) i++;
            if(i < n){
                posL[j] = i;
                i++;
            } else {
                break;    // once we fail, all further posL stay INF
            }
        }
    }

    // 2) Build posR[j] = index in a where we match b[j..m-1] greedily from the right
    vector<int> posR(m, -1);
    {
        int i = n - 1;
        for(int j = m - 1; j >= 0; j--){
            while(i >= 0 && a[i] < b[j]) i--;
            if(i >= 0){
                posR[j] = i;
                i--;
            } else {
                break;   // once we fail, all earlier posR stay -1
            }
        }
    }

    // 3) If we can already match all m without any insertion, answer = 0
    if (posL[m-1] != INF) {
        cout << 0 << "\n";
        return;
    }

    // 4) Prepare the unique sorted list of candidates k = distinct b[j]
    vi sorted = b;
    sort(all(sorted));
    sorted.erase(unique(all(sorted)), sorted.end());

    // 5) Test function: is there some j0 where inserting k >= b[j0] works?
    auto canWithK = [&](ll k){
        rep(j0,0,m){
            if (k < b[j0]) continue;
            // prefix [0..j0-1] must fit in a[0..posL[j0-1]]
            int left_end = (j0 == 0 ? -1 : posL[j0-1]);
            if (j0 > 0 && left_end == INF) break;
            // suffix [j0+1..m-1] must fit in a[posR[j0+1]..end]
            int right_start = (j0 == m-1 ? n : posR[j0+1]);
            // if j0==m-1 we only need prefix; otherwise suffix must start strictly after left_end
            if (j0 == m-1 || right_start > left_end) 
                return true;
        }
        return false;
    };

    // 6) Binary‐search the smallest k in sorted[] that makes canWithK(k)==true
    int lo = 0, hi = (int)sorted.size() - 1, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canWithK(sorted[mid])) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << (ans < 0 ? -1 : sorted[ans]) << "\n";
}
int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    cin >> t;
    while(t--)
        // solve();
        solve2();

    return 0;
}
