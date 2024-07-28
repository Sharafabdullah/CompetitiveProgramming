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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 3e5, M = 10;
int k,n,m;

void bfs(int s,int e, vector<vector<int>>& adj) {
    vector<bool> vis(adj.size(), false);
    deque<int> q;
    q.push_back(s);
    vis[s] = true;
    int d= -1, connectedComp = 0;

    while (!q.empty()) {
        int sz = q.size();
        d++;
        for (int i = 0; i < sz; i++)
        {
            int cur = q.front();
            q.pop_front();
            connectedComp++;
            // if(cur == e){
            //     cout<<"found at depth: "<<d<<endl;
            // }
            for(int nbhd: adj[cur]){
                if(!vis[nbhd]){
                    vis[nbhd ] =1;
                    q.pb(nbhd);
                }
            }
        }
    }
    deb(connectedComp)
}

void dfs(int start, const vector<vector<int>>& adj) {
    vector<bool> vis(adj.size(), false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        if (!vis[cur]) {
            vis[cur] = true;
            cout << cur << " ";

            for (auto it = adj[cur].rbegin(); it != adj[cur].rend(); ++it) {
                if (!vis[*it]) {
                    st.push(*it);
                }
            }
        }
    }
}
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

class DSU {
public:
    vi parent,rank,size;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1); // Each element is initially its own set with size 1
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // Path compression
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
                size[rootU] += size[rootV]; // Update the size of the new root
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV]; 
                ++rank[rootU];
            }
        }
    }
    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
    int getSize(int u) {
        return size[find(u)]; // Return the size of the set containing u
    }
};

vvi g;
string treeCanonicalForm(int i, int parent){
    vector<string> children;
    for(int ch: g[i]){
        if(ch!=parent) children.push_back(treeCanonicalForm(ch,i));
    }
    string ret = "(";
    sort(all(children));
    for(string str: children) ret+=str;
    ret += ")";
    return ret;
}

pair<int, int> bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> distance(n, -1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    int farthestNode = start;
    int maxDistance = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);

                if (distance[neighbor] > maxDistance) {
                    maxDistance = distance[neighbor];
                    farthestNode = neighbor;
                }
            }
        }
    }

    return {farthestNode, maxDistance};
}

// Function to find the path from the start node to the target node
void findPath(int start, int target, const vector<vector<int>>& adj, vector<int>& path, vector<bool>& visited) {
    visited[start] = true;
    path.push_back(start);

    if (start == target) return;

    for (int neighbor : adj[start]) {
        if (!visited[neighbor]) {
            findPath(neighbor, target, adj, path, visited);
            if (path.back() == target) return;
        }
    }

    path.pop_back();
}

// Function to find the center(s) of a tree
vector<int> findTreeCenters(const vector<vector<int>>& adj) {
    pair<int, int> p1 = bfs(0, adj);  // Find farthest node from node 1
    pair<int, int> p2 = bfs(p1.first, adj);  // Find the diameter of the tree

    int start = p1.first;
    int end = p2.first;

    vector<int> path;
    vector<bool> visited(adj.size(), false);
    findPath(start, end, adj, path, visited);

    int diameter = path.size() - 1;

    // Find the center(s)
    vector<int> centers;
    if (diameter % 2 == 0) {
        centers.push_back(path[diameter / 2]);
    } else {
        centers.push_back(path[diameter / 2]);
        centers.push_back(path[diameter / 2 + 1]);
    }

    return centers;
}

void solve(){
    g = vvi(5);
    g[0].pb(1);
    g[0].pb(2);
    // g[3].pb(4);
    vi v = findTreeCenters(g);
    deb(v)
    cout<<treeCanonicalForm(0,-1)<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    // cin>>t;
    while(t--) solve();
    

    return 0;
}