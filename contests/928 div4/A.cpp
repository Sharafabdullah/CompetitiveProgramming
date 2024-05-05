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

    int n, bs= 0, as=0;
    cin>>n;
    while(n--){
        bs = 0; as = 0;
        string s;
         cin>>s;
         for (int i = 0; i < s.length(); i++)
         {
            if(s[i]=='A') as++;
            else bs++;
         }
         if(as>bs) cout<<"A"<<endl;
         else cout<<"B"<<endl;
    }

    return 0;
}