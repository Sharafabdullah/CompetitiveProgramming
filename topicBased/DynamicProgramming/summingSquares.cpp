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

map<int,int> m;
int dp(int t){
    if(!t) return 0;
    if(m[t]) return m[t];
    priority_queue<int, deque<int>, greater<int>> pq;
    for (int i = 1; i < 10000; i++)
    {
        if(t-i*i<0) break;
        pq.push(dp(t-i*i));
    }
    m[t] = pq.top() + 1;
    return m[t];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //!Given a number t - find the minimun number of perfect squares that 
    //!sums to t

    p(dp(10));

    return 0;
}