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
int k, n, m;

struct cell{
    int x = 0, y = 0;
    int dist = 0;
    cell() = default;
    cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    bool operator<(const cell& other) const {
        if (dist != other.dist) return dist < other.dist;
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

set<cell> tables, cells;
void solve(){
    cin>>n;
    vector<cell> rmv_t, rmv_c;
    rep(i,0,n){
        bool t;
        cin>>t;
        deb(i)
        for(auto [x,y,dst]: cells) {
            deb(x,y,dst)
        }
        if(t){
            auto [x,y,dst] = *cells.begin();
            cells.erase(cells.begin());
            rmv_c.pb(cell(x,y,dst));
            if(tables.count(cell(x,y,dst))){
                tables.erase(cell(x,y,dst));
                rmv_t.pb(cell(x,y,dst));
            } 
            cout<<x<<" "<<y<<endl;
        }
        else{
            auto cl = *tables.begin();
            cells.erase(cl);
            rmv_c.pb(cl);
            tables.erase(cl);
            rmv_t.pb(cl);
            cout<<cl.x<<" "<<cl.y<<endl;
        }
    }
    for(auto c: rmv_t) tables.insert(c);
    for(auto c: rmv_c) cells.insert(c);
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    queue<pi> q;
    queue<pi> nq;
    vvi g(1010, vi(1010, inf));
    q.push({0,0});
    g[0][0] = 0;
    int d= 0;
    while(!q.empty()){
        auto [f,s] = q.front();
        // deb(d)
        q.pop();
        // deb(f,s)
        rep(i,0,4){
            int nf = f + dx[i], ns = s + dy[i];
            // deb(nf,ns)
            if (nf < 0 || ns < 0 || nf >= g.size() || ns >= g.size()) continue;

            if(nf % 3 != 0 && ns %3 !=0 && g[nf][ns]==inf){
                // deb(nf,ns, g[nf][ns])
                g[nf][ns] = d + 1;
                if(nf %3==1 && ns%3 ==1){
                    tables.insert(cell(nf, ns, d+1));
                }
                cells.insert(cell(nf,ns, d+1));
                continue;
            }
            else if(g[nf][ns] > d + 1 ){
                // deb(nf,ns,d)
                g[nf][ns] = d + 1;
                nq.push({nf,ns});
            }
        }

        if(q.empty()){
            q = nq;
            while (!nq.empty()) {
                q.push(nq.front());
                nq.pop();
            }
            d++;
        }
    }
    for(auto [f,s,dst]: cells){
        deb(f, s, dst)
    }
    deb((*tables.begin()).dist)
    deb("here")

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
