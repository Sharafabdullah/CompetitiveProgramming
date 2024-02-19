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
freopen("bcount.in", "r", stdin);

	freopen("bcount.out", "w", stdout);


    int q, n, c, f, s;
    cin>>n>>q;
    vi h(n+1, 0);
    vi g(n+1, 0);
    vi j(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin>>c;
        h[i]= h[i-1];
        g[i]= g[i-1];
        j[i]= j[i-1];
        if(c==1) h[i]++;
        else if(c==2) g[i]++;
        else j[i]++;
    }

    while(q--){
        cin>>f>>s;
        cout<<h[s]-h[f-1]<<" "
            <<g[s]-g[f-1]<<" "
            <<j[s]-j[f-1]<<endl;
    }
    
    return 0;
}