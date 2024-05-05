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

const int SI  = 30000;

#include<bitset>

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // cout<<SI<<endl;
    int n, m, l, a;
    cin>>n>>m>>l;
    vector<int> N(n+1), M(m+1), L(l+1);
    // cout<<n<<"  "<<m<<endl;
    for (int i = 0; i < n  ; i++)
    {
        cin>>N[i];
        // for(int j=a; j<SI; j+=a) N[a] = 1;
    }
    for (int i = 0; i < m  ; i++)
    {
        cin>>M[i];
        // for(int j=a; j<SI; j+=a) M[a] = 1;
    }
    for (int i = 0; i < l  ; i++)
    {
        cin>>L[i];
        // for(int j=a; j<SI; j+=a) L[a] = 1;
    }
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < l; k++)
            {
                s.insert(N[i]+M[j]+L[k]);
            }
            
        }
        
    }
    
    int k,K;
    cin>>K;
    for (int i = 0; i < K; i++)
    {
        cin>>k;
        cout<<(s.count(k) ? "YES": "NO")<<endl;
    }
    
    return 0;
}