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


int numOfp(int p, int n){
    int num=0, i=1;
    // while((int)(n/pow(p, i))!=0){
    //     num+= (int)(n/pow(p, i));
    //     i++;
    // }
    for(int i = p; n/i>=1; i*=p){
        num += n/i;
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k1, k2;
    cin>>n;
    k1= numOfp(2, n);
    k2= numOfp(5, n);
    cout<<min(k1,k2);
    

    return 0;
}