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

ll choose2(ll x){
    ll nom = x - 2;
    deb(x * (x-1));
    return (x * (x-1) )/ 2;
}

void solve(){
    cin>>n;
    bool allZ  = 1;
    ll sum = 0;
    vi a(n); for(int& i: a) {cin>>i;sum+= i;
        if(i) allZ = 0;
    }
    if(sum%3) {
        cout<<0<<endl;
        return;
    }
    if(!sum){
        //count number of elm such that sum = 0
        int s = 0,cnt = 0;
        rep(i,0,n){
            s += a[i];
            if(!s) cnt++;
        }
        deb(cnt)
        cout<< choose2(cnt)<<endl;
        return;
    }
    // deb(sum)
    int i = 0, j = n-1;
    ll lsum = sum/3, rsum = sum/3;

    if(sum){
        while(i<n && lsum>0){
            lsum -= a[i++];
        }
        while(j>=0 && rsum>0){
            rsum -= a[j--];
        }
    }
    else {i++; j--;}
     
    
    if(lsum<0||rsum<0 || j - i < 0) {
        cout<<0<<endl; return;
    }

    int lz= 1, rz = 1;
    while(i < j && !a[i]){
        lz++; i++;
    }

    while(j>i && !a[j]){
        rz++; j--;
    }
    cout<< lz * rz <<endl;

    
}

void solve2(){
    int n;
    cin >> n;
    vll cnt(1e6+10), a(1e6+10);
    long long s = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0)
        cout << "0\n";
    else {
        s /= 3;
        long long ss = 0;
        for(int i = n-1; i >= 0 ; --i)
        {
            ss += a[i];
            if (ss == s)
                cnt[i] = 1;
        }
        for(int i = n-2 ; i >= 0 ; --i)
            cnt[i] += cnt[i+1];
        
        long long ans = 0;
        ss = 0;
        for(int i = 0 ; i+2 < n ; ++i) {
            ss += a[i];
            if (ss == s)
                ans += cnt[i+2];
        }
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    // solve2();
    

    return 0;
}