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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n;
    string s; cin>>s;
    int q; cin>>q;
    vi psum(s.size()+1);
    rep(i,1,psum.size()){
        psum[i] = psum[i-1] + (s[i-1]=='1');

    }
    int l ,r ;
    // int lr = inf, rr = -1;
    set<int> st;
    bool f= 0;
    while(q--){
        cin>>l>>r;
        if(psum[r] - psum[l-1]>0 ){
            st.insert(l); st.insert(r);
        }
        if(!st.empty()){
            auto t1= st.upper_bound(l);
            auto t2 = t1; 
            if(t1!=st.begin())t2--;
            // int tmp = *(--st.upper_bound(l));
            deb(*t1)
            if(psum[r] - psum[l-1]>0 || (t1!=st.end()&&*t1 >=l && *t1<=r) || (t1!=st.end()&&*t2>=l && *t2<=r)){
                deb(l) deb(r)
                st.insert(l);
                st.insert(r);
                deb(st)
            }
        }
        
    }
    int b = *st.begin(), e = *(--st.end());
    deb(b)
    for (int i = 0; i < s.size(); i++)
    {
        if(i>=b-1 && i<=e-1){
            cout<<'1';
        }
        else{
            cout<<s[i];
        }
    }
    cout<<endl;
    
}

void solve2(){
    cin>>n;
    string s; cin>>s;
    int q; cin>>q;
    vector<pi> v;
    rep(i,0,s.size()){
        if(s[i]=='0') continue;
        int j = i;
        while(j< s.size() && s[j]=='1'){
            j++;
        }
        j--;
        v.pb({i,j});
        i = j;
    }
    int l,r;
    deb(v)
    while(q--){
        cin>>l>>r; l--, r--;
        ll lo = 0, hi = v.size()-1;
        auto cmp = [&](ll md){
            return v[md].second >= l;
        };
        //finds the first true given by cmp (lo). hi is the last false
        while(lo<=hi){
            ll md = lo + (hi-lo)/2;
            if(cmp(md)) hi = md - 1;
            else lo = md+1;
        }
        if(lo >= v.size()|| lo<0 || v[lo].first > r) continue;
        v[lo] = {min(v[lo].first, l), max(v[lo].second, r)};
        deb(v[lo])
        for (int i = v[lo].first; i <= v[lo].second; i++)
        {
            s[i] = '1';
        }
        
        int c = lo-1;
        while(c>=0){
            if(v[c].second >= v[lo].first-1){
                v.erase(v.begin()+c);
            } else break;
        }
        c = lo + 1000;
        while(c<v.size()){
            if(v[c].first <= v[lo].second - 1){
                v.erase(v.begin()+c);
            } else break;
        }
    }
    // deb(v)
    // sort(all(v));
    // vector<pi> w;
    // if(v.size()) w.pb(v[0]);
    // rep(i,1,v.size()){
    //     if(w.back().second >= v[i].first-1){
    //         w.back().second = max(w.back().second, v[i].second);
    //     }
    //     else w.pb(v[i]);
    // }
    // deb(w)
    // for (int ind= 0, i = 0; i < s.size(); i++)
    // {
    //     while(ind<v.size() && i>v[ind].second) ind++;
    //     if(ind<v.size() && v[ind].first<=i && i<=v[ind].second){
    //         cout<<'1';
    //     }
    //     else{
    //         cout<<s[i];
    //     }
    // }
    cout<<s;
    cout<<endl;
    
}

void solve3(){
    cin>>n; string s; cin>>s;
    set<int> zeros, ones;
    rep(i,0,s.size()){
        if(s[i]=='1') ones.insert(i);
        else zeros.insert(i);
    }
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;l--, r--;
        auto it = ones.lower_bound(l);
        if(it==ones.end() || *(it) > r) continue;
        it = zeros.lower_bound(l);
        vi tormv;
        while(it!=zeros.end() && *it<=r){
            // ones.insert(*it);
            // zeros.erase(*it);
            tormv.pb(*it);
            it++;
        }
        for(int i: tormv){
            ones.insert(i);
            zeros.erase(i);
        }
    }
    rep(i,0,n){
        if(ones.count(i)){
            cout<<'1';
        } else cout<<'0';
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    // while(t--) solve();
    // while(t--) solve2();
    while(t--) solve3();
    

    return 0;
}