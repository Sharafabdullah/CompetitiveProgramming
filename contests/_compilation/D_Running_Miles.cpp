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

template <class T> struct SegmentTree{
    #define L (2*node + 1)
    #define R (2*node + 2)
    #define md ((l+r)/2)
private:
    vector<T> seg;
    T skip = 0;
    int sz = 1;
    T merge(T x, T y){
        return max(x, y);
    }
    void build(int l, int r, int node, vi& org){
        if(l==r){ 
            if(l<org.size()) seg[node]=org[l];
            return;
        }

        build(l, md, L, org);
        build(md+1, r, R, org);
        seg[node] =merge(seg[L], seg[R]);
    }

    void update(int l, int r, int node, int ind, T val){
        if(l==r){
            seg[node] = val;
            return;
        }

        if(ind<=md) update(l, md, L, ind, val);
        else update(md+1, r, R, ind, val);
        
        seg[node] = merge(seg[L], seg[R]);
    }

    T query(int l, int r, int node, int lq, int rq){
        if(r<lq || l > rq) return skip;
        if(l>=lq && r<=rq) return seg[node];

        return merge(query(l, md, L, lq,rq), query(md+1, r, R, lq,rq));
    }

public:
    SegmentTree(vi& arr){
        while(sz<(int)arr.size()) sz*=2;
        seg = vector<T>(sz*2,skip);
        build(0, sz-1, 0, arr);
    }
    
    void update(int ind, T val){
        update(0, sz-1, 0, ind, val);
    }

    T query(int l, int r){
        return query(0, sz-1, 0, l, r);
    }
#undef L
#undef R
#undef md
};

void solve(){
    cin>>n;
    vi a(n), pref(n);
    vector<pair<ll,ll>> bigThree(3);
    ll ans = 0;
    rep(i,0,n)
    {
        cin>>a[i];
        if(i<3) {bigThree[i] = {a[i], i};ans+=a[i];}
    }
    sort(all(bigThree));
    ans-=2;
    SegmentTree<ll> sg(a);
    deb(bigThree)

    int l = 0, h = 2;
    while(h < n){
        int lo_ind = inf, bInd = 0;
        vi indecies(3);
        map<int,int> mp;
        rep(i,0,3){
            indecies[i] = bigThree[i].second;
            mp[bigThree[i].second] = i;
        }
        sort(all(indecies));
        deb(l,h)
        deb(bigThree)
        deb(indecies)

        ll lo = h+1, hi = n-1;
        auto cmp = [&](ll md){
            if(sg.query(h + 1,md) >= bigThree[0].first) return true;
            return false;
        };
        while(lo<=hi){
            ll md = lo + (hi-lo)/2;
            if(cmp(md)) hi = md - 1;
            else lo = md+1;
        }
        deb(lo)
        if(lo >=n) break;

        ll lo_ind_replace = (indecies[1]-indecies[0]) + a[lo] - bigThree[mp[indecies[0]]].first;
        ll min_val_replace = a[lo] - bigThree[0].first;

        if(lo_ind_replace >= min_val_replace){
            bigThree[mp[indecies[0]]] = {a[lo], lo};
        }
        else{
            bigThree[0] = {a[lo], lo};
        }
        sort(all(bigThree));
        l = min({bigThree[0].second, bigThree[1].second, bigThree[2].second});
        h = lo;
        ans = max(ans, (ll)bigThree[0].first+ bigThree[1].first+ bigThree[2].first - (h - l));
    }
    cout<<ans<<endl;
}
int sol(vector<int>& b) {
    int n = b.size();
    vector<int> left(n, INT_MIN), right(n, INT_MIN);

    for (int i = 1; i < n; ++i)
        left[i] = max(left[i - 1], b[i - 1] + (i - 1));
    for (int i = n - 2; i >= 0; --i)
        right[i] = max(right[i + 1], b[i + 1] - (i + 1));

    int ans = INT_MIN;
    for (int j = 1; j < n - 1; ++j)
        ans = max(ans, left[j] + b[j] + right[j]);

    return ans;
}

void solve2(){
    cin>>n;
    vi a(n); 
    rep(i,0,n) cin>>a[i];
    cout<<sol(a)<<endl;
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
