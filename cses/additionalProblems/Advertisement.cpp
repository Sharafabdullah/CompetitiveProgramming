// #include <bits/stdc++.h>
// using namespace std;


// #define all(v)        ((v).begin()), ((v).end())
// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// #define pb            push_back
// #define ppb           pop_back
// #define F             first
// #define S             second
// #define B             begin()
// #define E             end()
// #define clr(x)        memset(x,0,sizeof(x))
// #define endl          '\n'
// #define coutfloat(n,d)     cout << fixed << setprecision(d) << n << endl
// #define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)


// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double   ld;
// typedef pair<int, int> pi;
// typedef vector<bool>      vb;
// typedef vector<vb>        vvb;
// typedef vector<string>    vs;
// typedef vector<int>       vi;
// typedef vector<ll>       vll;
// typedef vector<double>    vd;
// typedef vector< vi >      vvi;


// #ifndef ONLINE_JUDGE
// #define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
// #define deb(x)
// #endif

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(ld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// const int dx[] = {0,0,1,-1};
// const int dy[] = {1,-1,0,0};

// const ll inf = 1e9+1000;
// const double eps = (1e-8);
// const ll mod = 1e9 + 7;

// const int N = 3e5, M = 10;
// int k,n,m;


// void solve(){
//     cin>>n;
//     vi a(n); rep(i,0,n) cin>>a[i];
//     vector<pi> st;
//     st.pb({0,0});
//     ll ans = 0;
//     rep(i,0,n){
//         int end = i+1;
//         while(a[i] <= st.back().first){
//             end = st.back().second;
//             st.pop_back();
//         }
//         st.pb({a[i],i+1});
//         ll lo = 1, hi = st.size()-1;
//         auto cmp = [&](ll md){
//             ll mdA = 1ll*st[md].first * (i - (st[md-1].second) + 1);
//             ll md1 = 0;
//             if(md==1) md1 = 0;
//             else md1 = 1ll*st[md-1].first * (i - (st[md-2].second) + 1);
//             deb(md)
//             deb(mdA)
//             deb(md1)
//             ans = max({ans, mdA, md1});
//             if(md1 >= mdA) return true;
//             else return false;
//         };
//         //finds the first true given by cmp (lo). hi is the last false
//         deb(st)
//         while(lo<=hi){
//             ll md = lo + (hi-lo)/2;
//             if(cmp(md)) hi = md - 1;
//             else lo = md+1;
//         }
//     }
//     cout<<ans<<endl;
    
// }

// int main(){
//     FASTIO;

//     int t= 1;
//     // cin>>t;
//     while(t--){
//         solve();
//     }
    

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<ll> heights(n);
	for (ll &i : heights) { cin >> i; }

	ll ans = 0;
	stack<pair<ll, ll>> mono_stack;
	for (int i = 0; i < n; i++) {
		int start = i;
		while (!mono_stack.empty() && heights[i] < mono_stack.top().second) {
			pair<ll, ll> cur = mono_stack.top();
			mono_stack.pop();
			start = cur.first;
			ans = max(ans, (i - cur.first) * cur.second);
		}
		mono_stack.push({start, heights[i]});
	}

	// finish up the remaining rectangles
	while (!mono_stack.empty()) {
		pair<ll, ll> cur = mono_stack.top();
		mono_stack.pop();
		ans = max(ans, (n - cur.first) * cur.second);
	}

	cout << ans << endl;
}