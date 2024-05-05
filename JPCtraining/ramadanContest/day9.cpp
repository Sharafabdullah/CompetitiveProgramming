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
const int mod = 1e9 + 7;
vector<ll> factarr;

ll fact(int n){
    if (n==1 || n==0) return 1LL;
    if(factarr[n]) return factarr[n];
    else{
        factarr[n] = (fact(n-1)* n)%mod;
        return factarr[n];
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    factarr= vector<ll>(45,0);
    factarr[0] =1;
    factarr[1] = 1;
    // cout<<"Fact of the first 30 num: "<<endl;
    // for (int i = 0; i < 30; i++)
    // {
    //     cout<<i<<"- "<<fact(i)<<endl;
    // }
    // cout<<endl;
    int t;
    string s; 
    cin>>t;
    while(t--){
        cin>>s;
        vector<int> freq(28);

        int ocnt = 0;
        int rcnt =0;
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]-'a']++;
        }
        // cout<<"Freq: ";
        // for (int i = 0; i < freq.size(); i++)
        // {
        //     cout<<freq[i]<<"    ";
        // };
        // cout<<endl;
        vector<int> rp(28);
        for (int i = 0; i < freq.size(); i++)
        {
            if(freq[i]%2) ocnt++;
            else {
                rcnt+= freq[i];
                rp[i] = freq[i]/2;
                }
        }
        if(ocnt<=1){
            // ecnt /= 2;
            int n = s.length()/2;
            // cout<<"ecnt"<<ecnt<<endl;
            ll ans = fact(n);
            for (int i = 0; i < rp.size(); i++)
            {
                if(rp[i]!=0) ans /= fact(rp[i]);
            }
            
            cout<<ans<<endl;
        }
        else{
            // cout<<"ocnt: "<<ecnt<<endl;
            // cout<<"ecnt: "<<ecnt<<endl;

            cout<<0<<endl;
        }
    }

    return 0;
}