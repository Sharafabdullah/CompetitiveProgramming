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

int SoD(int x){
    int s = 0;
    while(x != 0){
        s += x%10;
        x = x/10;
    }
    return s;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, t, sum;
    cin>>t;
    while(t--){
        cin>>n;
        sum = 0;
        sum = n/9 * 45 + (n%9)*(n%9+1)/2;
        cout<<sum<<endl;
    }

    return 0;
}