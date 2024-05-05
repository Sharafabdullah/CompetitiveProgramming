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


unsigned long long fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    ll t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n,0);
        for(ll& i: a) cin>>i;
        ll lz =0, tz= 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]) break;
            lz++;
        }

        for(int i=n-1; i>=0; i--){
            if(a[i]) break;
            tz++;
        }
        if(tz== n || lz==n){
            cout<<(n*(n+1))/2<<endl;

        } else{
            ll ans=(lz+1)* (tz+1);
            cout<< ans<<endl;
        }
        
    }
    

    return 0;
}