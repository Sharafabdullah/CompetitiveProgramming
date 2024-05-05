#include <bits/stdc++.h>
using namespace std;

#define P(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << a << endl;
err(++it, args...);}

#define all(v)        ((v).begin()), ((v).end())
//can go back and forwards - almost all types
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//#define pb            push_back
#define mp            make_pair
#define B             begin()
#define E             end()


typedef long long ll;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
const ll inf = 1e9;
const double eps = (1e-8);
const ll mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int i =0,j=0;
        while(i<s.size()&&s[i]=='0'){
            i++; j++;
        }
        ll ans = 0;
        while(j<s.size()){
            if(s[j]=='0'){
                ans +=(j-i+1); j++;i++;
            } else j++;
        }
        cout<<ans<<endl;
    }

    return 0;
}