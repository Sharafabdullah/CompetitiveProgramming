#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repd(i, a, b) for (int i = a; i >= b; --i)
#define pb            push_back
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
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
#define deb(...) cerr << "[" << #__VA_ARGS__ << "] = "; _print(__VA_ARGS__); cerr << endl;
#else
#define deb(...)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(const char* s) {cerr << s;}


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename... Args>
void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
ll k, n, m,q;

ll mpow(ll bs, ll exp) {
    ll res = 1;
    bs = bs;
    while (exp > 0) {
        if (exp & 1)
            res = (res * bs);
        exp = exp >> 1;
        bs = (bs * bs);
    }
    return res;
}

ll numAns;
void numAt(pair<ll,ll> pos, ll sz, ll base){
    // deb(sz, pos, base)
    if(sz==1){
        if(pos.first==1 && pos.second==1) base+=1;
        else if(pos.first==1) base+=2;
        else if(pos.second==1) base+=3;
        numAns = base;
        return;
    }
    ll half_size = mpow(2, sz - 1);
    ll qSize = mpow(2, 2*sz - 2);
    bool top, left;
    if(pos.first < half_size){
        top = 1;
    } else top = 0;

    if(pos.second < half_size){
        left = 1;
    } else left = 0;

    // deb(top, left)
    if(top && left){
        numAt(pos, sz-1, base);
    }

    if(!top && !left){
        pos.first -= half_size;
        pos.second -= half_size;
        base += qSize;
        numAt(pos, sz-1, base);
    }
    if(!top && left){
        pos.first -= half_size;
        base+= 2 * qSize;
        numAt(pos, sz - 1, base);
    }
    if(top && !left){
        pos.second -= half_size;
        base += 3 * qSize;
        numAt(pos, sz - 1, base);
        
    }
}


pair<ll,ll> baseAns;
void posOf(ll ind, ll sz, pair<ll,ll> base){
    deb(ind, sz, base)
    if(sz==1){
        if(ind==2) {
            base.first += 1;
            base.second += 1;
        }
        if(ind == 3){
            base.first +=1;
        }
        if(ind == 4){
            base.second +=1;
        }
        baseAns = base;
        return;
    }
    ll qSize = mpow(2,2*sz-2);
    ll half_size = mpow(2, sz - 1);

    ll i = 1;
    while(qSize * i < ind){
        i++;
    }
    i--;
    deb(i)
    if(i==1) {
        base.first += half_size;
        base.second += half_size;
    }
    if(i==2){
        base.first += half_size;
    }
    if(i==3){
        base.second += half_size;
    }
    posOf(ind - i * qSize, sz - 1, base);
}
void solve(){
    cin>>n>>q;
    rep(i,0,q){
        string str;
        cin>>str;
        deb(i, str)
        if(str=="->"){
            ll x,y;
            cin>>x>>y;
            numAt({x-1,y-1},n,0);
            cout<<numAns + 1<<endl;
        }
        else{
            ll ind;
            cin>>ind;
            posOf(ind,n, {0,0});
            cout<<baseAns.first+1<<" "<<baseAns.second + 1<<endl;
        }
    }
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
