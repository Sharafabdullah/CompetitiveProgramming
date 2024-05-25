#include<iostream>
using namespace std;

int main(){

    long long k, n,odds;
    cin>>k>>n;
    odds = (k+1)/2;

    if(n<=odds) cout<<(n*2-1);
    else cout<<(n-odds)*2;

    return 0;
}