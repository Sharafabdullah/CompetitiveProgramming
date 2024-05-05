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




/* int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,n,x,a,b;
    cin>>t;
    while(t--){
        set<pair<int,int>> s;
        cin>>n>>x;
        // for (int i = 1; i <= n; i++)
        // {
        //     s.insert({i,i});
        // }
        vector<int> v1(n+1), v2(n+1);
        while(x--){
            cin>>a>>b;
            if(!s.count({a,b})){
                v1[a]++;
                v2[b]++;
                s.insert({a,b});
            }
            // v1[a].push_back(b);
            // v2[b].push_back(a);
            // s.insert({a,b+20});
            // s.insert({b+20,a});
        }
        int mx1= 0, mx2= 0;
        for (int i = 1; i <= n; i++)
        {
            if(v1[i]==n) mx1++;
            if(v2[i]==n) mx2++;
        }
        
        
        // cout<<"add1: "<<add1<<endl;
        // cout<<"add1: "<<add2<<endl;
        cout<<n+max(mx1,mx2)<<endl;
    }

    return 0;
} */

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,n,x,a,b;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<bitset<21>> v(n+1);
        while(x--){
            cin>>a>>b;
            v[a-1].set(b-1);
        }
        int mx = n;
        for (int i = 0; i < (1<<n); i++)
        {
            bitset<21> inter;
            bool f = 1;
            for (int j = 0; j < n; j++)
            {
                if(i & 1<<j){
                    if(f) {inter = v[j]; f =0;}
                    else inter = inter & v[j];
                }
            }
            // cout<<"i's ones: "<<__builtin_popcount(i)<<endl;
            // cout<<"inter.count : "<<inter.count()<<endl;
            mx = max((int)(__builtin_popcount(i)+ inter.count()), mx);
        }
        cout<<mx<<endl;
        
    }

    return 0;
}