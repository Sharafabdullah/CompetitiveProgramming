#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define sz(x)         ((int)(x).size())
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))


typedef long long ll;
typedef unsigned long long ull;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<bool>      vb;
typedef vector<vb>        vvb;
typedef vector<string>    vs;
typedef vector<int>       vi;
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

int N = 3e3, M = 10;
int k,n,m;

vvi g(4);
vi val;

int sign(int f) {
    return f>0? 1: -1;
}

bool bt(int i){
    deb(i)
    deb(val);
    if(i>n){
        return true;
    }
    int f= g[1][i], s = g[2][i], t = g[3][i];
    int c =0;
    if(val[abs(f)]!=0 ) {
        if(val[abs(f)]!=sign(f)){
            // return false;
        }
        else c++;
    }
    if(val[abs(s)]!=0 ) {
        if(val[abs(s)]!=sign(s)){
            // return false;
        }
        else c++;
    }
    if(val[abs(t)]!=0 ) {
        if(val[abs(t)]!=sign(t)){
            // return false;
        }
        else c++;
    }
    bool ans = 0;
    deb(c)
    // if(c==3) ans|= bt(i+1);
    if(c>=2){
        ans|= bt(i+1);
    }
    else if(c==1){
        if(val[abs(f)]==0) {
            val[abs(f)] = sign(f);
            ans |= bt(i+1);
            val[abs(f)] = 0;
        }
        if(val[abs(s)]==0) {
            val[abs(s)] = sign(s);
            ans |= bt(i+1);
            val[abs(s)] = 0;
        }
        if(val[abs(t)]==0) {
            val[abs(t)] = sign(t);
            ans |= bt(i+1);
            val[abs(t)] = 0;
        }
    }
    else {
        if(!val[abs(f)] && !val[abs(s)]) {
            val[abs(f)] = sign(f);
            val[abs(s)] = sign(s);
            ans |= bt(i+1);
            val[abs(f)] = 0;
            val[abs(s)] = 0;
        }
        if(!val[abs(f)] && !val[abs(t)]) {
            val[abs(f)] = sign(f);
            val[abs(t)] = sign(t);
            ans |= bt(i+1);
            val[abs(f)] = 0;
            val[abs(t)] = 0;
        }
        if(!val[abs(s)] && !val[abs(t)]) {
            val[abs(s)] = sign(s);
            val[abs(t)] = sign(t);
            ans |= bt(i+1);
            val[abs(s)] = 0;
            val[abs(t)] = 0;
        }
    }
    return ans;

}
void solve(){
    cin>>n;
    val = vi(n+1);
    rep(i,1,4){
        g[i] = vi(n+1);
        rep(j,1,n+1){
            cin>>g[i][j];
        }
    }
    cout<< (bt(1)?"YES":"NO")<<endl;

    // deb(g);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}