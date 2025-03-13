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

const ll inf = 1e15+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;

struct Node {
    ll totalSum, prefixSum, suffixSum, maxSubarraySum;

    // Merge function for two nodes
    static Node merge(const Node &left, const Node &right) {
        Node result;
        result.totalSum = left.totalSum + right.totalSum;
        result.prefixSum = max(left.prefixSum, left.totalSum + right.prefixSum);
        result.suffixSum = max(right.suffixSum, right.totalSum + left.suffixSum);
        result.maxSubarraySum = max({left.maxSubarraySum, right.maxSubarraySum, left.suffixSum + right.prefixSum});
        return result;
    }
};

class SegmentTree {
    vector<Node> tree;
    int n;

public:
    SegmentTree(const vll&arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    // Build function to initialize the segment tree
    void build(const vll &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], max(0ll,arr[start]), max(0ll, arr[start]),max(0ll,arr[start])};
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = Node::merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    Node query(int left, int right) {
        return queryUtil(0, 0, n - 1, left, right);
    }

private:
    // Utility function for the query
    Node queryUtil(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            // Return a neutral node that won't affect the result
            return {-inf, 0ll, 0ll, 0ll};
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node leftResult = queryUtil(2 * node + 1, start, mid, left, right);
        Node rightResult = queryUtil(2 * node + 2, mid + 1, end, left, right);
        return Node::merge(leftResult, rightResult);
    }
};

void solve(){
    cin>>n;
    vll a(n); rep(i,0,n) cin>>a[i];

    SegmentTree sg(a);
    ll ans = inf;
    rep(i,1,n){
        ans = min(ans, abs(sg.query(0,i-1).maxSubarraySum- sg.query(i,n-1).maxSubarraySum));
    }
    cout<<ans<<endl;
    
}

int main(){
    FASTIO;

    int t= 1;
    cin>>t;
    while(t--){
        solve();
    }
    

    return 0;
}