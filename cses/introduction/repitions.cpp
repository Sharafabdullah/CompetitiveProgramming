#include <bits/stdc++.h>
#include<algorithm>
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

    string s; 
    char pc; 
    ll mmax=0, cur = 0;
    cin>>s;
    pc = s[0];
    for (int i = 0; i < s.length(); i++)
    {
        if(pc==s[i]) cur++;
        else{
            mmax = max(mmax, cur);
            pc = s[i];
            cur=1;
        }
    }
    cout<<max(mmax, cur);
    

    return 0;
}