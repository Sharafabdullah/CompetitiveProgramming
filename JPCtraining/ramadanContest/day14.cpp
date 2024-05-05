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




int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t, n, m,a;
    ll least;
    cin>>t;
    while(t--){
        cin>>n>>m;
        n= n>>1;
        least = n*(n+1);
        int cnt = 0;
        while(m--){
            cin>>a;
            if(!(a<least || a%2)) cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}