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

// vector<bool> vis;
// vector<bool> res;


// bool isSub(string& a, string& b) {
//     // if(vis[s]) return vis[s];
//     int i = 0, j = 0;
//     int m = a.length(), n = b.length();
    
//     while (i < m && j < n) {
//         if (a[i] == b[j]) {
//             i++;
//         }
//         j++;
//     }
    
//     return (i == m);
// }
 
// int main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     int t, n, q;
//     string s, sub;
//     cin>>t;
//     while(t--){
//         cin>>n>>q;
//         cin>>s;
//         map<string, bool> vis;
//         map<string, bool> res;
//         map<char, int> ms;
//         for (int i = 0; i < n; i++)
//         {
//             ms[s[i]]++;
//         }
        
//         while(q--){
//             cin>>sub;
//             map<char, int> msub;
//             msub[sub[0]]++;
//             msub[sub[1]]++;
//             msub[sub[2]]++;
//             if(ms[sub[0]]>= msub[sub[0]]&&
//                ms[sub[1]]>= msub[sub[1]]&&         
//                ms[sub[2]]>= msub[sub[2]])
//                {
//                 if(vis[sub]) {
//                     cout<< (res[sub]? "NO": "YES")<<endl;
//                     continue;
//                 }
//                 vis[sub]=1;
//                 res[sub] = isSub(sub, s);
//                 cout<<( res[sub]? "NO":"YES")<<endl;
//                }
//             else cout<<"YES"<<endl;
//         }
//     }
 
//     return 0;
// }

//! Another Approach:
int main(){
    int t, n,q;
    string s, sub;
    cin>>t;
    while(t--){
        cin>>n>>q;
        cin>>s;
        map<char, vector<int>> have;
        for (int i = 'a'; i <= 'z'; i++)
        {
            have[i] = {};
        }
        
        for (int i = 0; i < n; i++)
        {
            have[s[i]].push_back(i);
        }
        
        while(q--){
            cin>>sub;
            int cur = 0;
            bool nf=0;
            for(char a: sub){
                auto low = lower_bound(have[a].begin(), have[a].end(), cur);
                if(low==have[a].end()) {
                    cout<<"YES"<<endl;
                    nf = 1;
                    break;
                }
                else{
                    cur = *low+1;
                }
            }
            if(!nf) cout<<"NO"<<endl;
        }
    }
    return 0;
}