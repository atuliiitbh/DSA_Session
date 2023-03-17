// METHOD 1 USING FOR LOOP (SIMILAR TO MCM)
// GFG ques: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
  public:
    int fun(int arr[],int n,int i,int (&dp)[1001][1001])
    {
        if(n==0 || n<i){return 0;}
        if(dp[n][i]!=-1){return dp[n][i];}
        int cost=INT_MIN;
        for(int k=i;k<=n;k++)
        {
            int temp=arr[k-1]+max(fun(arr,n-k,k+1,dp),fun(arr,n-k,k,dp));
            cost=max(cost,temp);
        }
        return dp[n][i]=cost;
        
    }
    int cutRod(int price[], int n) {
        //code here
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return fun(price,n,1,dp);
    }
};

// METHOD 2 WITHOUT USING FOR LOOP (SIMILAR TO LCS) 
class Solution{
  public:
    int fun(int arr[],int n,int i,int (&dp)[1001][1001])
    {
        if(n==0 || i>n){return 0;}
        if(dp[i][n]!=-1){return dp[i][n];}
        return dp[i][n]=max(arr[i-1]+fun(arr,n-i,1,dp),fun(arr,n,i+1,dp));
    }
    int cutRod(int price[], int n) {
        //code here
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return fun(price,n,1,dp);
    }
};
