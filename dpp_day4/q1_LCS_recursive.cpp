// LCS Recursive
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int fun(string a,string b,int i,int j)
{
    if(i<0||j<0){return 0;}
    if(a[i]==b[j])
    {
        return 1+fun(a,b,i-1,j-1);
    }
    else
    {
        return max(fun(a,b,i-1,j),fun(a,b,i,j-1));
    }
}
int main() {
    string a="AGGTAB";
    string b="GXTXAYB";
    int m=a.length();
    int n=b.length();
    
    cout<<fun(a,b,m-1,n-1);
    return 0;
}
