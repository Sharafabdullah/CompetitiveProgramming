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

int MAXQ = 160;
int q= 0;
bool ask(int a, int b) {
    cout << "? " << a <<" "<<b<<endl;
    int ans; cin>>ans;
    assert(ans!=-1);
    return ans;
}

void answer(vi& u) {
    cout << "! ";
    for(int i = 1; i<u.size(); i++){
        cout<<u[i]<<(i==u.size()-1?"":" ");
    }
}

void solve() {
  cin>>n;
  MAXQ = 2*n - 6;
  int lastOne = -1;
  vi bigger; vi zAdj;
  vi parent(n);
  for(int i = n-1; i>1; i--){
    int ret = ask(i,1);
    if(ret==0){
        if(lastOne==-1){
            lastOne = i;
            parent[i] = 1;
        }
        else{
            parent[i] = parent[lastOne];
            parent[lastOne] = i;
            lastOne = i;
        }
    }
    else{
        if(lastOne==-1){
            bigger.pb(i);
        }
        else{
            zAdj.pb(i);
        }
    }
  }
  sort(all(bigger));
  if(bigger.size()) bigger = {bigger[0]};
//   sort(all(zAdj));
    int ind = 0, idLast = -1, cnt = 0;
    for(int i = 0; i<bigger.size() && ind<zAdj.size();){
        int elm = bigger[i];
        int ret = ask(elm, zAdj[ind]);
        if(ret==0){
            cnt++;
            parent[elm] = zAdj[ind];
            zAdj[ind] =elm;
            if(cnt>=2){
                for(int j = i+1; j < bigger.size(); j++){
                    parent[bigger[j]] = elm;
                    elm = bigger[j];
                }
                break;
            }
            
            i++;
        }
        else{
            cnt=0;
            ind++;
        }
    }
    answer(parent);
}


void solve2(){
    cin>>n;
    vi parent(n, 0);
    set<int> next;
    int j = n;
    if(n==4){
        int ret = ask(1,3);
        if(ret){
            ret = ask(2,3);
            if(ret){
            }
            else{
                parent = {0,0,0,2};
            }
        }
        else{
            ret = ask(2,3);
            if(ret){
                parent = {0,0, 0, 1};
            }
            else{
                parent = {0,0,1,2};
            }
        }
        answer(parent);
        return;
    }
    rep(i,2,n){
        int ret = ask(i,1);
        next.insert(i);
        if(ret==0){
            parent[i] = 1;
            // next.pb(i);
            j = i+1;
            break;
        }
    }
    int ind = 0;
    while(j<n && next.size()){
        int ret = ask(j, *next.begin());
        if(ret){
            next.erase(next.begin());
        }
        else{
            parent[j] = *next.begin();
            next.erase(next.begin());
            next.insert(j);
            j++;
        }
    }
    answer(parent);

}

int main() {
    int T;
    cin >> T;
  
    while (T--) {
        // solve();
        solve2();
        cout << endl;
    }
}

