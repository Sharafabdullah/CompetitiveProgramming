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

void solve(){
    cin>>n>>k;
    int i = 1;
    k++;
    deque<int> q;
    rep(i,1,n+1) q.pb(i);
    while(!q.empty()){
        if(i%k){
            q.pb(q.front());
            q.pop_front();
            i++;
        }
        else{
            cout<<q.front()<<" ";
            q.pop_front();
            i++;
        }
    }
}

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve2(){
    cin>>n>>k;
    ordered_set<int> os;
    rep(i,1,n+1) os.insert(i);
    int start = 0;
    while(!os.empty()){
        start = (start + k) % os.size();
        auto it = os.find_by_order(start);
        cout << *it <<" ";
        os.erase(it);
    }
}


struct TreeNode {
    int value;
    int next; // link to the next person in the circle (ordered)
};

std::vector<TreeNode> tree1;

int josephus(int n, int k) {
    std::vector<bool> alive(n, true); // mark who's still in the circle

    int curr = 0; // start from person 0
    int remaining = n;

    while (remaining) {
        int steps = (k - 1) % remaining;
        // Move to k-th alive person
        while (steps) {
            curr = tree1[curr].next;
            if (alive[curr])
                --steps;
        }
        // find the next alive if current is dead
        while (!alive[curr]) {
            curr = tree1[curr].next;
        }

        std::cout << tree1[curr].value << " "; // elimination order
        alive[curr] = false;
        --remaining;

        // move curr to next alive for next iteration
        curr = tree1[curr].next;
        while (!alive[curr] && remaining) {
            curr = tree1[curr].next;
        }
    }

    return 0;
}

int solve3() {
    cin>>n>>k;k++;
    // int n = 7; // number of people
    // int k = 3; // eliminate every 3rd person

    tree1.resize(n);
    // initialize tree1 as a circular linked list
    for (int i = 0; i < n; ++i) {
        tree1[i].value = i + 1; // people are labeled 1..n
        tree1[i].next = (i + 1) % n;
    }

    josephus(n, k);

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct SegmentTree {
    #define L (2 * node + 1)
    #define R (2 * node + 2)
    #define md ((l + r) / 2)
    
private:
    vector<T> seg;
    T skip = 0;  // identity for addition
    int sz = 1;
    
    // merge now performs addition
    T merge(T a, T b) {
        return a + b;
    }
    
    // Build the segment tree over [l, r] for the original array.
    void build(int l, int r, int node, const vector<T>& org) {
        if (l == r) {
            // If within bounds of org, use its value; otherwise, use skip.
            seg[node] = (l < org.size() ? org[l] : skip);
            return;
        }
        build(l, md, L, org);
        build(md + 1, r, R, org);
        seg[node] = merge(seg[L], seg[R]);
    }
    
    void update(int l, int r, int node, T val, int ind) {
        if (l == r) {
            seg[node] = val;
            return;
        }
        if (ind <= md)
            update(l, md, L, val, ind);
        else
            update(md + 1, r, R, val, ind);
        seg[node] = merge(seg[L], seg[R]);
    }
    
    T query(int l, int r, int node, int lq, int rq) {
        if (r < lq || l > rq)
            return skip;
        if (l >= lq && r <= rq)
            return seg[node];
        return merge(query(l, md, L, lq, rq), query(md + 1, r, R, lq, rq));
    }
    
public:
    SegmentTree(const vector<T>& arr) {
        while (sz < arr.size())
            sz *= 2;
        seg.assign(2 * sz, skip);
        build(0, sz - 1, 0, arr);
    }
    
    void update(int ind, T val) {
        update(0, sz - 1, 0, val, ind);
    }
    
    T query(int l, int r) {
        return query(0, sz - 1, 0, l, r);
    }
    
    // Iterative findKth: Given k (1-indexed), find the smallest index
    // such that the cumulative sum up to that index is at least k.
    int findKth(T k) {
        int node = 0;
        int l = 0, r = sz - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int leftNode = 2 * node + 1;
            // If the left child's sum is at least k, the kth alive lies in the left child.
            if (seg[leftNode] >= k) {
                node = leftNode;
                r = mid;
            } else {
                // Otherwise, subtract the left sum and search in the right child.
                k -= seg[leftNode];
                node = leftNode + 1;  // right child
                l = mid + 1;
            }
        }
        return l;
    }
    
    #undef L
    #undef R
    #undef md
};

//
// Josephus permutation using the above segment tree
//
int solve4(){
    int n, k;
    cin >> n >> k; k++;
    
    // Create an array of ones, each representing an alive person.
    vector<int> arr(n, 1);
    
    // Build the segment tree on the array.
    SegmentTree<int> seg(arr);
    
    // pos is our current offset (0-indexed) in the "alive" ordering.
    int pos = 0;
    for (int i = 0; i < n; i++){
        // Get current number of alive persons.
        int remaining = seg.query(0, n - 1);
        
        // Compute new offset in the alive order.
        pos = (pos + k - 1) % remaining;
        
        // Find the (pos+1)-th alive person (findKth is 1-indexed).
        int idx = seg.findKth(pos + 1);
        
        // Output the person (convert from 0-indexing to 1-indexing).
        cout << idx + 1 << " ";
        
        // Mark this person as eliminated.
        seg.update(idx, 0);
    }
    
    cout << "\n";
    return 0;
}



int main(){
    FASTIO;
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "w", stdin);

    int t = 1;
    // cin >> t;
    while(t--)
        // solve();
        // solve2();
        // solve3(); TLE
        solve4();

    return 0;
}
