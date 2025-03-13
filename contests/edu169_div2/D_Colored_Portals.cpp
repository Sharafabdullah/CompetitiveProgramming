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
    cin>>n>>k;
    map<string, int> mp;
    mp["BG"] = 0;
    mp["BR"] = 1;
    mp["BY"] = 2;
    mp["GR"] = 3;
    mp["GY"] = 4;
    mp["RY"] = 5;
    vs org(n);
    vi ar(n); 
    rep(i,0,n){
        string str; cin>>str;
        org[i] = str;
        ar[i] = mp[str];
    }
    vvi pref(6, vi(n+1,-1)), suf(6, vi(n+1, -1));

    rep(i,1,n+1){
        rep(cur,0,6){
            pref[cur][i] = pref[cur][i-1];
            if(ar[i-1]==cur) pref[cur][i]=i-1;
        }
    }
    for(int i = n-1; i>=0; i--){
        rep(cur,0,6){
            suf[cur][i] = suf[cur][i+1];
            if(ar[i]==cur) suf[cur][i]=i;
        }
    }
    deb(ar)
    deb(pref[0])
    deb(pref[1])


    deb(suf[0])
    deb(suf[1])
    deb(suf[3])
    

    while(k--){
        int a,b; cin>>a>>b; a--,b--;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        if(b<a) swap(a,b);
        vs s(4,"");
        s[0] += org[a][0]; s[0]+=org[b][0];
        s[1] += org[a][0];s[1]+=org[b][1]; 
        s[2] += org[a][1]; s[2]+=org[b][0]; 
        s[3]+= org[a][1]; s[3]+=org[b][1]; 
        for(string& str: s){
            if(str[1]=='B' ||( str[1]=='G' && str[0]!='B') || str[0]=='Y')swap(str[0],str[1]);
        }
        deb(s)
        vi v(4,-1);

       if(mp.find(s[0])!=mp.end()) v[0] = mp[s[0]];
       if(mp.find(s[1])!=mp.end()) v[1] = mp[s[1]];
       if(mp.find(s[2])!=mp.end()) v[2] = mp[s[2]];
       if(mp.find(s[3])!=mp.end()) v[3] = mp[s[3]];
       deb(v)
        int ans1=inf, ans2=inf;
        int nxt=inf,prv=-inf;
        deb(a)
        for(int val: v){
            if(val==-1) continue;
            deb(val) deb(a+1)
            deb(suf[val][a+1])
            
            if(suf[val][a+1]!=-1) nxt =min(nxt, suf[val][a+1]);
            if(pref[val][a+1]!=-1)  prv = max(prv, pref[val][a+1]);
        }
        if(nxt == inf && prv==-inf){
            cout<<-1<<endl;
            continue;
        }
        if(nxt != inf){
            ans1 = nxt - a;
            ans1 += abs(nxt - b);
        }
        if(prv!=-inf){
            ans2 = a - prv;
            ans2 += abs(prv - b);
        }
        cout<<min(ans1,ans2)<<endl;
    }
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}