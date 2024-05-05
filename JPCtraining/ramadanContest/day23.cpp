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

    int n, m, k,a, t1,t2,s,A,B;
    cin>>n>>m>>k;
    vector<vi> ver(n+1, vector<int>());
    while(m--){
        cin>>t1>>t2;
        ver[t1].pb(t2);
        ver[t2].pb(t1);
    }
    bitset<200002> safe, vis;
    safe.set();
    vi visAt(n+1, 0);
    deque<pi> q;
    while(k--){
        cin>>t1>>t2;
        q.pb({t1,t2});
    }
    cin>>A>>B;

    sort(all(q), [](auto f, auto s){ return f.second<s.second;});
    // cout<<endl;
    // for(auto [f,s]: q) cout<<f<<"  "<<s<<endl;
    while(!q.empty()){
        s = q.size();
        while(s--){
            auto t= q.front(); q.pop_front();
            safe[t.first] = 0;
            if(t.second> visAt[t.first]){
                visAt[t.first] = t.second;
                for(int v: ver[t.first]){
                    q.push_back({v, t.second-1});
                }
            }
        }
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<i<<": "<<safe[i]<<endl;
    // }
    
    deque<int> qsrch;
    if(safe[A]&& safe[B])  qsrch.pb(A);
    while(!qsrch.empty()){
        s= qsrch.size();
        while(s--){
            t1 = qsrch.front(); qsrch.pop_front();
            // p(t1);
            vis[t1] =1;
            if(t1==B){
                cout<<"YES"<<endl;
                exit(0);
            }
            for(int v: ver[t1]){
                if(v==B){
                    cout<<"YES"<<endl;
                    exit(0);
                }
                if(safe[v] && !vis[v]) qsrch.push_back(v);
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

/* 
10 10 2
9 10
5 9
1 2
2 3
3 8
3 5
5 7
7 6
6 4
4 1
8 3
3 1
6 4
 */