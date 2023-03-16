// MCM RECURSIVE
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int fun(int arr[],int i,int j)
{
    if(i>=j){return 0;}
    int cost=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=fun(arr,i,k)+fun(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        cost=min(cost,temp);
    }
    return cost;
}
int main() {
    int arr[]={40,20,30,10,30};
    int n=5;
    
    int i=1;
    int j=n-1;
    
    cout<<fun(arr,i,j);
    return 0;
}
