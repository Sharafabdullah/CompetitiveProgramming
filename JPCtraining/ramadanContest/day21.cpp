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
const ll inf = 1e9+7;
const double eps = (1e-8);

ll a, n, k;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    vector<int> v(n+1); v[0] = inf;
    for (int i = 1; i <= n; i++)
    {
        cin>>a;
        if(a>n) v[i] = inf;
        else {v[i] = ((a-i)%n+n)%n;}
    }
    // for(auto i: v) cout<<i<<"   ";
    // cout<<endl;
    deque<int> q;
    int t, shft;
    for (int i = 1; i < v.size(); i++)
    {
        if(!v[i]) q.push_back(i);
    }
    int d = 0;
    while(!q.empty()){
        if(d>n || d>=k){
            // p(k);
            // p(n);
            // p(d);
            cout<<"YES"<<endl;
            exit(0);
        }
        int s = q.size();
        bitset<100002> vis;
        // for(int i: q) cout<<i<<"    ";
        // cout<<endl;
        d++;
        while(s--){
            int t = q.front(); q.pop_front();
            vis[t] = 1;
            shft = (2 * v[t] + t)%n;
            // p(t);
            // p(shft);
            // cout<<endl;
            for (int i = 1; i < v.size(); i++)
            {
                if(v[i] == shft && t == i){
                    cout<<"YES";
                    exit(0);
                }
                if(v[i] == shft && !vis[i]){
                    q.push_back(i);
                }
            }
        }
    }
    cout<<"NO"<<endl;

    return 0;
}