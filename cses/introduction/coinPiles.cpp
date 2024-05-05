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

    int n, a, b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        int tmp = max(a,b);
        b= min(a, b);
        a = tmp;
        if((a+b)%3 != 0){}
        else{
            if(b<a/2) {}
            else{
                if((a==b && b==0)|| (a>1 && b>=1)){
                    cout<<"YES"<<endl;
                    continue;
                }
            }
        }
        cout<<"NO"<<endl;
    }

    return 0;
}