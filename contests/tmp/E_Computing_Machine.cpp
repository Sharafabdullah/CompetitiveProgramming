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

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    string a,b,org;
    cin>>n>>a>>b;
    org= a;
    vector<pi> v(n, {inf,-inf});
    rep(i,1,n-1){
        if(b[i]=='0'&&a[i-1]=='0'&&a[i+1]=='0'){
            b[i]='1';
            v[i]={i-1,i+1};
        }
    }
    rep(i,1,n-1){
        if(a[i]=='0'&&b[i-1]=='1'&&b[i+1]=='1'){
            a[i]='1';
            v[i].first = v[i-1].first==inf? i-1: v[i-1].first;
            v[i].second= v[i+1].second==-inf? i+1: v[i+1].second;
        }
    }
    vi psum(n+1);
    rep(i,1,n+1){
        psum[i]= psum[i-1]+ (a[i-1]=='1');
    }
    // deb(psum)
    int l,r,q;
    cin>>q;
    while(q--){
        cin>>l>>r;
        ll ans = psum[r]-psum[l-1];
        l--, r--;
        if(org[l]=='0' && a[l]=='1') ans--;
        if(l!=r && org[r]=='0' && a[r]=='1') ans--;

        if(l+1<r && org[l+1]=='0'&&a[l+1]=='1'&& (v[l+1].first<l || v[l+1].second > r)) ans--;
        if(l+2<r && org[l+2]=='0'&&a[l+2]=='1'&& (v[l+2].first<l || v[l+2].second > r)) ans--;
        if(l+3<r && org[l+3]=='0'&&a[l+3]=='1'&& (v[l+3].first<l || v[l+3].second > r)) ans--;
        if(l+4<r && org[l+4]=='0'&&a[l+4]=='1'&& (v[l+4].first<l || v[l+4].second > r)) ans--;
        cout<<ans<<endl;
    }
    deb(v)
    deb(a)

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}