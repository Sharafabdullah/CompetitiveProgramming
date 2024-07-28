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

const int N = 2e5+10, M = 10;
int k,n,m;


void solve(){
    cin>>n;
    vi b(n), a(n);
    set<int> s1,s2;
    map<int,int> ind;
    rep(i,0,n){
        cin>>a[i];
        s1.insert(a[i]);
    }
    bool can = 1;
    rep(i,0,n){
        cin>>b[i];
        if(s1.count(b[i])==0) can = 0;
        s2.insert(b[i]);
        ind[b[i]] = i;
    }
    if(s1.size()!=s2.size()){
        can = 0;
    }
    for(int i: s1){
        if(s2.count(i)==0) can = 0;
    }
    if(!can){
        cout<<"NO"<<endl;
        return;
    }
    int pos = 0, neg=0;
    for (int i = 0; i < n; i++)
    {
        if(ind[a[i]]-i > 0){
            pos++;
        }
        if(ind[a[i]]-i < 0){
            neg++;
        }
    }
    
    if((pos&1) && (neg&1)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}

void solve2(){
    cin>>n;
    vi b(n), a(n),perm(n);
    map<int,int> mp;
    int cnt = 0;

    rep(i,0,n) {cin>>a[i];mp[a[i]]=cnt++;}
    rep(i,0,n) {
        cin>>b[i];
        perm[i] = mp[b[i]];
    }
    sort(all(a)); sort(all(b));
    if(a!=b){
        cout<<-1<<endl;
        return;
    }
    
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}