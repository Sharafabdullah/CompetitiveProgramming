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

const int N = 3e5, M = 10;
int k,n,m;

// void divisors(ll n, ll& cnt) 
// { 
//     ll i;
//     for ( i=1; i*i<n; i++) 
//     { 
//         if (n%i == 0) 
//         { 
//             cnt+=2;
//             // if(i*i != n) div.pb(n/i);
//         } 
//     } 
//     if(i*i == n) cnt++;
// }
void rangeDivisors(vi& num){
    for (int i = 1; i < num.size(); i++)
    {
        //for each number - add it to the numbers that this number divides
        for(int j = i; j<num.size(); j+= i){
            num[j]++;
        }
        
    }
}

using namespace chrono; steady_clock::time_point tstt,endt;
void start(){tstt = steady_clock::now();}
void end(int i = 0){
    if(!i) cout<<"Time: "<<duration_cast<microseconds>(steady_clock::now()- tstt).count()<<char(230)<<"s"<<endl;
    else cout<<"Time: "<<duration_cast<milliseconds>(steady_clock::now()- tstt).count()<<"ms"<<endl;}

void solve(){
    // cin>>n;
    n = 1e5;
    vector<vi> div(n+1); ll cnt = 0;
    // divisors(n, cnt);
    // cout<<cnt<<endl;
    start();
    // rangeDivisors(n, div);
    // rep(i,0,n){
    //     cout<<i<<" ";
    //     deb(div[i]);
    // }
    end(1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    // start();
    // vi div(1e6+10);
    n = 1e6+10;
    vi num(n);
    rangeDivisors(num);
    // end(1);
    // deb(num)
    cin>>t;
    while(t--){
        cin>>n;
        cout<<num[n]<<endl;
    }

    return 0;
}