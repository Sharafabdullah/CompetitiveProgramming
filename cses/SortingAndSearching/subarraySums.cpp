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
    //* Use sliding window technique
    int n, x,i=0, j=0,ans = 0,sum=0;
    cin>>n>>x;
    vector<ll> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    while(i<n){
        sum+= arr[i];
        while(sum>=x){
            if (sum==x) ans++;
            sum-= arr[j];
            j++;
        }
         i++;
    }
    
    cout<<ans;
    

    

    return 0;
}