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

const ll N = 500001, M = 10;
ll k,n,m;

void divisors(ll n, map<ll,ll>& div) 
{ 
    for (ll i=2; i*i<=n; i++) 
    { 
        if (n%i == 0) 
        { 
            div[i]=(n/i);
            if(i*i != n) div[n/i] = i;
        } 
    } 
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve2(){
    cin>>n>>m;
    vi a(n); rep(i,0,n) cin>>a[i];
    map<ll,ll> div;
    divisors(m, div);
    ll ans = 1;
    unordered_map<ll,ll, custom_hash> cur;
    vi tochg(100000);
    rep(i,0,n){
        ll d= div[a[i]];
        if(d==0) continue;
        if(cur.count(d)==0){
            int ind = 0;
            for(auto [k, val]: cur){
                if(k * a[i]> m) continue;;
                tochg[ind++] = k*a[i];
            }
            rep(j,0,ind){
                cur[tochg[j]]++;
            }
            cur[a[i]]++;
        } 
        else {
            ans++;
            cur.clear();
            cur[a[i]]++;
        }
    }
    cout<<ans<<endl;
}



void solve3(){
    cin>>n>>m;
    vi a(n); rep(i,0,n) cin>>a[i];
    unordered_set<int, custom_hash> cur;
    int ans = 1;
    rep(i,0,n){
        if(m%a[i]==0){
            // deb(cur)
            if(cur.count(m/a[i])){
                cur.clear();
                ans++;
                cur.insert(a[i]);
            }
            else{
                vi toAdd;
                for(int elm: cur){
                    if(elm*a[i]>m) continue;;
                    if(elm==1) continue;
                    toAdd.pb(elm * a[i] );
                }
                for(int elm: toAdd){
                    cur.insert(elm);
                }
                cur.insert(a[i]);
            }
        }
    }
    cout<<ans<<endl;
}
  
 
int vis[200010] , vcnt = 0;
 
void solve4(){
	int n , x;
	scanf("%d%d",&n,&x);
    deb(n) deb(x)
	vector< int > arr(n);
	for(int i = 0 ;i < n;i++) scanf("%d",&arr[i]);
 
    // deb(arr)
	int ans = 1;
	vector< int > v(1 , 1);
	long long val;
	vcnt++;
	for(int sz , i = 0 ;i < n;i++){
		if(x % arr[i] != 0) continue;
 
		sz = (int)v.size();
		for(int j = 0 ;j < sz;j++){
			val = (long long)v[j] * arr[i];
			if(x % val != 0 || vis[val] == vcnt) continue;
			vis[val] = vcnt;
			v.push_back((int)val);
		}
		if(vis[x] == vcnt){
			ans++;
			v.clear();
			v.push_back(1);
			v.push_back(arr[i]);
			vcnt++;
		}
	}
	printf("%d\n",ans);
}
int main(){
    // FASTIO;

    int t= 1;
    cin>>t;
    // while(t--) solve2();
    // while(t--) solve3();
    while(t--) solve4();

    return 0;
}