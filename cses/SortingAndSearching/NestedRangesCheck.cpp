#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


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

int N = 3e5, M = 10;
int k,n,m;

  


void solve(){
    cin>>n;
    int a,b;
    ordered_set<pi> os;
    vector<pi> v(n+1);
    rep(i,1,n+1){
        cin>>a>>b;
        os.insert({a,i});
        os.insert({b,i});
        v[i] = {a,b};
    }
    set<int> s;
    vb contained(n), contains(n);
    while(!os.empty()){
       auto it =  *os.find_by_order(0);
       deb(s)
       deb(it)
       if(s.count(it.second)){
            int pos  = 0;
         for(auto num: s){
            if(num>=it.second) break;
            {
                pos++;
                contains[num-1] = 1;
            }
         }
         deb(pos)
         if(pos>=1) contained[it.second-1] = 1;
         s.erase(it.second);
       } 
       else{
        s.insert(it.second);
       }
       os.erase(it);
    }
    deb(contains)
    deb(contained)
}

struct range{
    int l, r, ind;
    bool operator < (range& other){
        if(l == other.l) return r>other.r;
        return l<other.l;
    }
};
void solve2(){
    cin>>n;
    vector<range> v(n);
    vb contains(n), contained(n);
    rep(i,0,n){
        cin>>v[i].l>>v[i].r;
        v[i].ind = i;
    }
    sort(all(v));
    // for(range r: v){
    //     cout<<r.l<<" "<<r.r<<" "<<r.ind<<endl;
    // }
    //* Check contained
    int mx = 0;
    rep(i,0,n){
        if(v[i].r<=mx){
            contained[ (v[i].ind) ] = 1;
        }
        mx = max(mx, v[i].r);
    }
    int mn = inf;
    rep(i,n,0){
        if(v[i].r >= mn){
            contains[ v[i].ind ] = 1;
        }
        mn = min(mn, v[i].r);
    }
    // deb(contains);
    // deb(contained);
    rep(i,0,n) cout<<contains[i]<<" ";
    cout<<endl;
    rep(i,0,n) cout<<contained[i]<<" ";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}