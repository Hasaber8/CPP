/*Printing nxm matrix in spiral way*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    int startRow=0, endRow=n-1, columnStart=0, columnEnd=m-1;

    while(startRow<=endRow && columnStart<=columnEnd){
        for(int i=columnStart;i<=columnEnd;i++){
            cout<<a[startRow][i]<<" ";
        }
        startRow++;
        for(int i=startRow;i<=endRow;i++){
            cout<<a[i][columnEnd]<<" ";
        }
        columnEnd--;
        if(startRow<=endRow){
            for(int i=columnEnd;i>=columnStart;i--){
                cout<<a[endRow][i]<<" ";
            }
        }
        endRow--;
        if(columnStart<=columnEnd){
            for(int i=endRow;i>=startRow;i--){
                cout<<a[i][columnStart]<<" ";
            }
        }
        columnStart++;
    }
    return 0;
}