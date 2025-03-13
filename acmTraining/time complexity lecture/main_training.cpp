#include <bits/stdc++.h>
using namespace std;


void solve1(){
    string s;
    cin>>s;
    string sorted_string = "";
    for(int i = 0; i<s.size(); i++){
        if(s[i]=='+') continue;
        sorted_string += s[i];
    }
    sort(sorted_string.begin(), sorted_string.end());
    for(int i = 0; i<sorted_string.size(); i++){
        cout<<sorted_string[i];
        if(i == sorted_string.size()-1) break;
        cout<<'+';
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while(t--)
        solve1();

    return 0;
}
