// LCS DP Memoized 

#include<bits/stdc++.h>
using namespace std;
int fun(string a,string b,int m,int n,int (&dp)[100][100])
{
    if(m<0 || n<0){return 0;}
    if(dp[m][n]!=-1){return dp[m][n];}
    if(a[m]==b[n])
    {
        return dp[m][n]=1+fun(a,b,m-1,n-1,dp);
    }
    else
    {
        return dp[m][n]=max(fun(a,b,m,n-1,dp),fun(a,b,m-1,n,dp));
    }
}
int main()
{
    string a="AGGTAB";
    string b="GXTXAYB";
    int m=a.length();
    int n=b.length();
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<"Longest Common Subsequence Is: "<<fun(a,b,m-1,n-1,dp);
    return 0;
}
