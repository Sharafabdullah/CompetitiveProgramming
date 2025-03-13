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

const int N = 3e5, M = 30;
int k,n,m;


void solve(){
    string s;
    cin>>n>>s;
    vi f1(M), f2(M);
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==2){
        cout<<0<<endl;
        return;
    }
    rep(i,0,n){
        if(i%2) f2[s[i]-'a']++;
        else f1[s[i]-'a']++;
    }
    if(n%2){
        vi bf1(M), bf2(M);
        int ans = n;
        // if(*max_element(all(f1)) == e && e>o) ans++;
        rep(i,0,n){
            if(i%2){
                f2[s[i]-'a']--;
            } else f1[s[i]-'a']--;
            vi tmp1(M), tmp2(M);
            rep(i,0,(int)M){
                tmp1[i] = f2[i] + bf1[i];
                tmp2[i] = f1[i] + bf2[i];
            }
            int cur = n - *max_element(all(tmp1)) - *max_element(all(tmp2)) - 1;
            // if(*max_element(all(f1)) == e && e>o) cur++;

            deb(i)
            deb(s[i])
            deb(tmp1) deb(tmp2)
            deb(cur)
            ans = min(ans, cur+1);
            if(i%2){
                bf2[s[i]-'a']++;
            } else bf1[s[i]-'a']++;
        }
        cout<<ans<<endl;
        return;
    }
    int e = (n+1)/2, o = (n)/2;
    int ans = n - *max_element(all(f1)) - *max_element(all(f2));
    if(*max_element(all(f1)) == e && e>o) ans++;
    cout<<ans<<endl;
}


int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        solve();
        // solve2();
    }
    

    return 0;
}