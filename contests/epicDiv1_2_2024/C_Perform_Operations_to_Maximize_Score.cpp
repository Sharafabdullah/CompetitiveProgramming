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

const ll inf = 2e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve(){
    cin>>n>>k;
    ordered_set<int> changable, unchangable;
    vi a(n),b(n),ch; 
    rep(i,0,n) {cin>>a[i];}
    bool bl;
    rep(i,0,n){
        cin>>b[i];
        if(b[i]){
            {changable.insert(a[i]); ch.pb(a[i]);}
        } else unchangable.insert(a[i]);
    }
    int x = ch.size();
    vi pref(x+1);
    rep(i,1,x+1){
        pref[i] = pref[i-1] + ch[i-1];
    }
    int median = n - (n+1)/2 + 1;
    ll ans = 0;
    rep(i,0,n){
        if(b[i]){
            changable.erase(changable.find(a[i]));
        } else unchangable.erase(unchangable.find(a[i]));

        ll lo = 0, hi = inf;
        auto cmp = [&](ll md){
            ll numElm = 0,req=0;
            // deb(md);
            numElm = unchangable.size() - unchangable.order_of_key(md);
            numElm += changable.size() - changable.order_of_key(md);
            // deb(numElm)
            if(numElm >= median) return false;
            else{
                ll order = changable.order_of_key(md);
                ll reqElm = median - numElm;
                deb(order) deb(reqElm)
                if(b[i]) reqElm++;
                if(order < reqElm) return true;
                ll sum = pref[order] - pref[order - reqElm];
                if(b[i]) sum-=a[i];
                deb(sum)
                req = md * reqElm - sum;
                if(req<=k) return false;
                else return true;
            }

        };
        //finds the first true given by cmp (lo). hi is the last false
        while(lo<=hi){
            ll md = lo + (hi-lo)/2;
            if(cmp(md)) hi = md - 1;
            else lo = md+1;
        }
        if(b[i]){
            changable.insert(a[i]);
        } else unchangable.insert(a[i]);
        ans = max(ans, lo + a[i]);
    }
    cout<<ans<<endl;
}

void solve2(){
    cin>>n>>k;
    vector<pi> vec(n);
    rep(i,0,n) cin>>vec[i].first;
    rep(i,0,n) cin>>vec[i].second;
    sort(all(vec));
    vi ones, zeros; vll prefOnes(1,0);
    rep(i,0,n){
        if(vec[i].second){
            ones.pb(vec[i].first);
        } else zeros.pb(vec[i].first);
    }
    sort(all(ones)); sort(all(zeros));
    rep(i,0,ones.size()) prefOnes.pb(prefOnes.back()+ones[i]);

    ll ans = 0, median = n - n/2;

    ll lo = 0, hi = inf;
    auto cmp = [&](ll md){
        int have = zeros.end()- lower_bound(all(zeros), md);
        // deb(have)
        if(!zeros.empty() && zeros.back()>=md && have) have--;
        int need = n - n/2 - have;
        // deb(need)
        ll kk = k;
        for(int i = ones.size()-1; i>=0; i--){
            if(ones[i]>=md) need--;
            else if(md - ones[i]>kk) break;
            else {
                kk -= md- ones[i];
                need--;
            }
        }
        if(need<=0) return true;
        return false;
    };
    //finds the first true given by cmp (lo). hi is the last false
    while(lo<=hi){
        ll md = lo + (hi-lo)/2;
        deb(md)
        if(!cmp(md)) hi = md - 1;
        else lo = md+1;
    }
    deb(hi)
    ans = max(ans, hi + (zeros.empty()? 0: zeros.back()));
    deb(ans)

    rep(i,0,n){
        if(vec[i].second){
            int p1 = (n-2)/2; //to get the first possible median
            if(i<=p1) p1++; //if it is the first -> it has the second median
            ans = max(ans, (ll)vec[p1].first + vec[i].first + k);
        }
    }
    cout<<ans<<endl;
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        // solve();
        solve2();
    }
    

    return 0;
}