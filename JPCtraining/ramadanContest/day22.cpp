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
const ll mod = 1e9 + 7;
const double eps = (1e-8);

ll power(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base = (base*base)%mod;
        exp /= 2;
    }
    return result;
}

vector<vector<ll>> v(8, vector<ll>(63,1));

vector<int> p = {2,3,5,7};
map<ll,ll> mem;
ll findVal(ll a){
    if(mem[a]) return mem[a];
    for(int i :p) if(a==i) return 2;
    ll ans = 1, c = a;

    // vector<int> fact(10);
    // int hom=0;
    // for (int i : p) {
    //     if(c%i == 0) hom++;
    //     while (c % i == 0) {
    //         fact[i]++;
    //         c /= i;
    //     }
    // }

    for(int i: p){
        if(!(a%i)){
            // if(hom ==1 ){
            //     ans = v[i][fact[i]];
            // }
            // else ans = (ans + power(findVal(a/i), i))%mod;
            ans = (ans + power(findVal(a/i), i))%mod;
        }
    }  
    
    mem[a] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; ll ans = 1, a;
    cin>>n;
    
    // vector<ll> r2(63,1), r3(63, 1), r5(63, 1), r7(63,1);
    // for (int i = 1; i < v[0].size(); i++)
    // {
    //     v[2][i] = (power(v[2][i-1], 2)+ 1)%mod;
    //     v[3][i] = (power(v[3][i-1], 3)+ 1)%mod;
    //     v[5][i] = (power(v[5][i-1], 5)+ 1)%mod;
    //     v[7][i] = (power(v[7][i-1], 7)+ 1)%mod;
    // }
    

    while(n--){
        cin>>a;
        ans = (ans * findVal(a))%mod;
        // p(findVal(a));
    }
    cout<<ans<<endl;

    return 0;
}