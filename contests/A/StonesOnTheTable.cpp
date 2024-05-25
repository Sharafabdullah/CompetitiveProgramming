
#include<iostream>
using namespace std;

int main(){

    int n, count= 0;
    cin>>n;
    char* cList = new char(n);

    char prev, curr;

    for (int i =1; i<=n; i++){
        prev= curr;
        cin>>curr;
        if(curr==prev){
            count++;
        }
    }
    cout<<count;

    return 0;
}
