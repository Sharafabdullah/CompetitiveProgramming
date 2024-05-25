#include <set>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <utility>s
#include <iterator>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define lpi(i, j, n) for (int i = (j); i < (int)(n); ++i)
#define lpd(i, j, n) for (int i = (j); i >= (int)(n); --i)

typedef long long ll;
typedef pair<int, int> pi;

const ll OO = 1e8;
const double EPS = (1e-7);

#define pb push_back
#define mp make_pair
#define p(x) cout << #x << " = { " << x << " }\n"

typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;

vector<vector<bool>> visited;
vector<vector<char>> g;

bool validInd(int i, int j, int &c)
{
    return (i < c && j < c);
};
void dfs(int i, int j, int &c)
{
    if (!visited[i][j] || !validInd(i, j, c) || g[i][j] == '.')
        return;

    visited[i][j] = 1;
    dfs(i - 1, j, c);
    dfs(i + 1, j, c);
    dfs(i, j + 1, c);
    dfs(i, j - 1, c);
}

int cnt;
void sol(int test, int c)
{
    cnt = 0;
    visited = vector<vector<bool>>(c, vector<bool>(c, 0));
    for (vector<bool> i : visited)
        for (bool j : i)
            cout << j << "  ";

    // g = vector<vector<char>>(c, vector<char>(c));
    // lp(i, c) lp(j, c)
    // {
    //     cin >> g[i][j];
    // };

    // lp(i, c) lp(j, c)
    // {
    //     if (!visited[i][j] && g[i][j] == 'x')
    //     {
    //         dfs(i, j, c);
    //         cnt++;
    //     }
    // }
    // cout << "Case " << test << ": " << cnt << endl;
}

int main()
{

    int t, c;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> c;
        sol(i, c);
    }

    return 0;
}