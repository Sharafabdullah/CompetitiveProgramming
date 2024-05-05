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

    ll t;
    ll n, a, c;
    cin>>t;
    while(t--){
        cin>>n;
        ll ans = 0;
        vector<ll> b(1<<10,-1);
        // vector<ll> nelm(1<<10,0);
        vector<unordered_multiset<ll>> nelm(1<<10);
        while(n--){
            cin>>a; c = a;
            ll ind = 0;
            if (!a) ind = 1;
            while(a){
                ind =ind | 1<<(a%10);
                a/=10;
            }
            // cout<<"Index: "<<ind<<endl;
            if(b[ind]==-1) b[ind]=0;
            b[ind] +=c;
            // nelm[ind]++;
            nelm[ind].insert(c);
            // cout<<"Val at Index: "<<b[ind]<<endl;

        }
        for (int i = 0; i < b.size(); i++)
        {
            for (int j = i+1; j < b.size(); j++)
            {
                // if(!(i&j)&& b[i]!=-1 && b[j]!=-1){
                //     ans+=  nelm[i]* (b[i]* nelm[j] + b[j]);
                //     // cout<<"Val at i: "<<i<<" is: "<<b[i]<<endl;
                //     // cout<<"Val at j: "<<j<<" is: "<<b[j]<<endl;
                //     // cout<<endl;
                // }
                if(!(i&j) && !nelm[i].empty() && !nelm[j].empty()){
                    for(ll ei: nelm[i]){
                        for(ll ej: nelm[j]){
                            ans += ei + ej;
                        }
                    }
                }
            }   
        }
        cout<<ans<<endl;
    }

    return 0;
}