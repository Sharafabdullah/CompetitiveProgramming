#include <bits/stdc++.h>
using namespace std;

#define P(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << a << endl;
err(++it, args...);}

#define all(v)        ((v).begin()), ((v).end())
//can go back and forwards - almost all types
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//#define pb            push_back
#define mp            make_pair
#define B             begin()
#define E             end()


typedef long long ll;
typedef long double   ld;
typedef pair<ll, ll> pi;
typedef vector<ll>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
const ll inf = 1e9;
const double eps = (1e-8);
const ll mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t,n,k,sum;
    cin>>t;
    while(t--){
        cin>>n>>k;
        sum = 0;
        vi a(n);
        for (ll i = 0; i < n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(n==1) {
            cout<<a[0]<<endl;
            continue;
        }
        ll df = 0, ind = 0;
        for (ll i = 1; i <= k; i++)
        {
            ll mx = 0;
            for (ll j = 0; j < n; j++)
            {
                if(j==0) df = a[j]-a[j+1];
                else if(j==n-1) df = a[j]-a[j-1];
                else df = max(a[j]-a[j-1],a[j]-a[j+1]);
                // P(df);
                if(df>mx){
                    mx = df;
                    ind = j;
                }
            }

            // P(sum, mx,a[ind]);
            sum-=mx; a[ind]-=mx; 
            for(auto j: a) cout<<j<<"  ";
            cout<<endl;
        }
        cout<<sum<<endl;
        
    }

    return 0;
}