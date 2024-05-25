//this is the first problem

#include<iostream>
using namespace std;
int main(){
    int x, y,ctr=0;
    cin>>x>>y;
    while(x<=y){
        x*=3;
        y*=2;
        ctr++;
    }
    cout<<ctr;
return 0;
}