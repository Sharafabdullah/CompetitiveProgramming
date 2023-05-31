#include<iostream>
#include<set>
#include<vector>
#include<deque>
#include<list>
#include<algorithm>
#include <utility>
#include<iterator>

#include<sstream>
using namespace std;

int main(){

    string a, b; getline(cin, a); getline(cin, b);
    int res=0;
    for (size_t i = 0; i < a.length(); i++)
    {
        if(tolower(a[i])<tolower(b[i])) {res = -1; break;}
        else if(tolower(a[i])>tolower(b[i])){
            res=1; break;
        }
    }
    cout<<res;
    

    return 0;
}