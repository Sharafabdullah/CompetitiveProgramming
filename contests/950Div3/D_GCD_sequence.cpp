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

bool check(vll& a, int ind){
    vll b;
    rep(i,0,n){
        if(i==ind) continue;
        b.pb(a[i]);
    }
    rep(i,0,b.size()-1){
        b[i] = gcd(b[i], b[i+1]);
    }
    return is_sorted(all(b));
}

void solve(){
    cin>>n;
    vll a(n),b(n),bf(n); 
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        
    }
    rep(i,0,n-1){
        b[i] = __gcd(a[i], a[i+1]);
        // if(i!=n-2) bf[i] = __gcd(a[i], a[i+2]);
    }
    if(check(a,0)|| check(a,n-1)){
        cout<<"YES"<<endl;
        return;
    }
    rep(i,0,n){
        if(b[i]<b[i-1]){
            if(check(a, i) || (i-1>=0&& check(a,i-1)) || (i+1<n && check(a,i+1))){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    if(check(a , n-1))
	{
		cout<<"YES"<<endl;
		return;
	}
    cout<<"NO"<<endl;
}

void solve2(){
    cin>>n;
    vi a(n), b(n-1);
    for(int& i: a) cin>>i;
    rep(i,0,n-1){
        b[i] = gcd(a[i], a[i+1]);
    }
    if(is_sorted(b.B+1, b.E)|| is_sorted(b.B, b.E-1)|| n<=3){
        cout<<"YES"<<endl;
        return;
    }
    rep(i,2,n-1){
        if(b[i]<b[i-1] || b[i-1]<b[i-2]){
            if((is_sorted(b.B, b.B + i - 1) || i == 2)&& (is_sorted(b.B + i + 1, b.E)||i+1==n)){
                // cout<<"It is sorted "<<i<<endl;
                int val = gcd(a[i-1], a[i+1]);
                if(val>=b[i-2] && val<=b[i+1]){
                    cout<<"YES"<<endl;
                    return;
                }
                val = gcd(a[i-2], a[i]);
                if(val>=b[i-2]&& val<=b[i]){
                    cout<<"YES"<<endl;
                    return;
                }
            }

        }
    }
    b.erase(b.B+1);
    b[0] = gcd(a[0], a[2]);
    if(is_sorted(all(b))){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    // while(t--) solve();
    while(t--)solve2();
    

    return 0;
}