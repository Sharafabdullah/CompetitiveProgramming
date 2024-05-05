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

    int n,x,y,cnt=0;
    cin>>n;
    set<pair<int,int>> s;
    while(n--){
        cin>>x>>y;
        s.insert({x,y});
    }
    for(auto p1: s){
        for(auto p2: s){
            if(p1.first != p2.first && p1.second !=p2.second){
                if(s.count({p1.first, p2.second})&& s.count({p2.first, p1.second})) cnt++;
            }
        }
        // s.erase(p1);
    }
    cout<<cnt/4<<endl;

    return 0;
}