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

int canSum(vi& n, int t, int start){
    //* Can be solved using recursion dp - tab dp - two rows tab dp
    bitset<1000> sub = 1<<t;
    for (int i = 0; i < n.size(); i++)
    {
        sub |= sub>>n[i];
    }
    return sub[0];
    
}

vector<vi> m(1000, vi(1000, 0));
int dp(vi& n, int s, int i){
    if(s<0 || i>n.size()) return 0;
    if(s==0 || i==0) {
        m[i][s] = 1;
        return 1;
    }
    if(m[i][s]) return m[i][s];
    m[i][s] = dp(n, s, i+1)+ dp(n, s-n[i-1], i+1);
    return m[i][s];
}
vector<vi> minDP(100, vi(100,-1));
bool minDiffDP(vi& n, int i, int s){
    if(minDP[i][s]!=-1) return minDP[i][s];
    if(s==0) return 1;
    if(i>n.size()) return 0;

    minDP[i][s] = minDiffDP(n, i+1, s);
    if(i!=0) minDP[i][s] |= minDiffDP(n, i+1, s-n[i-1]);;
    return minDP[i][s];
}
int minDiff(vi& n){
    //! want to find s1 & s2 s.t s1+s2 = sum(n) && diff= abs(s1-s2) is min
    //* -> assume s1<=s2 -> want to minimize diff = 2s2 - sum;
    int s=0,diff = INT_MAX;
    for(int i: n) s+=i;
    for (int  i = 0; i <= s; i++)
    {
        minDiffDP(n, 0, s-i);
    }
    
    
    // p(minDiffDP(n, 1, s));
    for (int i = 0; i <= s; i++)
    {
        cout<<minDP[n.size()][i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i <= s/2; i++)
    {

        if(diff > abs(s - 2*i) && minDP[n.size()][i]==1){ 
            diff = abs(s-2*i);
        
        }
    }
    return diff;
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //* a collection of items each with profit and weight - how to maximize the profit given a target weight
    //* Types: 1- 01 (an item is either included or ex) states: weight - number of items
    //* 2- Bounded(items can be included n number of instances at max) 
    //* 3-Unbounded
    //* 1- Franctional (greedy - not dp, start with items with max profit rate) 2- Integer

    //* Variations: 1-subset sum 
    //* 2- coins change
    //*2-partition equal subset sum 3-

    //* elements are bounded to 1 usage
    vi n = {1,2,1,5,20};
    p(canSum(n, 6, 0));
    // p(dp(n, 3, 1));
    p(minDiff(n));
    
    return 0;
}