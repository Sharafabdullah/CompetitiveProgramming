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
const ll mod = 1e9 + 7;
const double eps = (1e-8);

int tr, tc;
vvi m(100, vi(100));
int dp(int r, int c, vvi& g){
    if(r<0 || c<0 || r>tr || c>tc) return -inf;
    if(m[r][c]) return m[r][c];
    if(c==tc && r ==tr) {
        return g[r][c];
    }

    m[r][c] = max(dp(r+1, c, g), dp(r, c+1, g)) + g[r][c];
    return m[r][c];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //* Given a Grid verticies - find the max sum from left up to bottom right - only using down and right movement
    vvi g = {
        {1,3,12}, 
        {5,6,2}
    };
    tr = g.size()-1, tc = g[0].size()-1;
    p(dp(0,0,g));
    return 0;
}