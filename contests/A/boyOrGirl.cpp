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
    string c; cin>>c;
    set<int> s;
    for (size_t i = 0; i < c.length(); i++)
    {
        s.insert(c[i]);
    }
    if(s.size()%2==0) cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
    

    return 0;
}