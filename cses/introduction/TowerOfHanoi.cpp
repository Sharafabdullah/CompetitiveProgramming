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


void solve(int n, int m, int t, int h){
    if(n==1){
        cout<<m<<" "<<t<<endl;
    }
    else{
        solve(n-1, m, h, t);
        cout<<m<<" "<<t<<endl;
        solve(n-1, h, t, m);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, s; cin>>n;
    cout<<pow(2, n) -1<<endl;
    solve(n, 1, 3, 2);

    return 0;
}