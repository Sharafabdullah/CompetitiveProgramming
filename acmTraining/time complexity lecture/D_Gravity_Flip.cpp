#include <bits/stdc++.h>
#include<algorithm>

using namespace std;


void solve1(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) 
        cin>>a[i];
    
    int sorted_array[n];
    bool taken_index[n] = {0};

    for(int i = 0; i<n; i++){
        int min_element_index = -1;

        for(int j = 0; j < n; j++){
            if(taken_index[j]) continue;

            if((min_element_index==-1) || (a[j] < a[min_element_index])) min_element_index = j;
        }

        sorted_array[i] = a[min_element_index];
        taken_index[min_element_index] = 1;
    }

    for(int i = 0; i<n; i++){
        cout<<sorted_array[i]<<" ";
    }
}

void solve2(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) 
        cin>>a[i];

    sort(a, a+n);
    for(int i = 0; i<n; i++) {
        cout<<a[i]<<" ";
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) {
        solve1();

        // solve2();
    }

    return 0;
}
