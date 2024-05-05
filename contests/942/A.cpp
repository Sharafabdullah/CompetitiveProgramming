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

    int t,n,a, r=0;
    cin>>t;
    while(t--){
        // P(r++);
        cin>>n;
        set<pair<int,int>> s;
        bool f = 1;
        for (int i = 1; i < n+1; i++)
        {
            cin>>a;
            // cout<<i<<"   "<<a<<endl;
            s.insert({i,a});
            if(s.find({a,i})!=s.end()) {
                // cout<<"found"<<endl;
                // cout<<a<<"   "<<i<<endl;
                if(f) cout<<2<<endl;
                f= 0;
                // break;
            }
        }
        // s.clear();
        if(f) cout<<3<<endl;
    }
    // rep(n,2,51){

    //     set<pair<int,int>> s;
    //     bool f = 1;
    //     for (int i = 1; i < n+1; i++)
    //     {
    //         cin>>a;
    //         s.insert({i,a});
    //         if(s.count({a,i})) {
    //             cout<<2<<endl;
    //             f= 0;
    //             break;
    //         }
    //     }
    //     if(f) cout<<3<<endl;
    // }

    return 0;
}