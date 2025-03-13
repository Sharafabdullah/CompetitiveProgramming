#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a,b,c; //3 ? It's basically the same as 1
    cin>>a>>b>>c; 
    bool answer_bigger_than_10 = 0;
    if(a+b >= 10) answer_bigger_than_10 = 1;
    if(a+c >= 10) answer_bigger_than_10 = 1;
    if(b+c >= 10) answer_bigger_than_10 = 1;

    if(answer_bigger_than_10) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    cin >> t; //1
    while(t--) //t
        solve();

    return 0;
}
