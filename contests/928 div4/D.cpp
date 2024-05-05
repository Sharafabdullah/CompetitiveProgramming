#include <bits/stdc++.h>
#include<bitset>
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

     int t, n, a;
    cin>>t;
    while(t--){
        cin>>n;
        int g = 0;
        unordered_set<bitset<31>> s;
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            bitset<31> b(a);
            if(s.count(b.flip())==0) g++;
             s.insert(b);
        }
        cout<<g<<endl;
        s.clear();
    }
    return 0;
}