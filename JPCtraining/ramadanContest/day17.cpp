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

    string s;
    int cnt = 0;
    cin>>s;
    vector<bitset<26>> f1(s.length()+2, bitset<26>(0)), f2(s.length()+2, bitset<26>(0));
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        f1[i+1] = f1[i];
        f1[i+1][s[i]-'a'].flip() ;
        f2[n-i-1] = f2[n-i];
        f2[n-i-1][s[i]-'a'].flip() ;
    }
    // reverse(s.begin(), s.end());
    // cout<<s<<endl;
    // for (int i = s.length()-1; i >= 0; i--)
    // {
    //     f2[i] = f2[i+1];
    //     f2[i][s[i]-'a'] = ~f2[i][s[i]-'a'] ;
    // }
    for (int i = 1; i < s.length(); i++)
    {
        // cout<<"f1 "<<i<<": "<< f1[i]<<endl;
        // cout<<"f2 "<<i<<": "<< f2[i]<<endl;
        // cout<<endl;
        if(f1[i].count()<=1 && f2[i].count()<=1) cnt++;
    }
    
    
    cout<<cnt<<endl;

    return 0;
}