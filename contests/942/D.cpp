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

    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vi a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        priority_queue<int> lst(all(a));
        set<int,greater<int>> s;
        for (int i = 0; i < k; i++)
        {
            s.insert(lst.top()); lst.pop();
        }
        
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        
        priority_queue<pair<int,int>> pq;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if(b[i]>a[i]) {
                pq.push({b[i],a[i]});
                s.insert({a[i],b[i]});
                p-=a[i];
            }
        }

        for (int i = 0; i < k; i++)
        {
            pq.pop();
            if(pq.empty()) break;
        }
        while(!pq.empty()){
            auto t = pq.top(); pq.pop();
            p+= t.first;
            P(p);
            cout<<t.first<<"   "<<t.second<<endl;
        }
        if(p<=0) cout<<0<<endl;
        else cout<<p<<endl;

    }

    return 0;
}