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

const int N = 1e5+10, M = 10;
int k,n,m;

vs v(2);
ll tab[N][4][4] = {};

ll dp(int i, int cur, int nxt){

        if (i >= n) {
            return (cur != 0 || nxt != 0) ? -inf : 0;
        }
        
        if(tab[i][cur][nxt]!=-1) return tab[i][cur][nxt];
        ll ans = 0, up = 0, down = 0;
        if(cur == 3){
            ans = dp(i+1, nxt, 0);
        }
        up += (v[0][i] == 'A');
        down += (v[1][i] == 'A');
        if(cur==0){
            ans = max(ans, dp(i+1, 2,0) + (int)((up + down + (int)(v[1][i+1] == 'A'))>=2));
            ans = max(ans, dp(i+1, 1,0) + (int)((up + down + (int)(v[0][i+1] == 'A'))>=2));
            
            int add = (int)((up + (int)(v[0][i+1]=='A') + (int)(v[0][i+2]=='A'))>=2) +
             (down + (int)(v[1][i+1]=='A') + (int)(v[1][i+2]=='A'))>=2; 
            deb(add)
            deb((down + (int)(v[1][i+1]=='A') + (int)(v[1][i+2]=='A')))
             
            ans = max(ans, dp(i+3, 0,0) + add);
        }
        if(cur==1){
            if(nxt == 0){
                ans = max(ans, (dp(i+2, 0,0) + 
                        ((down + (int)(v[1][i+1]=='A') + (int)(v[0][i+1]=='A'))>=2)
                ));
                ans = max(ans, dp(i+1, 2,2) + ((int)(down + (int)(v[1][i+1]=='A') + (int)(v[1][i+2]=='A')>=2)));
            }
            else ans = max(ans, dp(i+2,2,0) + ((int)(down + (int)(v[1][i+1]=='A') + (int)(v[1][i+2]=='A')>=2)));
        }
        if(cur==2){
            if(nxt == 0){
                ans = max(ans, (dp(i+2, 0,0) + 
                        ((ll)( v[0][i]=='A') + (int)((v[0][i+1]=='A')) + (int)(v[1][i+1]=='A')>=2)
                ));
                ans = max(ans, dp(i+1, 1,1) + ((int)((up + (int)(v[0][i+1]=='A') + (int)(v[0][i+2]=='A'))>=2)));
            }
            else ans = max(ans, dp(i+2,1,0) + ((int)(up + (int)(v[0][i+1]=='A') + (int)(v[0][i+2]=='A')>=2)));
        }

        return tab[i][cur][nxt] = ans;
}
void solve(){
    cin>>n;
    cin>>v[0]>>v[1];
    v[0].pb('0');
    v[0].pb('0');
    v[0].pb('0');
    v[1].pb('0');
    v[1].pb('0');
    v[1].pb('0');
    rep(i,0,4){
        rep(j,0,4){
            rep(k,0,n+3){
                tab[k][i][j] = -1;
            }
            // tab[i][j] = vi(n+2,-1);
        }
    }
    cout<<dp(0,0,0)<<endl;
    
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