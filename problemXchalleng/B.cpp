#include <bits/stdc++.h>
using namespace std;


#define all(v)				((v).begin()), ((v).end())
#define repv(i, v)		for(int i=0;i<(v).size();++i)
//can go backwards and forwards - almost all stl types
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define dow(i, j, n)	for(int i=(j);i>=(int)(n);--i)

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);}

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

const ll mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,n,a,o,e;
    cin>>t;
    while(t--){
        // cout<<"hi"<<endl;
        cin>>n; n*=2;
        e=0,o=0;
        while(n--){
            cin>>a;
            if(a%2) o++;
            else e++;
        }
         cout<<(o==e?"YES":"NO")<<endl;
    }

    return 0;
}