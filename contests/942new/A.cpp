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


multiset<int> s1,s2;
bool cmp(){
    auto it1 = s1.begin(), it2=s2.begin();
    for(;it1!=s1.end();it1++,it2++){
        if(*it1 > *it2) return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        s1.clear(); s2.clear();
        cin>>n;
        int a,b;
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            s1.insert(a);
        }
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            s2.insert(a);
        }
        int cnt= 0;
        while(cmp()){
            auto it = s1.end(); it--;
            s1.erase(it);
            s1.insert(1);
            // for(auto i: s1) cout<<i<<"  ";
            // cout<<endl;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    

    return 0;
}