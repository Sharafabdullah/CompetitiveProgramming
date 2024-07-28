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
int k,n,m,x;

vll pow2(32);

bool valid(int x){
    bool v = 1;
    int prev = x%2;
    x /=2;
    while(x){
        int cur = x%2;
        if(prev==1 && cur ==1) v = 0;
        x/=2;
        prev = cur;
    }
    return v;
}

void rec(ll x, bool sign, vi& ans){
    if(valid(x)){
        vi tmp;
        while(x){
            int cur = x%2;
            x/=2;
            if(sign) tmp.pb(cur);
            else tmp.pb(-1* cur);
        } 
        reverse(all(tmp));
        for(int i: tmp){
            ans.pb(i);
        }
        return;
    }
    auto it = lower_bound(all(pow2), x);
    ll rem = *it - x;
    auto itRem = lower_bound(all(pow2), rem);
    // deb(x)
    // deb(rem)
    if(sign){
        ans.pb(1);
        ans.pb(0);
    } else{
        ans.pb(-1);
        ans.pb(0);
    }
    it--; it--;
    while(it > itRem){
        ans.pb(0);
        it--;
    }
    rec(rem, !sign, ans);
}

void solve(){
    cin>>x;
    vi ans;
    rec(x, 1,ans);
    cout<<ans.size()<<endl;
    rep(i,ans.size(), 0){
        cout<<ans[i]<<" ";
    } cout<<endl;
}

void bt(int x, int sign, vi& ans){
    if(x==1) ans.pb(1*sign);
    if(!x) ans.pb(0);
    if(valid(x)){
        vi tmp;
        while(x){
            int cur = x%2;
            x/=2;
            tmp.pb(sign* cur);
        } 
        reverse(all(tmp));
        for(int i: tmp){
            ans.pb(i);
        }
        return;
    }
    ans.pb(1*sign);
    // ans.pb(0);

    auto it = lower_bound(all(pow2), x);
    int rem = *it - x;
    auto remIt = lower_bound(all(pow2),x);
    it--;
    while(it > remIt){
        ans.pb(0);
        it--;
    }
    bt(rem, !sign, ans);
}

void solve2(){
    cin>>x;
    vi ans;

    bt(x,1,ans);
    deb(ans)
}

void solve3(){
    cin>>x;
    vi res(31);
    for (int i = 0; i < 31; i++)
    {
        if(1ll & (x>>i)){
            if(res[i]){
                res[i+1] = 1;
                res[i] = 0;
            }
            else{
                if(i==0) {res[i]=1; continue;}
                if(res[i-1]==1){
                    res[i-1] = -1;
                    res[i]=0;
                    res[i+1]= 1;
                }
                else{ //the before element is only 1 or 0, can't be -1 because we place them backwords them move forwards
                    res[i] =1;
                }
            } 
        }
    }
    cout<<31<<endl;
    rep(i,0,31){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    pow2[0]=1;
    for (int i = 1; i < 32; i++)
    {
        pow2[i] = pow2[i-1]*2;
    }
    
    cin>>t;
    // while(t--) solve();
    // while(t--) solve2();
    while(t--) solve3();
    

    return 0;
}