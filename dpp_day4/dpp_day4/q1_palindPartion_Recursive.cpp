// Recursive Code Same As MCM !!
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
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
int fun(string s,int i,int j)
{
    if(i>=j || isPalindrome(s,i,j))
        return 0;
    
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=fun(s,i,k)+fun(s,k+1,j)+1;
        ans=min(temp,ans);
    }
    return ans;
}
int main() {
    string s="geek";
    int n=s.size();
    
    int i=0;
    int j=n-1;
    
    cout<<fun(s,i,j);
    return 0;
}
