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

    string str1, str2,res; cin>>str1>>str2;
        int i;
        for( i= 0; i<min(str1.length(), str2.length()); i++){
            // res += (to_string(str1[i])+to_string(str2[i]));
            // cout<<to_string('a')<<endl;
            res+= str1[i];
            res+= str2[i];
            cout<<res<<endl;
        }
        if( str1.length()> str2.length()) res+= str1.substr(i);
        else if(str1.length()< str2.length()) res+= str2.substr(i);
        cout<< res;

    return 0;
}