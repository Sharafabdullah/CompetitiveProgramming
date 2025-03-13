#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define endl '\n'
#define coutfloat(n, d) cout << fixed << setprecision(d) << n << endl
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;

const ll inf = 1e18;
const int N = 3e5;
int k, n, m;

void solve() {
    cin >> n >> m >> k;
    vector<bool> horse(n + 1, false);
    vector<vpi> g(n + 1);

    ll a, b, c;
    rep(i, 0, k) {
        cin >> c;
        horse[c] = true;
    }

    rep(i, 0, m) {
        cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }

    auto dijkstra = [&](int start, vector<vll> &dist) {
        priority_queue<tuple<ll, bool, int>, vector<tuple<ll, bool, int>>, greater<tuple<ll, bool, int>>> pq;
        dist[start] = {0, horse[start]};
        pq.push({0, horse[start], start});
        bool vis[n+1][2] = {0};
        while (!pq.empty()) {
            auto [w, hasHorse, v] = pq.top();
            pq.pop();
            if(vis[v][hasHorse]) continue;
            // if (dist[v].first < w) continue;
            hasHorse |= horse[v];
            vis[v][hasHorse] = 1;
            for (auto [u, cost] : g[v]) {
                ll new_w = hasHorse ? cost / 2 + w : cost + w;
                int edge = hasHorse | horse[u];
                if (new_w < dist[u][edge]) {
                    dist[u][edge] = new_w;
                    pq.push({new_w, edge, u});
                }
            }
        }
    };

    vector<vll> dist1(n + 1, vll(2, inf));
    vector<vll> dist2(n + 1, vll(2, inf));

    // Dijkstra from node 1
    dijkstra(1, dist1);
    // Dijkstra from node n
    dijkstra(n, dist2);

    ll ans = inf;
    rep(i, 1, n + 1) {
        ans = min(ans, max(dist1[i][0], dist2[i][0]));
        ans = min(ans, max(dist1[i][0], dist2[i][1]));
        ans = min(ans, max(dist1[i][1], dist2[i][0]));
        ans = min(ans, max(dist1[i][1], dist2[i][1]));
    }

    cout << (ans == inf ? -1 : ans) << endl;
}

int main() {
    FASTIO;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
