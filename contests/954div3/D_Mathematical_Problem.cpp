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
    cin>>n;
    string s; cin>>s;
    ll ans = inf;
    if(n<=2){
        cout<<stoi(s)<<endl;
        return;
    }
    if(n>3){
        for(char c: s){
        if(c=='0'){
            cout<<0<<endl;
            return;
        }
        }
    }
    if(n==3){
        string tmp;
        tmp+=s[0]; tmp+=s[1];
        int c1 = min(stoi(tmp)+ (s[2]-'0'), stoi(tmp)*(s[2]-'0'));
        tmp.clear();
        tmp+=s[1]; tmp+=s[2];
        // deb(stoi(tmp) + s[0]-'0');
        cout<<min(c1, min(stoi(tmp)+ (s[0]-'0'),stoi(tmp)* (s[0]-'0')))<<endl;
        return;
    }
    

    rep(i,0,n-1){
        ll p = 0, a=0,c=0;
        string tmp;
        tmp+=s[i];
        tmp+=s[i+1];
        c = stoi(tmp);
        for (int j = 0; j < i; j++)
        {
            if(s[j]=='1') continue;
            p += (s[j]-'0');
        }
        // if(!p && i>0){
        //     p = 1;
        // }
        for (int j = i+2; j < n; j++)
        {
            if(s[j]=='1') continue;
            a += (s[j]-'0');
        }
        // if(!a && i+2<n){
        //     a = 1;
        // }
        // cout<<p<<" "<<c<<" "<<a<<endl;
        // ll cur = c;

        ans = min(ans, a+c+p);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    
    // cout<<stoi("02")<<endl;
    return 0;
}