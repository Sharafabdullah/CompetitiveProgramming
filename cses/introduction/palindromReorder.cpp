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

    string s, sn;
    int odd=0;
    cin>>s;
    sn.reserve(s.length());
    vi arr(27, 0);
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i]-'A']++;
    }
    for (int i = 0; i < 27; i++)
    {
        if(arr[i]%2){ odd++;
        sn.push_back(i+'A'); 
        arr[i]--;
        }
    }
    
    if(odd>1 && s.length()>2){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        for (int i = 0; i < 27; i++)
        {
            for (int j = 0; j < arr[i]; j+=2)
            {
                sn.push_back(i+'A');
                // sn.insert(sn.begin(), i+'A');
            }
        }
        string substr;
        if (odd==1)  substr = sn.substr(1);
        else  substr = sn;
        reverse(substr.begin(), substr.end());
        sn.insert(0,substr);
        cout<<sn<<endl;
        
    }

    return 0;
}