#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v;
    int n, num; cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    transform(v.begin(), v.end(), v.begin(), [](int x){cout<<x<<" "; return x;});

    return 0;
}