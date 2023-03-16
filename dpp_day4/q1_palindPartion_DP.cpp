#include<bits/stdc++.h>
using namespace std;
bool isPalin(string s,int i,int j)
{
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int fun(string s,int i,int j,vector<vector<int>>&dp)
{
    if(i>j || isPalin(s,i,j)==true){return 0;}
    
    if(dp[i][j]!=-1){return dp[i][j];}
    
    int cost=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=1+fun(s,i,k,dp)+fun(s,k+1,j,dp);
        cost=min(temp,cost);
    }
    return dp[i][j]=cost;
}
int main()
{
    string str = "ababbbabbababa";
    int n=str.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<"No. Of Partitioning : "<<fun(str,0,n-1,dp);
    return 0;    
}

