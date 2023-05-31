#include<iostream>
using namespace std;
int main(){

    int x, a=0, d=0;
    char newChar;
    cin>>x;
    for (size_t i = 0; i < x; i++)
    {
        cin>>newChar;
        if(newChar=='A') a++;
        else d++;
    }
    if(a>d){cout<<"Anton";}
    else if(d>a){cout<<"Danik";}
    else{cout<<"Friendship";}
return 0;
}