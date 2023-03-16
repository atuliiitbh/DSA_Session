// Recursive Code Same As MCM !!

// Method 1 Using 2 fn parameters.
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
// Method 2 using substr and only one parameter:
/*
#include<bits/stdc++.h>
using namespace std;
bool isPalin(string s)
{
    string a=s;
    reverse(s.begin(),s.end());
    return s==a;
}
int fun(string s)
{
    if(s.length()==0 || isPalin(s)==true){return 0;}
    
    int cost=INT_MAX;
    int n=s.length();
    for(int i=1;i<s.length();i++)
    {
        int temp=1+fun(s.substr(0,i))+fun(s.substr(i,n-i));
        cost=min(temp,cost);
    }
    return cost;
}
int main()
{
    string str = "ababbbabbb";
    int n=str.length();
    cout<<fun(str);
    return 0;    
}


*/
