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

int N = 3e5, M = 8;
int k,n,m;


void solve(){
    vs g(M);
    rep(i,0,M) cin>>g[i];
    vvb can(M, vb(M,1));
    auto diagonal = [&](int curI, int curJ){
        int i = curI - 1, j = curJ + 1;
        while(i>= 0 && j < M){
            can[i][j] = 0;
            if(g[i][j] !='.' && g[i][j] !='K') break;
            i--, j++;
        }
        i = curI-1, j = curJ - 1;
        while(i>= 0 && j >= 0){
            can[i][j] = 0;
            if(g[i][j] !='.' && g[i][j] !='K') break;
            i--, j--;
        }
        i = curI + 1, j = curJ + 1;
        while(i < M && j < M){
            can[i][j] = 0;
            if(g[i][j] !='.' && g[i][j] !='K') break;
            i++, j++;
        }

        i = curI + 1, j = curJ - 1;
        while(i < M && j >= 0 ){
            can[i][j] = 0;
            if(g[i][j] !='.' && g[i][j] !='K') break;
            i++, j--;
        }
    };
    auto horizantal = [&](int curI, int curJ){
        for(int i = curI + 1; i < M; i++){
            can[i][curJ] = 0;
            if(g[i][curJ]!='.'&&g[i][curJ]!='K') break;
        }
        for(int i = curI - 1; i >= 0; i--){
            can[i][curJ] = 0;
            if(g[i][curJ]!='.'&&g[i][curJ]!='K') break;
        }

        for(int j = curJ + 1; j< M; j++){
            can[curI][j] = 0;
            if(g[curI][j]!='.' && g[curI][j]!='K') break;
        }
        for(int j = curJ - 1; j>=0; j--){
            can[curI][j] = 0;
            if(g[curI][j]!='.' &&  g[curI][j]!='K') break;
        }
    };
    rep(i,0,M){
    rep(j,0,M){
        if(g[i][j] == 'B' || g[i][j]=='Q') diagonal(i,j);
        if(g[i][j] == 'R' || g[i][j]=='Q') horizantal(i,j);
        if(g[i][j] == 'P' && i>0){
            if(j+1<M) can[i-1][j+1] = 0;
            if(j-1>=0) can[i-1][j-1] = 0;
        }
        if(g[i][j] == 'N'){
            if(i-1 >= 0){
                if(j+2<M) can[i-1][j+2] = 0;  
                if(j-2>=0) can[i-1][j-2] = 0;
            }
            if(i-2 >= 0){
                if(j+1<M) can[i-2][j+1] = 0;
                if(j-1>=0) can[i-2][j-1] = 0;
            }
            if(i+1 < M){
                if(j+2<M) can[i+1][j+2] = 0;
                if(j-2>=0) can[i+1][j-2] = 0;
            }
            if(i+2 < M){
                if(j+1<M) can[i+2][j+1] = 0;
                if(j-1>=0) can[i+2][j-1] = 0;
            }
        }
    }
}
    int ans = 0;
    rep(i,0,M){
        rep(j,0,M){
            if(g[i][j]=='K'){
                if(i>0){
                    ans += can[i-1][j];
                    if(j>0) ans += can[i-1][j-1];
                    if(j+1<M) ans += can[i-1][j+1];
                }
                if(i+1<M){
                    ans += can[i+1][j];
                    if(j>0) ans += can[i+1][j-1];
                    if(j+1<M) ans += can[i+1][j+1];
                }
                if(j>0) ans += can[i][j-1];
                if(j+1<M) ans += can[i][j+1];
            }
        }
    }
    deb(can)
    cout<<(ans?"Yes":"No")<<endl;
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