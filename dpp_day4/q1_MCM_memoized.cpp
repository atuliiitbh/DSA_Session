//MCM DP MEMOIZED CODE !!
// Passing 2d array int (&dp)[100][100] as reference
#include<bits/stdc++.h>
using namespace std;
int fun(int i,int j,int arr[],int (&dp)[100][100])
{
    if(i==j){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int cost=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=fun(i,k,arr,dp)+fun(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
        cost=min(temp,cost);
    }
    dp[i][j]=cost;
    return cost;
}
int main()
{
    int arr[]={40,20,30,10,30,50,60,80,90,100};
    int n=10;
    
    int i=1;
    int j=n-1;
    
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    
    int ans=fun(i,j,arr,dp);
    cout<<"Minm Cost Of Multiplication: "<<ans;
    return 0;
}
