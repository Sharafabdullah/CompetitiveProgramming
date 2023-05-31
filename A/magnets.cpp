#include<iostream>
using namespace std;

int main(){

    string cur, prev="";
    int n, g=0; cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        cin>>cur;
        if(cur==prev) continue;
        else {prev = cur; g++;}
    }
    
    cout<<g;
    return 0;
}