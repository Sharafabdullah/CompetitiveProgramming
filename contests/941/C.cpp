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

const ll mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, t,a;
    cin>>t;
    while(t--){
        cin>>n;
        set<int> s;
        while(n--){
            cin>>a;
            s.insert(a);
        }
        if(s.size()==1) {cout<<"Alice"<<endl; continue;}
        int cnt = 0;
        bool A= s.size()%2;
        bool r = 0;
        // if(s.size()%2) A=1;
        // auto ;
        // if(*it>1) cnt++;
        int prev = 0;
        for(auto it = s.begin(); it!=s.end(); it++){
            if(*it-prev > 1){
                // p(*it);
                if(r==0) A=1;
                else A=0;
                break;
            }
            prev = *it;
            r ^= 1;
        }
        //  p(A);
        // if(cnt%2) A = !A;
        if(A) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }

    return 0;
}