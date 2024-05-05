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
const ll mod = 1e9 + 7;

int fact2(int n){
    int cnt=0;
    while(n%2==0){
        n /= 2;
        cnt++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, a;
    unsigned long long ans=1;
    cin>>n;
    vector<int> v(n);
    vector<unsigned long long> pos(63);
    pos[0]= 1;
    for (int i = 1; i < pos.size(); i++)
    {
        pos[i] = (1 + pos[i-1]*pos[i-1])%mod;
    }
    // for(auto i: pos) cout<<i<<" ";
    
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        // p(a);
        // p(pos[fact2(a)]);
        ans = (ans* pos[fact2(a)])%mod;
    }
    cout<<ans<<endl;
    
    

    return 0;
}