#include <bits/stdc++.h>
#include<algorithm>

using namespace std;


void solve(){
    string s;
    cin>>s;
    
    string s_without_plus;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='+') continue;

        s_without_plus += s[i];
    }

    sort(s_without_plus.begin(), s_without_plus.end());

    for(int i =0; i<s_without_plus.size(); i++){
        cout<< s_without_plus[i];
        if(i != s_without_plus.size()-1) cout<<'+';
    }
}


int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) {
        solve();
    }

    return 0;
}
