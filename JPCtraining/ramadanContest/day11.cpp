

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

    int n,a;
    cin>>n;
    set<int> s;
    int mx =0;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        s.insert(a);
    }
    
    for (int i = 0; i < 1e6+5; i++)
    {
        int cur = 0;
        if(s.count(i)){
            for (int j = i; j < 1e6+5; j = j<<1)
            {
                if(s.count(j)){
                    cur++;
                    s.erase(j);
                } else{
                    break;
                }
            }
            
        }
        mx = max(mx, cur);
    }
    cout<<n - mx<<endl;
    

    return 0;
}