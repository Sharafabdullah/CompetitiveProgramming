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

int N = 3e5, M = 10;
int k,n,m;

template<typename T>
struct cmp {
    bool operator()( T& p1,  T& p2)  {
        return p1.second > p2.second;
    }
};


void solve(){
    // auto cmp = [&](pi p1, pi p2){
    //     return p1.second > p2.second;
    // };
    // vector<pi> v = {{3,1},{3,21},{0,321}};
    // priority_queue<pi, deque<pi>, decltype(cmp)> pq(all(v));
    // while(!pq.empty()){
    //     deb(pq.top()); pq.pop();
    // }
    // auto cmpInt = [](int f,int s){return f>s;};
    // set<int, decltype(cmpInt)> s(cmpInt); //! have to provide the lambda if used to order
    // s.insert(3);
    // s.insert(12);
    // s.insert(5);
    // for(int i: s) cout<<i<<" ";
    // int sum = 0;
    // for_each(all(s), [&](int i){sum=  i+1;});
    // for(int i: s) cout<<i<<" ";
    // deb(sum);
    // cout<<endl;

    priority_queue<pi, deque<pi>, cmp<pi>> pq;
    cin>>n; 
    int a,b, mx = 1;
    vector<pi> v; rep(i,0,n) {cin>>a>>b; v.pb({a,b});};
    sort(all(v), [](pi f,pi s){return f.first<s.first;});
    // deb(v);
    pq.push(v[0]);
    rep(i,1,n){
        while(!pq.empty() && pq.top().second < v[i].first){
            pq.pop();
        }
        pq.push(v[i]);
        mx = max(mx,(int) pq.size());
    }
    cout<<mx<<endl;
}

void solve2(){
    cin>>n;
    int ans = 0,cur = 0, a,b;
    vector<pi> v; rep(i,0,n){ cin>>a>>b; v.pb({a,1}); v.pb({b,-1});}; //each custormer adds one when he enters and minus one one he leaves to the customers
    sort(all(v));
    for(pi cust: v) {
        cur += cust.second;
        ans = max(ans, cur);
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}