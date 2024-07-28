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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n;
    ll ans = 0, op = 0;
    vvi matrix(n+1,vi(n+1));
    for (int i = 1; i <= n; i++)
    {
        op++;
        // cout<<1<<" "<<i<<" ";
        for (int j = 1; j <= n; j++)
        {

            matrix[i][j] = j;
            // ans += j;
        }
        // cout<<endl;
    }
    // deb(matrix)
    int rsum = (n * (n+1))/2;
    for (int i = 1; i <= n; i++)
    {
        if(n * i < rsum){
            op++;
            for (int k = 1; k < n+1; k++)
            {
                matrix[k][i] = k;
            }
        }
    }
    deb(matrix)
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            ans += matrix[i][j];
        }   
    }
    cout<<ans<<" "<<op<<endl;

    for (int i = 1; i <= n; i++)
    {
        cout<<1<<" "<<i<<" ";
        for (int j = 1; j <= n; j++)
        {

            // matrix[i].pb(j);
            cout<<j<<" ";
            // ans += j;
        }
        cout<<endl;
    }

    for (int i = 1; i <= n; i++)
    {
        if(n * i < rsum){
            cout<<2<<" "<<i<<" ";
            op++;
            for (int k = 1; k < n+1; k++)
            {
                // matrix[k][i] = k;
                cout<<k<<" ";
            }
            cout<<endl;
        }
    }
    
}

void solve2(){
    cin>>n;
    int ans = 0;
    rep(i,1,n+1) ans+= (2*i-1)*i;
    cout<<ans<<" "<<2*n<<endl;
    rep(i,n+1,1){
        cout<<1<<" "<<i<<" ";
        rep(j,1,n+1) cout<<j<<" ";
        cout<<endl<<2<<" "<<i<<" ";
        rep(j,1,n+1) cout<<j<<" ";
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}