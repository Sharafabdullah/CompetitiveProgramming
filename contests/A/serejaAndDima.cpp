#include<set>
#include<vector>
#include<deque>
#include<list>
#include<algorithm>
#include <utility>
#include<iterator>

#include<sstream>
#include<iostream>
using namespace std;

int main(){

    deque<int> q;
    int s=0, d=0, n, m; cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        cin>>m;
        q.push_back(m);
    }
    for (size_t i = 0; i < n; i++)
    {
        if(i&1){
            if(q.front()>q.back()) {d+=q.front(); q.pop_front();}
            else{d+=q.back(); q.pop_back();}
        }
        else{
            if(q.front()>q.back()) {s+=q.front(); q.pop_front();}
            else{s+=q.back(); q.pop_back();}
        }
    }
    cout<<s<<" "<<d;
    
    

    return 0;
}