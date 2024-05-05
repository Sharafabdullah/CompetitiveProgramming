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



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        x=y=n/3;
        if(n%3==1) x++;
        if(n%3==2) y++;
        cout<<x<<" "<<y<<endl;
    }

    return 0;
}