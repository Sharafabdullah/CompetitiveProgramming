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
    ll p,t;
    cin>>p>>t;
    ll cand = p + t + 1;
    vll type(cand);
    vll Pskill(cand), Tskill(cand); 
    rep(i,0,cand){
        cin>>Pskill[i];
    }
    rep(i,0,cand){
        cin>>Tskill[i];
        if(Tskill[i]> Pskill[i]){
            type[i] = 1;
        }
    }
    vll ans;
    rep(i,0,cand){
        //ith will be abscent
        int cur = 0;
        int Ts = 0, Ps = 0;
        rep(j,0,cand){
            if(j==i) continue;
            if(type[j]){
                if(Ts < t){
                    cur += Tskill[j];
                    Ts++;
                } 
                else{
                    cur += Pskill[j];
                }
            }
            else{
                if(Ps < p){
                    cur += Pskill[j];
                    Ps++;
                }
                else{
                    cur += Tskill[j];
                }
            }
        }
        ans.pb(cur);
    }
    // deb(ans)
    for(ll i: ans) cout<<i<<" ";
    cout<<endl;
}

void solve2(){
    // ll t, p; cin>>
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}