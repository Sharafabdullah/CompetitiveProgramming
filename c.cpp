#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


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

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n;
    vi a(n);
    for(int& i: a) cin>>i;
    ordered_set s;
    rep(i, 1, n+1) s.insert(i);
    vi diff(n);
    int s1 = 0, s2 =0;
    rep(i,1,n-1){
        diff[i] = max(a[i-1]-a[i], a[i+1]-a[i]);
        diff[i] = max(diff[i], 0);
        if(i%2){
            s1+= diff[i];
        } else s2+= diff[i];
    }
    deb(diff)
    vi ans(n);
    deb(s1) deb(s2)
    if(s1<s2){
        set<pi> needing;
        for (int i = 1; i < n; i+=2)
        {
            needing.insert({diff[i], i});
        }
        for(auto [f,sec]: needing){
            auto it = (s.find_by_order(s.size()-1));
            ans[sec] = *it;
            s.erase(it);
        }
        ans[0] = *s.begin();
        s.erase(s.begin());
        int j = 0;
        for (int i = 2; i < n; i+=2)
        {
            ans[i] = *s.find_by_order(j); j++;
        }
    }
    else{
        set<pi> needing;
        for (int i = 2; i < n; i+=2)
        {
            needing.insert({diff[i], i});
        }
        // sort(all(needing));
        for(auto [f,sec]: needing){
            auto it = (s.find_by_order(s.size()-1));
            ans[sec] = *it;
            s.erase(it);
        }
        ans[0] = *s.begin();
        s.erase(s.begin());
        int j = 0;
        for (int i = 1; i < n; i+=2)
        {
            ans[i] = *s.find_by_order(j); j++;
        }

    }
    deb(ans);
    rep(i,0, n) cout<<ans[i]<<" ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}