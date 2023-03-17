// WRONG ANSWER 
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n=5; // size of the arrays;
    // int arr1[]={1, 12, 15, 26, 38};
    // int arr2[]={2, 13, 17, 30, 45}; // coreect answer=16 , mine=15
    int arr1[] = { 1, 4, 5, 6, 10 };
    int arr2[] = { 2, 3, 4, 5, 7 }; // corrrect answer 4.5 , mine=4
    
    int mn=min(arr1[0],arr2[0]);
    int mx=max(arr1[n-1],arr2[n-1]);
    
    int pos=n;
    int mid,place;
    while(mn<mx)
    {
        mid=mn+(mx-mn)/2;
        place=0;
        // 1st array
        place=place+upper_bound(arr1,arr1+n,mid)-arr1;
        // 2nd array
        place=place+upper_bound(arr2,arr2+n,mid)-arr2;
        
        if(place<pos){mn=mid+1;}
        else{mx=mid;}
        
    }
    cout<<"Answer: "<<mn<<endl;
}
