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

map<ll,map<ll,ll>> m;
ll n,k,b,s,mx;
vector<ll> p(2e5+10), a(2e5+10);

unsigned long long dp(int i,ll k ){
    // cout<<"i is: "<<i<<" and k: "<<k<<endl;
    // cout<<p[i]<<"   "<<a[i]<<endl;  
    if(k==0) return 0;
    if(a[i]==mx) return ((unsigned long long)k)*mx;
    if(m[i][k]) return m[i][k];
    if(i==p[i]) return (unsigned long long)k*a[i];
    return m[i][k] =  max(dp(p[i], k-1)+a[i], (unsigned long long)k*a[i]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while (t--)
    {
        m.clear();

        cin>>n>>k>>b>>s;
        rep(i,1,n+1){
            cin>>p[i];
        }
        // P(n);
        mx = -inf;
        rep(i,1,n+1){
            cin>>a[i];
            mx = max(mx, a[i]);
        }
        // rep(i,0,n+1)cout<<a[i]<<"  ";
        // cout<<endl;
        ll Bans = dp(b,k);
        // cout<<"Sans turn"<<endl;
        ll Sans = dp(s,k);
        // P(Bans);
        // P(Sans);
        if(Bans>Sans) cout<<"Bodya"<<endl;
        else if (Sans>Bans) cout<<"Sasha"<<endl;
        else cout<<"Draw"<<endl;
    }
    
    

    return 0;
}