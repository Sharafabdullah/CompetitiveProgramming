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

    // vector<ll> pow((int)13);
    ll t,n, j=0;
    // for (int i = 2; i < 10000; i = i<<1) pow[j++]= i;
    vector<int> s(50000);
    for (int i = 1; i < 100; i++)
    {
         s[i*i*2] = 1;
        s[i*i*4] = 1;
    }
    for (int i = 1; i < s.size(); i++)
    {
        s[i] += s[i-1] ;
    }
    
    // for(int i: pow) cout<<i<<"  ";
    // vector<int> ans(10005);
    // for ( n = 0; n < 10004; n++)
    // {
    //     int cnt = 0;
    //     for (int i = 0; i <= n; i++)
    //     {
    //         if(s[i]){
    //             cnt++;
    //         }
    //     }
    //     ans[n] = cnt;
    // }
    
    // cout<<"done loop"<<endl;
    cin>>t;
    while(t--){ cin>>n;
        // cout<<distance(pow.begin(), upper_bound(pow.begin(), pow.end(), n))<<endl;
        
        cout<<s[n]<<endl;
        
    }

    return 0;
}