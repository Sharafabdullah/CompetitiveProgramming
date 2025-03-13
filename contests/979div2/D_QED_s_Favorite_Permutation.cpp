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
    int q;
    cin>>n>>q;
    vi p(n); rep(i,0,n) cin>>p[i], p[i]--;
    string s; cin>>s;
    int r = -1, l = -1;
    vector<pi> inter;
    bool collecting = 0;
    rep(i,0,n){
        if(!collecting && p[i]!=i){
            collecting = 1;
            l = i;
            r = p[i];
        }
        else if(collecting){
            r = max(r,p[i]);
            if(i == r){
                inter.pb({l,r});
                collecting = 0;
            }
        }   
    }

    vector<set<int>> rVec(inter.size()), lVec(inter.size());
    int cnt = 0, target = inter.size(), cur = 0;
    vb correct(target+1);

    for(auto [l,r]: inter){
        for(int i = l; i<=r; i++){
            if(s[i]=='R') rVec[cnt].insert(i);
            else lVec[cnt].insert(i);
        }
        if(lVec[cnt].empty() || rVec[cnt].empty() || *(--rVec[cnt].end()) < (*lVec[cnt].begin())){
            cur++;
            correct[cnt]= 1;
        }
        cnt++;
    }
    deb(inter)
    deb(cur)
    deb(lVec) deb(rVec)

    string ans = ((cur == target)? "YES":"NO");
    inter.pb({inf,inf});
    while(q--){
        int x;
        cin>>x; x--;
        ll lo = 0, hi = target-1;
        auto cmp = [&](ll md){
            if(inter[md].second >= x) {
                return true;
            }
            else return false;
        };
        //finds the first true given by cmp (lo). hi is the last false
        while(lo<=hi){
            ll md = lo + (hi-lo)/2;
            if(cmp(md)) hi = md - 1;
            else lo = md+1;
        }
        int ind = lo;
        deb(x)
        deb(ind)
        if(ind < 0 || inter[ind].first > x) {
            cout<<ans<<endl;
            continue;
        }

        if(s[x]=='R'){
            s[x] = 'L';
            if(!rVec[ind].empty()) rVec[ind].erase(x);
            lVec[ind].insert(x);
        }
        else{
            s[x] = 'R';
            rVec[ind].insert(x);
            if(!lVec[ind].empty()) lVec[ind].erase(x);
        }
        if(lVec[ind].empty() || rVec[ind].empty() || *(--rVec[ind].end()) < (*lVec[ind].begin())){
            if(correct[ind]==0) cur++;
            correct[ind]= 1;
        }
        else {
            if(correct[ind]==1) cur--;
            correct[ind] = 0;
        }

        if(cur>=target) ans = "YES";
        else ans = "NO";
        assert((cur<=target));
        cout<<ans<<endl;
    }
    
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