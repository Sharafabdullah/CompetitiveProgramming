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
    cin>>n>>m;
    deb(n)
    int iter = min(n,m)/2, ib = 0, ie = n -1,jb = 0, je = m-1;
    vs v(n);
    rep(i,0,n) cin>>v[i];
    vector<char> str(4*max(n,m));
    int ans = 0;
    deb(v)
    rep(it,0,iter){
        int ind = 0;

        int ibb = ib + it, iee = ie - it, jbb = jb + it, jee = je - it;
        // int ibb = ib + it, iee = ie - it, jbb = jb + it, jee = je - it;
        // int i = ibb, j = iee;
        while(ibb < iee && jbb < jee){

            str[ind] = v[ibb][jbb];
            jbb++;
            ind++;
        }

        deb(ind)
        while(ibb < iee){
            str[ind] = v[ibb][jbb];
            ibb++;
            ind++;
        }
        deb(ind)

        while(jbb > jb + it){
            str[ind++] = v[ibb][jbb];
            jbb--;
        }
        deb(ind)
        while(ibb > ib + it){
            str[ind++] = v[ibb][jbb];
            ibb--;
        }
        deb(ind)

        for(int i = 0; i<ind; i++){
            string tmp = "";
            tmp.append({str[i%ind], str[(i+1)%ind], str[(i+2)%ind], str[(i+3)%ind]});
            if(tmp=="1543"){
                deb(i)
                ans++;
            }
        }
        deb(ans)
    }
    cout<<ans<<endl;
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