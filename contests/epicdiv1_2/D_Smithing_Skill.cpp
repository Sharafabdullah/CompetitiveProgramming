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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 1e6+1, M = 10;
int k,n,m;

template<typename T>
struct cmp {
    bool operator()( T& p1,  T& p2)  {
        return  p1.second - p1.first > p2.second - p2.first;
    }
};
void solve(){
    cin>>n>>m;
    vi a(n), b(n), c(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    rep(i,0,m) cin>>c[i];
    set<int> s;
    map<int, int> mp;
    vector<pi> vp(n);
    rep(i,0,n){
        vp[i] = {a[i], b[i]};}

    sort(vp.begin(), vp.end(), cmp<pi>());
    int cur = inf;
    rep(i,0,n){
        auto [a, b]= vp[i];
        if(cur>a){
            s.insert(a);
            mp[a] = a-b;
        }
        cur = min(a,cur);
    }
    deb(vp)
    deb(s)
    ll ans = 0;
    map<int,int> calc;
    int prev = 0;
    int cnt = 0;
    for(int req: s){
        if(!cnt){
            prev = req;
            calc[req] = 2;
            cnt++;
            continue;
        }
        calc[req] = 2;
        int tmp = req - mp[req];
        if(tmp>prev){
            calc[req] += (tmp-prev)/mp[prev];
        }
        prev = req;

    }
    rep(i,0,m){
        auto it = s.lower_bound(c[i]);
        if(it!=s.begin()) it--;
        int cur = c[i];
        bool f = 1;
        while(it!=s.begin()){
            int until = *it;int step = mp[until]; 
            // deb(cur)
            //  deb(until)
            // deb(step)
            if(cur-until >= 0){
                ans += (cur-until)/step + 1;
                // if(!f) calc[until]+= (cur-until)/step + 1;
                cur -= ((cur-until)/step + 1)*step;
            }
            f = 0;
            it--;
        }
        int until = *it;int step = mp[until]; 
        if(cur-until >= 0) {
            ans += (cur-until)/step + 1;
            cur -= ((cur-until)/step + 1)*step;
        }

    }
    cout<<2*ans<<endl;
}

void solve2(){
    cin>>n>>m;
    vi a(n), b(n), c(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    rep(i,0,m) cin>>c[i];

    vector<pi> vp(n);
    rep(i,0,n){
        vp[i] = {a[i], b[i]}; 
    }
    sort(all(vp));
    deb(vp)
    vi best(N,inf);
    int j = 0;
    for (int i = 1; i < N; i++)
    {
        int cur = inf;
        while(j< vp.size() && vp[j].first == i){
            cur = min(cur, vp[j].first - vp[j].second);
            j++;
        }
        // deb(cur)
        best[i] = min(best[i-1], cur);
    }
    vi times(N,0);
    for (int i = 1; i < N; i++)
    {   
        times[i] = max(times[i-1],( i>=best[i]? times[i-best[i]]+1:0));
    }
    ll ans = 0;
    rep(i,0,m){
        if(c[i]>=N){
            ans+= (c[i]-N)/best[N-1] + 1;
            c[i] -= ((c[i]-N)/best[N-1] + 1)*best[N-1];
        }
        ans+= times[c[i]];

    }
    cout<<ans*2<<endl;
    // deb(vp)
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}