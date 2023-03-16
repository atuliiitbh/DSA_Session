#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int fun(int arr[],int n,int i)
{
    if(i==n+1 || n==0)
        return 0;
    return max(arr[i-1]+fun(arr,n-i,1),fun(arr,n,i+1));
}


int main()
{
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n=8;
    int i=1;
    cout<<fun(arr,n,i);
    return 0;
}
