#include <bits/stdc++.h>
using namespace std;


void solve1(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) 
        cin>>a[i];
    
    int answer[n];

    for(int i =0; i<n; i++){
        int mx = 0;
        for(int j = 0; j < n; j++){
            if(i==j) continue;

            mx = max(mx, a[j]);
        }
        answer[i] = a[i] - mx;
        // cout<<a[i]-mx<<" ";
    }

    for(int i =0; i < n; i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
}

void solve2(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) 
        cin>>a[i];

    int first_max = 0, second_max = 0;
    for(int i = 0; i<n; i++){
        if(a[i] >= first_max) {
            second_max = first_max;
            first_max = a[i];
        }
        else if(a[i] > second_max){
            second_max = a[i];
        }
    }

    for(int i = 0; i<n; i++){
        if(a[i]==first_max) cout<<a[i] - second_max << " ";
        else cout<< a[i] - first_max<< " ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    cin >> t; //1
    while(t--) {
        // solve1();

        solve2();
    }

    return 0;
}
