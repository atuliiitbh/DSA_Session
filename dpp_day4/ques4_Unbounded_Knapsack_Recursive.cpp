#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Recursive Fn
int fun(int val[],int wt[],int i,int N,int W)
{
        if(i==N || W==0)
            return 0;
        if(wt[i]<=W)
        {
            return max(val[i]+fun(val,wt,i,N,W-wt[i]),fun(val,wt,i+1,N,W));
        }
        else
        {
            return fun(val,wt,i+1,N,W);
        }
}
int main() {
    int W = 100;
    int val[] = { 10, 30, 20 };
    int wt[] = { 5, 10, 15 };
    int i=0;
    int N=3;
    cout<<fun(val,wt,i,N,W);
    return 0;
}
