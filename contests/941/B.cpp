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

const ll mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, n,m;
    cin>>t;
    while(t--){
        int up =0, down = 0, r =0, l = 0;
        cin>>n>>m;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
        }

        pair<int,int> a1={-1,-1}, a2={-1,-1}, b1{-1,-1},b2{-1,-1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c=s[i][j];
                if(c=='W'){
                    if(a1 == make_pair(-1,-1)){
                        a1 = {i,j};
                        a2 = {i,j};
                    }
                    a1 = {min(a1.first, i), min(a1.second, j)};
                    a2 = {max(a2.first, i), max(a2.second, j)};
                }
                else{
                    if(b1 == make_pair(-1,-1)){
                        b1 = {i,j};
                        b2 = {i,j};
                    }
                    b1 = {min(b1.first, i), min(b1.second, j)};
                    b2 = {max(b2.first, i), max(b2.second, j)};
                }
            }
            
        }
        // p(a1.first);
        // p(a1.second);
        // p(a2.first);
        // p(a2.second);
        // p(b1.first);
        // p(b1.second);
        if(a1==make_pair(0,0) && a2==make_pair(n-1,m-1) ||b1==make_pair(0,0) && b2==make_pair(n-1,m-1)  ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        // if(up==m && down == 0 || up==0&&down==m || r==n && l==0 || r==0&&r==n) cout<<"NO"<<endl;
        // else cout<<"YES"<<endl;
        
        
    }

    return 0;
}