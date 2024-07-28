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
    map<char, pair<int,int>> mp;
    mp['1'] = {1,1};
    mp['2'] = {1,2};
    mp['3'] = {1,3};
    mp['4'] = {2,1};
    mp['5'] = {2,2};
    mp['6'] = {2,3};
    mp['7'] = {3,1};
    mp['8'] = {3,2};
    mp['9'] = {3,3};
    mp['0'] = {4,2};
    string s; cin>>s;
    int mnr = mp[s[0]].first, mnc = mp[s[0]].second;
    int mxr = mp[s[0]].first, mxc = mp[s[0]].second;
    int v = 0;
    bool f1= 0, f2=0;
    if(!f1 && mnr==3 && (mnc==1 || mnc==3)){ v++;f1=1;}
    if(!f2 && mnr==1 && (mnc==1 || mnc==3)) {v++;f2=1;}
    set<char> st;
    st.insert(s[0]);
    rep(i,1,s.size()){
        auto [r,c] = mp[s[i]];
        if(!f1 && (r==3 && (c==1 || c==3)) ) {v++;f1=1;}
        if(!f2 && r==1 && (c==1 || c==3)){ v++;f2=1;}
        st.insert(s[i]);
        mnr = min(r, mnr);
        mnc = min(c, mnc);
        mxr = max(r, mxr);
        mxc = max(c, mxc);
    }
    if((st.count('1')&&st.count('9')) ||(st.count('3')&&st.count('7')) || ((st.count('1') ||st.count('2')||st.count('3'))&&st.count('0'))||(st.count('7')&&st.count('9')&&st.count('1')) || mxr - mnr >=3 ||(st.count('1')&&st.count('7')&&st.count('6'))||(st.count('3')&&st.count('9')&&st.count('4'))||(st.count('2')&&(st.count('6')&&st.count('7')||st.count('4')&&st.count('9')))){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}