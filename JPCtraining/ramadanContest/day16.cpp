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

// bitset<3500000> nused;
// vector<bool> used(14);
// ll cnt;
// void bt(string& t, string cur, int pos){
//     if(cur.size()==t.size()){
//         ll n= stoll(cur);
//         cout<<n<<endl;
//         if(n!=0 && sqrt(n) == round(sqrt(n)) ){

//              cnt++; nused[sqrt(n)]=1;
//             }}
//     for (int i = 0; i < t.size(); i++)
//     {
//         if(!used[i]){
//             cur.push_back(t[i]);
//             used[i] = 1;
//             bt(t, cur, i+1);
//             used[i] =0;
//             cur.pop_back();
//         }
//     }
// }


// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     // cout<<"hello"<<endl;
//     // cout<<stol("00100");
//     int size;
//     cnt = 0;
//     string str;
//     cin>>size>>str;
//     // for (ll i = 0; i < 4000000; i++)
//     // {
//     //     s.insert(i*i);
//     // }
    
//     bt(str, "", 0);
//     cout<<cnt<<endl;
//     return 0;
// }

int main(){
    int size;
    ll cnt = 0; 
    string s,n;
    cin>>size>>s;
    vector<int> freq(10);
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]-'0']++;
    }
    // for(int i: freq) 
    for (ll i = 1; i < 4000000; i++)
    {
        bool v = 1;
        n = to_string(i*i);
        vector<int> freqn(10);
        for (int i = 0; i < n.size(); i++)
        {
            freqn[n[i]-'0']++;
        }
        for (int i = 0; i < 10; i++)
        {
            if(i==0){
                if(freqn[i]>freq[i]) {
                    v=0;
                    break;
                }
            }else{
                if(freqn[i]!=freq[i]) {
                    v= 0;
                    break;
                }
            }
        }
        cnt+=v;      
    }
    cout<<cnt<<endl;
    return 0;
}