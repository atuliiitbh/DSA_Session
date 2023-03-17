#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void fun(vector<int> arr,int k,int start)
{
    if(arr.size()==1)
    {
        cout<<endl<<"\nAnswer: "<<arr[0]<<endl;
        return; 
    }
    // soldier to be killed
    start=(start+k)%arr.size();
    cout<<endl<<"Soldier Number "<<arr[start]<<" Killed !";
    arr.erase(arr.begin()+start);
    fun(arr,k,start);
}
int main()
{
    int n,k;
    cout<<"Enter the total number of soldiers: ";
    cin>>n;
    cout<<"Enter the value of k: ";
    cin>>k;
    
    vector<int> arr;
    for(int i=1;i<=n;i++)
        arr.push_back(i);
    
    k--;
    fun(arr,k,0);

    return 0;
}

