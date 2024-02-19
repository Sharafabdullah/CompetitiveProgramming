// #include <bits/stdc++.h>
// using namespace std;


// #define all(v)				((v).begin()), ((v).end())
// #define repv(i, v)		for(int i=0;i<(v).size();++i)
// #define rep(i, j, n)	for(int i=(j);i<(int)(n);++i)
// #define dow(i, j, n)	for(int i=(j);i>=(int)(n);--i)

// #define pb					push_back
// #define mp					make_pair
// #define p(x)				cout<<#x<<" = { "<<x<<" }\n"


// typedef long long ll;
// typedef long double   ld;
// typedef pair<int, int> pi;
// typedef vector<int>       vi;
// typedef vector<double>    vd;
// typedef vector< vi >      vvi;
// const ll inf = 1e9;
// const double eps = (1e-8);




// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     int n, inst=0;
//     cin>>n;
//     vi w(2*n);
//     for (int i = 0; i < 2*n; i++)
//     {
//         cin>>w[i];
//     }
//     sort(w.begin(), w.end());
//     vi diff(2*n);
//     for(int i: w) cout<<i<<" ";
//         cout<<endl;
//     while(w.size()>2){
//         fill(diff.begin(), diff.end(), inf);
//         for (int i = 0; i < w.size()-1; i++)
//         {
//             diff[i] = w[i+1] - w[i];
//         }
//         auto me = min_element(diff.begin(), diff.begin()+w.size()-1);
//         inst += *me;
//         int ind = distance(diff.begin(), me);
//         // for(int i: w) cout<<i<<" ";
//         // cout<<endl;
//         cout<<"The index is: "<<ind<<endl;
//         w.erase(w.begin()+ind, w.begin()+ind+2);
//     }
//     cout<<inst;

//     return 0;
// }

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

    int n,ans = inf; cin>>n; n*=2;
    vi a(n); 
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
            sort(all(a));

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            vi b;
            for (int k = 0; k < n; k++)
            {
                if(k!= i && k!=j) b.pb(a[k]);
            }
            int cnt =0;
            for (int l = 0; l < b.size()-1; l+=2)
            {
                cnt += b[l+1]-b[l];
            }
            // cout<<"Cnt is: "<<cnt<<"i is: "<<i<<" - j: "<<j<<endl;
            ans = min(ans, cnt);
            b.clear();  
        }
    }
    cout<<ans;
    

    return 0;
}