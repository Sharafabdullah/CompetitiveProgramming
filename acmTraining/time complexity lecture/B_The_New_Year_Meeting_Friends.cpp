#include <bits/stdc++.h>
using namespace std;


void solve1(){
    int a,b,c; cin>>a>>b>>c;
    int answer = 1000000000;
    for(int i = 1; i <= 100; i++){
        int dst1 = abs(a - i);
        int dst2 = abs(b-i);
        int dst3 = abs(c-i);   
        answer  = min(answer, dst1 + dst2 + dst3);
    }
    cout<<answer<<endl;
}

void solve2(){
    int a,b,c; cin>>a>>b>>c;
    
    int dst1 = abs(a-b) + abs(a-c);
    int dst2 = abs(b-a) + abs(b-c);
    int dst3 = abs(c-a) + abs(c-b);

    cout<<min(dst1, min(dst2,dst3))<<endl;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    solve1();

    // solve2();

    return 0;
}
