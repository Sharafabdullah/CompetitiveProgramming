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

struct cmp {
    bool operator()(const auto& elm1, const auto& elm2) {
        return elm1[1] >= elm2[1];
    }
};

void solve(){
    cin>>n;
    vector<array<int,3>> v(n);
    rep(i,0,n) {cin>>v[i][0]>>v[i][1]; v[i][2] = i;}
    sort(all(v));
    priority_queue<array<int,3>, deque<array<int,3>>, cmp> pq;
    // while(!pq.empty()) {cout<<pq.top().first<<" "<<pq.top().second<<endl; pq.pop();}
    // pq.push({v[0][0], v[0][1], 1});

    vi ans(n);
    // for(auto [a,b,c]: v) cout<<a<<" "<<b<<endl;
    // ans[v[0][2]] = 1;

    int next_room_ind = 1;
    set<int> free_rooms;

    int i = 0;
    
    while(i < n){
        auto [a,b,org_ind] = v[i];
        // deb(i,b)

        while(!pq.empty() && pq.top()[1] < a){
            // deb(i, pq.top()[0], pq.top()[1], pq.top()[2]);
            free_rooms.insert(pq.top()[2]);
            pq.pop();
        }

        if(free_rooms.empty()){
            ans[org_ind] = next_room_ind;
            pq.push({a,b,next_room_ind});
            next_room_ind++;
        }
        else{
            ans[org_ind] = *free_rooms.begin();
            pq.push({a,b,*free_rooms.begin()});
            free_rooms.erase(free_rooms.begin());
        }
        deb(i, ans[org_ind])
        
        i++;
    }
    cout<<next_room_ind - 1<<endl;
    for(int i: ans) cout<<i<<" ";
}

int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}
