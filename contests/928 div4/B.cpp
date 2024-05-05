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

    int n, t;
    cin>> t;
    while(t--){
        cin>>n;
        int f1i = -1, f1j = -1;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
            for (int j = 0; j < v[i].length(); j++)
            {
                if(f1i==-1 && v[i][j]=='1'){
                    f1i = i;
                    f1j = j;
                }
            }
            
            
        }
        if(v[f1i + 1][f1j]=='0' || v[f1i][f1j+1]=='0') cout<<"TRIANGLE"<<endl;
        else cout<<"SQUARE"<<endl;
        
    }

    return 0;
}