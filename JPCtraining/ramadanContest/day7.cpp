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
const int mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> arr(n);
        for(ll& i: arr) cin>>i;
        *max_element(arr.begin(),  arr.end()) -=1;
        ll res=1;
        for(ll i: arr){
            res =( res*i)%mod;
        }
        cout<<res<<endl;
    }

    return 0;
}