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
const ll inf = 1e10+7;
const double eps = (1e-8);

ll n, k, a, tshft=0;
bitset<100007> memo;
vector<bool> vis;
void dfs(int shft, ll cnt, vector<ll>& v){
    if(cnt>=k){
        // p(cnt);
        // p(shft);
        cout<<"YES";
        exit(0);
    }
    // p(cnt);
    // p(shft);
    // if(memo[shft]) return;
    
    // p(tshft);
    // p(shft);
    // memo[shft] = 1;
    for (int i = 1; i <= n; i++)
    {
        if(v[i]==shft){
            // if(vis[i]){
            //     // p(cnt);
            //     // p(shft);
            //     cout<<"YES";
            //     exit(0);
            // }
            int npos =( shft+i)%n;
            vis[i]=1;
            dfs((shft + npos)%n , cnt+1, v);
            vis[i]=0;
        }
    }
    // memo[shft] = 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    vector<ll> v(n+1); v[0] = inf;
    vis = vector<bool>(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin>>a;
        if(a>n) v[i] = inf;
        else {v[i] = ((a-i)%n+n)%n;}
    }
    // for(auto i: v) cout<<i<<"   ";
    // cout<<endl;
    dfs(0,0, v);
    cout<<"NO"<<endl;

    return 0;
}