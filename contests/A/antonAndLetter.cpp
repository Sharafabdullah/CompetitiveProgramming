#include<iostream>
using namespace std;
 int mod(int a, int n){
    while(a>=n) a-=n;
    while(a<0) a+=n;
    return a;
 }
 int nabsmod(int a, int n){
    while(a>=n) a-=n;
    while(a<=-n) a+=n;
    return a;
 }
int main(){

    cout<< (-6%4 + (4))%4<<endl;
    cout<< mod(-6,4)<<endl;;
    cout<< nabsmod(-6,4);
    
    return 0;
}