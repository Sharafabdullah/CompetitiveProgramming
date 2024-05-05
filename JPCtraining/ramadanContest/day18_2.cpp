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

    ll t, n, a, c;
    cin>>t;
    while(t--){
        cin>>n;
        long long ans = 0;
        vector<map<ll,ll>> v(1<<11+1);
        while(n--){
            cin>>a; c = a;
            ll ind = 0;
            if(!a) ind |= 1;
            while(a){
                ind |= 1<<a%10;
                a/=10;
            }
            v[ind][c]++;
        }
        for (ll i = 0; i < 1<<11; i++)
        {
            for (ll j = i+1; j < 1<<11; j++)
            {
                if(!(i&j)){
                    for(auto [k1,v1]: v[i]){
                        for(auto [k2,v2]: v[j]){
                            ans+= v1*(ll)v2*(k1+k2);
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}