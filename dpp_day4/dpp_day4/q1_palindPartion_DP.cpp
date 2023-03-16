// Cost Is Same As Recursive ! Why??
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int aa=0;
bool isPalindrome(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;j--;
    }
    return true;
}
int fun(string s,int i,int j,vector<vector<int>> dp)
{
    cout<<aa<<"  ";
    aa++;
    if(i>=j || isPalindrome(s,i,j))
    {
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=fun(s,i,k,dp)+fun(s,k+1,j,dp)+1;
        ans=min(temp,ans);
    }
    dp[i][j]=ans;
    return ans;
}
int main() {
    string s="geeekss";
    int n=s.size();
    
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    int i=0;
    int j=n-1;
    
    cout<<fun(s,i,j,dp);
    return 0;
}
