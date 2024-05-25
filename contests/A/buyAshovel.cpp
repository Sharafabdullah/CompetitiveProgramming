#include<iostream>
#include<limits>
using namespace std;

int main(){

    int p, r; cin>>p>>r;
    int k=1;
    for(; k< numeric_limits<int>::max(); k++){
        if(((k*p)%10==r) || ((k*p)%10 ==0)){
            cout<<k;

            return 0;
        }
    }

    return 0;
}