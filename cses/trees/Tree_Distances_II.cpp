#include<bits/stdc++.h>
using namespace std;
typedef long long l; const l N=3e5;l n,u,v,i;
#define r(b,e) for(i=b;i<e;i++)
vector<l> g[N],z(N,1),a(N);void d(l c,l p){for(l x:g[c])if(x-p)d(x,c),z[c]+=z[x],a[c]+=a[x]+z[x];}void s(l c,l p,l w){a[c]=w;for(l x:g[c])if(x-p)s(x,c,w-2*z[x]+n);}int main(){cin>>n;r(0,n-1)cin>>u>>v,g[u].push_back(v),g[v].push_back(u);d(1,0); s(1,0,a[1]); r(1,n+1)cout<<a[i]<<" ";}