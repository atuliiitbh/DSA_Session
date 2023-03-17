// STORE PREV AS PREV+1 , INSTEAD OF STORING -1 IN DP SOLUTION..
#include<bits/stdc++.h>
using namespace std;
int fun(int arr[],int prev,int i,int n)
{
    if(i==n)
        return 0;
    if(arr[i]>prev)
    {
        return max(1+fun(arr,arr[i],i+1,n),fun(arr,prev,i+1,n));
    }
    else
    {
        return fun(arr,prev,i+1,n);
    }
}
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n=sizeof(arr)/sizeof(arr[0]);
    int prev=INT_MIN;
    int index=0;
    cout<<"Length Of Longest Increasing Subsequence Is: "<<fun(arr,prev,index,n);
    return 0;
}
