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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, i = 0, j=1;
    cin>>n;
    vector<ll> v(n+1);
    for (ll i = 1; i <= n; i++)
    {
        v[i] = v[i-1]+i;
    }
    ll s = n*(n+1)/2;
    if(s%2) cout<<"NO";
    else{
        cout<<"YES"<<endl;
        ll t = s/2;
        while(v[j]-v[i]!=t){
            if((v[j]-v[i])>t) i++;
            if (v[j]-v[i]<t) j++;
        }
        cout<<j-i<<endl;
        for (int k = i+1; k <= j; k++)
        {
            cout<<k<<" ";
        }
        cout<<endl;
        cout<<n-(j-i)<<endl;
        for (int k = 1; k <= i; k++)
        {
            cout<<k<<" ";
        }
        for (int k = j+1; k <= n; k++)
        {
            cout<<k<<" ";
        }

        
        
        
    }

    return 0;
}