// 0-1 Knapsack DP Memoized Version
#include<bits/stdc++.h>
using namespace std;
int fun(int p[],int w[],int W,int n,int (&dp)[100][100])
{
    if(n==0 || W==0){return 0;}
    if(dp[n][W]!=-1){return dp[n][W];}
    if(w[n]<=W)
    {
        return dp[n][W]=max(p[n]+fun(p,w,W-w[n],n-1,dp),fun(p,w,W,n-1,dp));
    }
    else
    {
        return dp[n][W]=fun(p,w,W,n-1,dp);
    }
    
    
}
int main()
{
    int p[] = { 60, 100, 120,10,20,40 };
    int w[] = { 10, 20, 30,10,20,30 };
    int W = 50;
    int n = 6;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<"Answer: "<<fun(p,w,W,n-1,dp);
    return 0;
}
