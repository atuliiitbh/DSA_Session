#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cout<<"Enter the string: ";
    cin>>a;
    
    // Method 1 
    cout<<endl<<"Method 1"<<endl;
    string b=a;
    reverse(a.begin(),a.end());
    if(a==b)
        cout<<"Yes It's A Palindrome!";
    else
        cout<<"No....It's Not A Palindrome!!";
    
    // Method 2 
    cout<<endl<<endl<<"Method 2"<<endl;
    int i=0,j=a.length()-1;
    int flag=1;
    while(i<j)
    {
        if(a[i]!=a[j])
        {
            flag=0;
            break;
        }
        i++;j--;
    }
    if(flag==1)
        cout<<"Yes It's A Palindrome!";
    else
        cout<<"No....It's Not A Palindrome!!";
    

    return 0;
}
