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

const ll inf = 1e9;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n>>k;
    vvi a(k, vi(n));
    rep(i,0,k){
        rep(j,0,n) cin>>a[i][j];
    }
    map<int,int> mp;
    bool can = 1;
    int ms = a[0][0], msp = 0;
    pi msr = {0, inf+5};
    int ctr= inf;
    rep(i,1,n){
        mp[a[0][i]] = ctr;
        ctr-=2;
    }
    rep(i,1,k){
        rep(j,1,n){
            if(!msp && a[i][j]==ms){
                if(j>1) msr.second = min(msr.second,mp[a[i][j-1]]);
                if(j<n-1) msr.first = max(mp[a[i][j+1]], msr.first);
                if(msr.second - msr.first == 2){ msp = msr.first + 1;mp[ms]=msp;}
                if(msr.second - msr.first < 2) can = 0; 
            }
            // cout<<a[i][j] << " "<<mp[a[i][j]]<<endl;
            if(msp==0 && (a[i][j]==ms || a[i][j-1]==ms)) continue;
            if(j>1 && mp[a[i][j]] > mp[a[i][j-1]]) can=0;
            if(!can) break;
        }
        // cout<<endl;
        if(!can) break;
    }
    cout<<(can?"YES":"NO")<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}