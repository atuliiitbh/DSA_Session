#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// to print the matrix
void printm(int n, vector<vector<int>> arr)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Enter the dimension of the square matrix: ";
    int n;
    cin>>n;
    cout<<endl<<"Enter The Matrix: ";
    int i,j,k,x,y;
    // Taking Input
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    // Method 1 brute force - simply copy the matrix to another 
    cout<<endl;
    
    vector<vector<int>> rotated(n,vector<int>(n,0));
    for(j=0;j<n;j++)
    {
        x=n-1-j;y=0;
        for(i=0;i<n;i++)
        {
            rotated[x][y]=arr[i][j];
            y++;
        }
    }
    
    printm(n,rotated);
    
    cout<<endl<<endl;
    // Method 2- If we take transpose of input matrix 
    // and then reverse all the columns - we get the rotated matrix!
    
    // Calculating Transpose 
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
   
    for(j=0;j<n;j++)
    {
        k=n-1;
        i=0;
        while(i<k)
        {
            swap(arr[i][j],arr[k][j]);
            i++;k--;
        }
    }
    
    // Matrix After Rotation:
    
    printm(n,arr);
    return 0;
}
//vector<vector<int>> vec( n , vector<int> (m, 0)); 
