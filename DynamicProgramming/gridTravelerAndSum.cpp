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
typedef vector< vi >      vvi;
typedef vector<double>    vd;
const ll inf = 1e9;
const double eps = (1e-8);

//! You have a gird m*n, in how many way can you traverse from top left to bottom right using only step right and step down

//* Memo Recipe:
//*1- Make a solution work - visualize as trees (usually like backtracking - general dfs)
//*2- Make it fast - save and return 


//* Tabulation Recipe
//* Visualize the problem as table -> find the table size
//* Init tabel with defaults -> choose the seed value 
//* Iterate through the table and find out how currect position affect future pos

ll gridTrav(int m, int n, map<pair<int,int>, ll>& memo){
    if(memo[{m, n}]!=0){
        return memo[{n,m}];
    }
    if(m==1 && n==1) return 1;
    if(m==0 || n==0) return 0;
    memo[{m,n}] = memo[{n,m}] = gridTrav(m-1, n, memo) + gridTrav(m, n-1,memo);
    return memo[{n,m}];
}

ll gridTravTab(int m, int n){
    vector<vector<ll>> table(m+1, vector<ll>(n+1));
    table[1][1] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(j != n) table[i][j+1] += table[i][j];
            if(i != m) table[i+1][j] += table[i][j];
        }
        
    }
    
    return table[m][n];
}

//* Can we find a sum to target using array of positive int - you  can choose any number how ever you want 
//* from O(n^m) -> O(m*n) time
//* from O(m) -> O(m) space
vector<int> memoSum(10000, -1); //* target shouldn't exeed 10000 - or you can use a map
bool canSum(int t, vector<int>& nums){
    if(!t) return 1;
    if(t<0) return 0;
    if(memoSum[t]!=-1) return memoSum[t]; //* If we have reached this target before return the res we found
    for(int i: nums){
        if(canSum(t-i, nums)) {
            memoSum[t-i] = 1;
            return true;
            }
    }
    memoSum[t] = 0;
    return false;
}

bool canSumTab(int t, vector<int>& nums){
    //* the table is for the target sum 
    vector<bool> v(t+1);
    v[0] =1;
    for (int i = 0; i < t+1; i++)
    {
        if(v[i]){
            for(auto n: nums){
                if(n+i < t+1) v[n+i] = 1;
                else break;
            }
        }
    }
    return v[t];
}
//* Return any combination that gives true in the prev example
//* memo changed it from O(n^m) in the worst case to O(n*M)
/* void howSum(int t,int cur,  vector<int>& num, vector<int>& res){
    if(!t) {
        res.pb(-1);
    }
    if(t<0) return;

    for(int i: num){
        howSum(t-i, i, num, res);
        if(res.size()) {
            res.pb(i);
            return;
        }
    }
} */


map<int, int> hmemo;
bool howSum(int t, vector<int>& num, vector<int>& res){
    if(hmemo.count(t)) return hmemo[t];
    if(!t) return true;
    if(t<0) return false;

    for(int i: num){
        if(howSum(t-i, num, res)){
            res.push_back(i);
            hmemo[t-i] = 1;
            return true;
        }
    }
    hmemo[t] = 0;
    return false;
}

void howSumTab(int t, vector<int>& num, vector<int>& res){
    vector<vi> tab(t+1, vi());
    vector<bool> reachable(t+1, 0);
    reachable[0] = 1;
    //* Time: O(m*m*n)
    for (int i = 0; i < tab.size(); i++)
    {
        if(reachable[i]){
            for(auto n: num){
                if(i+n<=t){
                    reachable[i+n] = 1;
                    tab[i+n] = tab[i];
                    tab[i+n].push_back(n);
                }
            }
        }
    }
    // for(vi c: tab){
    //     for(int cc: c) cout<<cc<<"  ";
    //     cout<<"||";
    // }
    cout<<endl;
    res = tab[t];
}

map<pair<int,int>, vector<int>> bmemo;
vector<int> bestSum(int t, vector<int>& num,vector<int>& cur, vector<int>& best){
    // if(hmemo.count({cur.size(), t})) return {};
    if(!t) return cur;
    if(t<0) return {};
    vector<int> res;
    for(int i: num){
        // if(howSum(t-i, num, res)){
        //     res.push_back(i);
        //     hmemo[t-i] = 1;
        //     // return true;

        // }
        cur.push_back(i);
        vector<int> res = bestSum(t-i, num, cur, best);
        if(res.size()  && res.size()<best.size() || !best.size()) best = res;  
        cur.pop_back();
        // cur.pop_back();
    }
    // bmemo[{cur.size(), t}] = {};
    return {};
}

void bestSumTab(int t, vector<int>& num, vector<int>& res){
    vector<vi> tab(t+1, vi());
    vector<bool> reachable(t+1, 0);
    reachable[0] = 1;
    //* Time: O(m*m*n)
    for (int i = 0; i < tab.size(); i++)
    {
        if(reachable[i]){
            for(auto n: num){
                if(i+n<=t){
                    reachable[i+n] = 1;
                    if(tab[i+n].empty() || tab[i].size()<tab[i+n].size()-1){
                        tab[i+n] = tab[i];
                        tab[i+n].push_back(n);
                        
                    }
                }
            }
        }
    }
    // for(vi c: tab){
    //     for(int cc: c) cout<<cc<<"  ";
    //     cout<<"||";
    // }
    // cout<<endl;
    res = tab[t];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<pair<int,int>, ll> memo;
    ll ans = gridTrav(18,18, memo);
    ll ans2 = gridTravTab(18,18);
    p(ans);
    p(ans2);


    vector<int> sum = {2,8,4,18};
    p(canSum(1021, sum));
    p(canSumTab(1021, sum));

    //! How Sum: 
    //if we want all combinations then use backtracking- check leetcode combinations 2
    vector<int> tmp;
    // howSum(35, sum, tmp);
    howSumTab(24,sum, tmp );
    cout<<"HowSumTab: ";
    for(int i: tmp) cout<<i<<"  ";

    //! best sum: 
    vector<int> best, cur;
    //this is implemented using brute force not dp
    bestSum(24, sum,cur, best);
    cout<<endl<<"best rec: ";
    for(int i: best) cout<<i<<"  ";

    cout<<endl<<"Best Sum Tab: ";
    bestSumTab(24, sum, tmp);
    for(int i: tmp) cout<<i<<"  ";


    return 0;
}