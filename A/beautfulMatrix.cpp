#include<iostream>
#include<algorithm>
using namespace std;

void scol(int m[][5], int j, int n){
    for (size_t i = 0; i < 5; i++)
    {
        swap(m[i][j], m[i][n]);
    }
    
}
void srow(int m[][5], int r, int rA){
    for (size_t i = 0; i < 5; i++)
    {
        swap(m[r][i], m[rA][i]);
    }
}
int main(){

    int m[5][5]={0};
    bool get;
    int i_1=0, j_1=0;

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            cin>>m[i][j];
            if(m[i][j]){
                i_1 = i;
                j_1 = j;
                // cout<<"the value of i"<<i<<"    the vlue of j: "<<j<<endl;
            }
            // cout<<"I have intered at "<<i<<"   "<<j<<"The value: "<<m[i][j];
        }
        
    }
    /* for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            cout<<m[i][j];
        }
        
    } */
    int ctr = 0;
    while (j_1!=2)
    {
        if(j_1<2){
            scol(m, j_1,j_1+1);
            j_1++;    
        } else if(j_1>2){
            scol(m, j_1,j_1-1);
            j_1--;
        }
        ctr++;
    }
    while(i_1!=2){
        if(i_1<2){
            srow(m, i_1, i_1+1);
            i_1++;
        }
        else if(i_1>2){
            srow(m, i_1, i_1-1);
            i_1--;
        }
         ctr++;
    }

    cout<<ctr;
    
    

    return 0;
}