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

    freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

    int n,c, mx = 0,d =0;
    cin>>n;
    vi arr(n+1), sum(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>c;
        arr[i]= c%7;
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = (sum[i-1]+arr[i])%7;
    }
    // for(int i: sum) cout<<i<<" ";
    // cout<<endl;
    for (int i = 0; i < 7; i++)
    {
        auto fit = find(sum.begin(), sum.end(), i);
        auto sit = find(sum.rbegin(), sum.rend(), i);
        if(fit!=sum.end()&& sit != sum.rend()) {
            // cout<<"found "<<*fit<<"     ";
            d = distance(fit, sit.base());
            // cout<<"D is: "<<d-1<<endl;
            if(d!=1) mx = max(mx ,d-1);
            }
    }
    cout<<mx;
    
    
    

    return 0;
}