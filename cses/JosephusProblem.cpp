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


void solve(){
    
    
}

ll J(ll i){
    // deb(i)
    if(i==1) return 1;
    if(i%2) return 2*J(i/2) + 1;
    else return 2*J(i/2) -1;
}

ll Jclosed(ll i, vector<ll>& powers){
    auto it = upper_bound(all(powers), i);
    if(it != powers.B) it--;
    return (i%(*it))*2  +1; 
}

using namespace chrono; steady_clock::time_point tstt,endt;
void start(){tstt = steady_clock::now();}
void end(int i = 0){
    if(!i) cout<<"Time: "<<duration_cast<microseconds>(steady_clock::now()- tstt).count()<<char(230)<<"s"<<endl;
    else cout<<"Time: "<<duration_cast<milliseconds>(steady_clock::now()- tstt).count()<<"ms"<<endl;}


void findLastOneStanding(){
    ll n = 1e2; //k = 2;
    //notice: J(2n) == 2*J(n) - 1
    //and J(2n+1) == 2*J(n) + 1
    rep(i, 1, n) cout<<i<<" "<<J(i)<<endl; //log(n)
    start();
    rep(i,1, n) J(i);
    end(1);
    //* Notice that J(2^m + l) == 2*l + 1
    //so find the largest power of two less than n -> find mod
    // vector<ll> twoPow(63);
    // twoPow[0] = 1;
    // rep(i,1, 63) twoPow[i] = 2*twoPow[i-1];

    // start();
    // rep(i,1, n) Jclosed(i, twoPow);
    // end(1);
    // rep(i,1, n) cout<<i<<" "<<Jclosed(i, twoPow)<<endl;
}

int josephusRecursive(int n, int k) {
    if (n == 1)
        return 0;
    else
        return (josephusRecursive(n - 1, k) + k) % n;
}

int josephusIterative(int n, int k) {
    int result = 0;
    for (int i = 2; i <= n; ++i) {
        result = (result + k) % i;
    }
    return result;
}

int generalizedJosephus(int sz, vi& steps) {
    int n = steps.size();
    int result = 0;
    for (int i = 2; i <= sz; ++i) {
        result = (result + steps[n - i]) % i;
    }
    return result;
}

void generalK(){
    //*Notice that J(n) == (J(n-1, k)+k)%n -> J(n-1, k) gets the position of the winner for n-1 circle - that position is zero indexed where as it should be 0+k because in reality - the zero index of the subproblem is originally numbered k
    int k = 3, n = 10;
    // rep(i, 1, 100){
    //     cout<<i<<" ";
    //     cout<<josephusRecursive(i,k)+1<<endl;
    // }

    //* Using this approach - k could be varying
    vi steps{2,2,2,2,2,2,2,2,2};
    rep(i,1,steps.size()){
        cout<<i<<" "<<generalizedJosephus(i,steps)+1<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    // while(t--) solve();
    // findLastOneStanding();
    generalK();
    

    return 0;
}