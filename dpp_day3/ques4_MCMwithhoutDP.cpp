#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(int arr[],int i,int j)
{
    if(i>=j){return 0;}
    int cost=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        cost=min(cost,temp);
    }
    return cost;
    
}
int main() {
    int arr[]={40,20,30,10,30}; // INPUT ARRAY
    int n=5; // SIZE
    
    int i=1;
    int j=n-1;
    cout<<"ANSWER : "<<solve(arr,i,j)<<endl;
    return 0;
}
