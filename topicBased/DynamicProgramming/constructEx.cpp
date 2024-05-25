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

vector<int> canMemo(1000, -1);
bool canConst(string t,int pos, vector<string>& bank){
    if(!canMemo[pos] || canMemo[pos] ==1) return canMemo[pos];
    if(pos==t.length()) return true;

    for(string str: bank){
        if(str.length() + pos <=t.length() && str == t.substr(pos, str.length())){
            if(canConst(t, pos + str.length(), bank)){
                 canMemo[pos] = 1;
                 return true;}
        }
    }
    canMemo[pos] = 0;
    return false;
}

bool canConstTab(string t, int pos, vector<string>& bank){
    vector<bool> tab(t.length()+1);

    for (int i = pos; i < t.length(); i++)
    {
        if(tab[i]){
            for(string word: bank){
                int endS = word.length() + i; bool can = 1;
                if(endS<=t.length()){
                    for (int j = 0; j < word.length(); j++)
                    {
                        if(t[i+j]!=word[j]) {
                            can = 0;
                            break;
                        }
                    }
                    
                } else can = 0;
                if(can) tab[endS] = tab[endS]? 1: can;
            }
        }
    }
    return tab[t.length()];
}

vector<int> cntMemo(1000, -1);
int cntConst(string& t, int pos, vector<string>& bank){
    if(cntMemo[pos]!=-1) return cntMemo[pos];
    if(pos == t.size()) return 1;

    int cnt = 0;

    for(string str: bank){
        int npos = pos+ str.length();
        if(npos <=t.size() && str == t.substr(pos, str.length())){
            cnt += cntConst(t, npos, bank);
        }
    }
    cntMemo[pos] = cnt;
    return cnt;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<string> wordBank1 = {"a", "aa", "aaa"};
    p(canConst("aaaaaaaaaaaaaaaaaaaaaaaaaaaaf", 0 , wordBank1));
    p(canConstTab("aaaaaaaaaaaaaaaaaaf", 0 , wordBank1));

    vector<string> wordBank2 = {"a", "aa", "aaa"};
    string t2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaa";
    p(cntConst(t2, 0, wordBank2));

    string t3 = "aaaa";
    vector<vector<string>> sol;
    
    return 0;
}