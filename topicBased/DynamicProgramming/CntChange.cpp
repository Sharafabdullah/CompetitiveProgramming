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

const ll mod = 1e9 + 7;

map<int, int> m;
int dp(int ind, int t, vi& c){
    if(m[t]) return m[t];
    if(t==0) return 1;
    if(ind>=c.size()) return 0;

    int cnt=0;
    for (int i = 0; i* c[ind]<= t; i++)
    {
        cnt += dp(ind+1, t - i*c[ind], c);
    }
    
    m[t] = cnt;
    return cnt;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //* Given an array of coins - how many ways can you gen. a target sum - you can reuse the coins

    vi c = {1,2,3};
    p(dp(0, 10000, c));

    return 0;
}