#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,no-stack-protector,fast-math")

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


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T, typename... Args>
void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+7;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k, n, m;
vector<ll> primes;
void sieve(int n) {
    // 500ms to get primes up to 1e7 -> ~660000 primes
    bitset<10000> prime; prime.set();
    for (ll p = 2; p * p<= n; p++) {
        if (prime[p]) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]) primes.pb(p);
}

vector<set<int>> primeFact(1010);

void PrimeDivisorsRange(ll mxVal, vector<set<int>>& divOf){
    for (ll i = 2; i < mxVal; i++)
    {
        if(divOf[i].size()==0){
            //this number is a prime - have not been reached before
            divOf[i].insert(i);
            for (int j = 2*i; j < mxVal; j+=i)
            {
                divOf[j].insert(i);
            }
        }
    }
}
void solve(){
    cin>>n>>k;
    vector<pi> v(n);
    rep(i,0,n){
        cin>>v[i].first;
    }
    rep(i,0,n) cin>>v[i].second;
    sort(all(v), [&](auto& f, auto& s){
        return f.second < s.second;
    });
    if(k==1){
        deb(k)
        for(auto [f,s]: v){
            if(f==1) {
                cout<<s<<endl;
                return;
            }
        }
        cout<<-1<<endl;
        return;
    }
    deb(v)
    int ans = inf;
    rep(i,0,n){
        set<int>& curSet = primeFact[v[i].first];
        vi curVec;
        for(int num: curSet){  
            curVec.pb(num);
        }
        int mask = (1<<(curVec.size())) - 1;

        vector<vi> dp(mask + 1, vi(curVec.size()+2,inf));
        vector<vector<set<int>>> takenInd(mask+1, vector<set<int>>(curVec.size()+2));

        dp[mask][1] = v[i].second;
        takenInd[mask][1].insert(i);

        int taken = 0, brk = 0;
        int curAns = inf;

        for(int j = i+1; j < n; j++){

            int curMask = 0;
            rep(s,0,curVec.size()){
                if(primeFact[v[j].first].count(curVec[s])){
                    curMask |= (1<<s);
                }
            }

            rep(s,0,curVec.size()+1){
                for(int m = mask; m>= 0; m--){
                    if(dp[m & curMask][s+1] >= dp[m][s]+v[j].second){

                        dp[m & curMask][s+1] = min(dp[m & curMask][s+1],
                         dp[m][s]+v[j].second);

                        takenInd[m&curMask][s+1] = takenInd[m][s];
                        takenInd[m&curMask][s+1].insert(j);
                    }
                }
            }

            rep(s,0,dp[0].size()){
                if(dp[0][s]<inf){
                    deb(j, s)
                    taken = s;
                    curAns = dp[0][s];
                    rep(l,0,n){
                        if(taken >= k) break;
                        if(!takenInd[0][s].count(l)){
                            taken++;
                            curAns+=v[l].second;
                            // takenInd[0][s].insert(l);
                        }
                    }
                    brk = 1;
                    break;
                }
            }
            if(brk) break;
        }
        if(taken != k || curAns >= inf) continue;
        // deb(dp[0])
        ans = min(ans, curAns);
    }
    cout<<(ans>=inf? -1:ans)<<endl;
    
}

int main(){
    FASTIO;

    sieve(1010);
    PrimeDivisorsRange(1010, primeFact);
    // primeFact[1].insert(1);


    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}