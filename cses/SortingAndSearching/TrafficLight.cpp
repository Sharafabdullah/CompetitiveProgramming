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


void solve(){
    cin>>k>>n;
    set<pi> s;
    // vi v(n); for(auto& i: v) cin>>i;
    s.insert({0,k});
    while(n--){
        cin>>m;
        for(auto it = s.begin(); it!=s.end(); it++){
            auto p = *it;
            deb(p)
            if(m>p.first && m<p.second) {
                if(m - p.first == p.second - m){
                    s.insert({p.first, m});
                    s.insert({m,p.second});
                }
                else if((m- p.first) < (p.second - m)){
                    s.insert({p.first, m});
                } else s.insert({m, p.second});
                // s.erase(p);
            }
        }
        pi ans = *s.begin();
        cout<<ans.second - ans.first<<" ";
    }
    cout<<endl;
    
}
void solve2(){
    int x, cnt= 0;
    cin>>x>>n;
    set<int> lights;
    map<int,int> len;
    lights.insert(0); lights.insert(x);
    len[x]++;
    while(n--){
        cin>>k;
        // deb(*len.rbegin());
        auto [it,p]  = lights.insert(k);
        int nVal = *next(it);
        int pVal = *prev(it);
        len[nVal - pVal]--;
        if(len[nVal-pVal]==0) len.erase(len.find(nVal - pVal));
        len[k - pVal]++; len[nVal - k]++;
        // for(auto [k,v]: len){
        //     cout<<k<<" "<<v<<endl;
        // }
        // cout<<"________"<<endl;
        cout<< (*len.rbegin()).first<<" ";
    }
        // deb(*len.rbegin());

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    
    

    return 0;
}