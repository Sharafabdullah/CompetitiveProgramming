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

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n;
    vi a(n); rep(i,0,n) cin>>a[i];

    vector<pi> st;
    st.pb({-1,0});
    vi nLeft(n), nRight(n);
    rep(i,0,n){
        int end = st.back().second;
        while(a[i] <= st.back().first){
            st.pop_back();
            end = st.back().second;
        }
        st.pb({a[i],i});
        if(end == i) nLeft[i] = inf;
        else nLeft[i] = i - end;
    }
    st.clear();
    st.pb({-1,n-1});
    rep(i,n,0){
        int end = st.back().second;
        while(a[i] <= st.back().first){
            st.pop_back();
            end = st.back().second;
        }
        st.pb({a[i],i});
        if(end == i) nRight[i] = inf;
        else nRight[i] = end- i;
    }
    map<int,int> mn;
    rep(i,0,n){
        int mx = max(nLeft[i], nRight[i]);
        if(i==0 || i == n-1) mx = min(nLeft[i], nRight[i]);
        if(mx > mn[a[i]]) mn[a[i]] = mx;
    }
    deb(mn)
    deb(nLeft) deb(nRight)


    int minElm = *min_element(all(a));
    int num = 0;
    for(auto it = mn.rbegin(); it!=mn.rend(); it++){
        // cout<<it->first<<" "<<it->second<<endl;
        while(num < n && num < it->second){
            cout<<it->first<<" ";
            num++;
        }
    }
    while(num<n){
        cout<<minElm<<" ";
        num++;
    }


    
}

void solve2(){
    cin>>n;
    vi a(n+1); rep(i,0,n) cin>>a[i];
    vi st, l(n), r(n);

    rep(i,0,n){
        while(!st.empty() && a[i] <= a[ st.back() ]){
            st.pop_back();
        }
        if(st.empty()){
            l[i] = 0;
        } else l[i] = st.back()+1;
        st.pb(i);
    }
    st.clear();
    rep(i,n,0){
        while(!st.empty() && a[i] <= a[ st.back() ]){
            st.pop_back();
        }
        if(st.empty()){
            r[i] = n+1;
        } else r[i] = st.back()+1;
        st.pb(i);
    }
    // deb(l); deb(r)
    vi ans(n+1);
    rep(i,0,n){
        int len = r[i] - l[i] - 1;
        // deb(len)
        ans[len] = max(ans[len], a[i]);
    }
    rep(i,n,1){
        ans[i] = max(ans[i+1], ans[i]);
    }
    rep(i,1,n+1) cout<<ans[i]<<" ";
}
int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--){
        // solve();
        solve2();
    }
    

    return 0;
}