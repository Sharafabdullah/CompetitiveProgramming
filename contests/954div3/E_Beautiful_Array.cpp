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

const ll inf = 1e17+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n>>k;
    vi a(n); for(int& i: a) cin>>i;
    sort(all(a));
    if(n==1){
        cout<<0<<endl;
        return;
    }
    if(n%2){
        int rm1 = a[0]%k, rm2=-1, rm3=-1;
        int t1 = 0, t2=0, t3=0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]%k==rm1) t1++;
            else if(a[i]%k==rm2 || rm2==-1){ t2++; rm2=a[i]%k;}
            else if(a[i]%k==rm3 || rm3==-1){ t3++; rm3=a[i]%k;}
            else {
                cout<<-1<<endl;;
                return;
            }
            vi v = {t1,t2,t3};
            // sort(all(v));
            // deb(v)
            // if((v[0]==1 && (v[1]%2 || v[2]%2)) || (v[0]==0 && (v[1]%2 && v[2]%2 || (v[1]%2==0 && v[2]%2==0)))){
            //     cout<<-1<<endl;;
            //     return;
            // }
        }
        

        // deb(rm)
        // deb(can)
        
        ll  ans= inf,a1 = 0,a2 = 0;
        for(int i =0; i<n-2; i+=2){
            a1 += (a[i+1]-a[i]);
        }
        for(int i =1; i<n-1; i+=2){
            a2 += (a[i+1]-a[i]);
        }
        cout<<min(a1,a2)<<endl;
    }
    else{
        int rm = a[0]%k;
        rep(i,1,n){
            if(a[i]%k!=rm) {
                cout<<-1<<endl;
                return;
            }
        }
        ll ans = 0;
        for(int i = 0; i<n-1; i+=2){
            ans += (a[i+1]-a[i]);
        }
        cout<<ans<<endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}