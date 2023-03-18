// GFG QUESTION::: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int fun(int arr[],int prev,int curr,int n,vector<vector<int>> &dp)
    {
        if(curr==n){return 0;}
        if(dp[prev+1][curr]!=-1){return dp[prev+1][curr];}
        if(prev==-1)
        {
            return dp[prev+1][curr]=max(fun(arr,prev,curr+1,n,dp),1+fun(arr,curr,curr+1,n,dp));
        }
        else
        {
            if(arr[curr]>arr[prev])
            {
                return dp[prev+1][curr]=max(fun(arr,prev,curr+1,n,dp),1+fun(arr,curr,curr+1,n,dp));
            }
            else
            {
                return dp[prev+1][curr]=fun(arr,prev,curr+1,n,dp);
            }
        }
        
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
       return fun(a,-1,0,n,dp);
    }
};
