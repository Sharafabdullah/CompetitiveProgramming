#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define mp            make_pair
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
int N = 8, M = N;


vector<string> g(N);
vi v;
int it = 0;

bool chk(vi& v){
    // it++;
    // deb(v);

    rep(i,0,N-1){
        rep(j, 1, N){
            if(i+j>=N) break;
            if(v[i+j]==v[i]+j) return false;
            if(v[i+j]==v[i]-j) return false;
        }
    }
    // deb(v);
    // deb(1);
    return true;
}

int cnt = 0;
void bt(vi& v, int n){
    if(v.size()==N){
        cnt+=chk(v);
        return;
    }
    // int msk = 0;
    // rep(i,0,v.size()){
    //     if(v[i]!=-1) msk |= 1<<v[i];
    // }
    // bitset<8> b(msk);
    set<int> s(all(v));
    // deb(s);
    // // cout<<b<<endl;
    // deb(v);
    rep(i,0,N){
        if(find(all(v), i)==v.end() && g[n][i]!='*'){
            v.push_back(i);
            // deb(v);
            bt(v,n+1);
            v.pop_back();
        }
    }
}

using namespace chrono; steady_clock::time_point tstt,endt;
void start(){tstt = steady_clock::now();}
void end(int i = 0){
    if(!i) cout<<"Time: "<<duration_cast<microseconds>(steady_clock::now()- tstt).count()<<char(230)<<"s"<<endl;
    else cout<<"Time: "<<duration_cast<milliseconds>(steady_clock::now()- tstt).count()<<"ms"<<endl;}


void solve(){
    int i,j,n,m;
    rep(i,0,N){  cin>>g[i];}
    // deb(g);
    bt(v,0);
    // deb(it);
    // deb(cnt);
    cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("Error.txt","w",stderr);
// #endif
    int t= 1;
    // cin>>t;
    start();
    while(t--) solve();
    end(1);

    return 0;
}