#include<iostream>
using namespace std;

int main(){

    int up=0, lo=0;
    string s, fin=""; cin>>s;
    for (size_t i = 0; i < s.length(); i++)
    {
        if(s[i]<='Z') up++;
    }
    if(up>(s.length()-up)) for (size_t i = 0; i < s.length(); i++)
    {
        // fin+=toupper(s[i]);
        if (s[i]>'Z')
        {
            s[i]-=32;
        }
        
    }
    else for (size_t i = 0; i < s.length(); i++)
    {
        // fin+=tolower(s[i]);
        if(s[i]<='Z') s[i]+=32;
    }
    cout<<s;
    


    return 0;
}