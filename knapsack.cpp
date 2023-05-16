#include <iostream>
#include <stdlib.h>
#include "func_take.h"
using namespace std;



int main(){ 
    long n,K,i,j; 
    cin >> n >> K;

    long items[n];
    for(j=0;j<n;j++)
            items[j]=0;

    long c[n][K+1];
    for(i=0;i<n;i++)
        for(j=0;j<=K;j++)
            c[i][j]=0;

    long data[n][2];
    for(i=0;i<n;i++)
        cin >> data[i][0] >> data[i][1];

    for(j=0;j<=K;j++){
        if(data[0][1]<=j)c[0][j]=data[0][0];
    }
    
    for(i=1;i<n;i++){
        for(j=1;j<=K;j++){
            if(data[i][1]<=j){
                if(j!=0){
                   c[i][j]=max(c[i-1][j],(data[i][0]+c[i-1][j-data[i][1]]));
                }
                if(j==0){
                   c[i][j]=max(c[i-1][j],data[i][0]);
                }
            }
            else{c[i][j]=c[i-1][j];}
        }
    }
    
    cout << "\n" << c[n-1][K] << "\n\n";
    
    long *c_p[n];
    long *data_p[n];
    for(i=1;i<n;i++){
        c_p[i]=c[i];
        data_p[i]=data[i];
    }
    take(n,K,items,n-1,K,c_p,data_p,0);
    long ans[n];
    for(i=0;i<n;i++)ans[i]=0;
    j=0;
    while(items[j]!=0){ans[items[j]-1]=1;j++;}
    for(j=0;j<n;j++)cout << ans[j] << " ";

    return 0;
}