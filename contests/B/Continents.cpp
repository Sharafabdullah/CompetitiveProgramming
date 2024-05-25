#include <bits/stdc++.h>
using namespace std;


#define all(v)				((v).begin()), ((v).end())
#define repv(i, v)		for(int i=0;i<(v).size();++i)
#define rep(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define dow(i, j, n)	for(int i=(j);i>=(int)(n);--i)

#define pb					push_back
#define mp					make_pair
#define p(x)				cout<<#x<<" = { "<<x<<" }\n"


typedef long long ll;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
const ll inf = 1e9;
const double eps = (1e-8);

int n, m;
char land;
vector<vector<bool>> vis;
vector<vector<char>> mat;

void dfs(int r, int c, int& cnt) {
    c = (c % m + m) % m;
    if (r >= n || r < 0 || mat[r][c] != land || vis[r][c]) return;
    // p(r);
    // p(c);
    vis[r][c] = 1;
    cnt++;

    dfs(r + 1, c, cnt);
    dfs(r - 1, c, cnt);
    dfs(r, c + 1, cnt);
    dfs(r, c - 1, cnt);
}



int main() {

    int ans = 0, cnt = 0;
    cin >> n >> m;
    vis = vector<vector<bool>>(n, vector<bool>(m));
    mat = vector<vector<char>>(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }

    }
    int r, c;
    cin >> r >> c;
    land = mat[r][c];
    dfs(r, c, cnt);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j]) {
                cnt = 0;
                dfs(i, j, cnt);
                p(cnt);
                ans = max(ans, cnt);
            }
        }

    }
    cout << ans;

    return 0;
}