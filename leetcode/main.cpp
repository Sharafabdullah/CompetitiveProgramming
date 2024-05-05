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
    vi arr(6);
    for(int& i: arr) cin>>i;
    map<int, int> m;
    for(int i: arr) m[i]++;
    unordered_set<int> unique;
    for(auto e: m){
        if(unique.count(e.second)) {
            cout<<"false";
            return 0;
        }
        unique.insert(e.second);
    }
    cout<<"true"<<endl;

    return 0;
}