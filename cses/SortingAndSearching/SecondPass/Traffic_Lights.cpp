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

struct cmp {
    bool operator()(const pi& a, const pi& b) const {
        int gapA = a.second - a.first;
        int gapB = b.second - b.first;
        // if gaps are equal, compare the starting point
        return (gapA == gapB) ? a.first < b.first : gapA > gapB;
    }
};

void solve(){
    int x;
    cin>>x>>n;
    int a;
    set<pi, cmp> st;
    set<int> beg;
    beg.insert(0);

    st.insert({0,x});
    map<int,int> mp;
    mp[0] = x;

    rep(i,0,n){
        cin>>a;
        auto b = *(--beg.upper_bound(a));
        int e = mp[b];

        deb(b, a,e)
        st.erase({b,e});
        st.insert({b, a});
        st.insert({a, e});
        beg.insert(a);
        // cout<<"Set:" <<endl;
        // for(auto [f, s]: st) cout<<f<<" "<<s<<endl;

        mp[b] = a;
        mp[a] = e;

        deb(*st.begin())

        cout<<(*st.begin()).second - (*st.begin()).first<<" ";

    }
}

void solve2(){
    int x, cnt= 0;
    cin>>x>>n;
    set<int> lights;
    map<int,int> len;
    lights.insert(0); lights.insert(x);
    len[x]++;
    while(n--){
        cin>>k;
        // deb(*len.rbegin());
        auto [it,p]  = lights.insert(k);
        int nVal = *next(it);
        int pVal = *prev(it);
        len[nVal - pVal]--;
        if(len[nVal-pVal]==0) len.erase(len.find(nVal - pVal));
        len[k - pVal]++; len[nVal - k]++;
        // for(auto [k,v]: len){
        //     cout<<k<<" "<<v<<endl;
        // }
        // cout<<"________"<<endl;
        cout<< (*len.rbegin()).first<<" ";
    }
        // deb(*len.rbegin());
 
}
int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    // cin >> t;
    while(t--)
        // solve();
        solve2();

    return 0;
}
