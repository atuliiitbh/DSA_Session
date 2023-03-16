// 0-1 Knapsack Recursive
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int fun(int p[],int w[],int W,int n,int i)
{
    
    if(i==n || W==0){return 0;}
    if(w[i]<=W)
    {
        return max(p[i]+fun(p,w,W-w[i],n,i+1),fun(p,w,W,n,i+1));
    }
    else
    {
        return fun(p,w,W,n,i+1);    
    }
    
}
int main() {
    int p[] = { 60, 100, 120 };
    int w[] = { 10, 20, 30 };
    int W = 50;
    int n = 3;
    
    cout<<fun(p,w,W,n,0);
    return 0;
}
