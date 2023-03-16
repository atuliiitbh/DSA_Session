#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool fun(string s,string t)
{
        unordered_set<char> ms;
        unordered_map<char,char> mm;
        char temp;
        for(int i=0;i<s.length();i++)
        {
            temp=s[i];
            if(mm.count(temp)==0)
            {
                if(ms.count(t[i])==1)
                    return false;
                mm[temp]=t[i];
                ms.insert(t[i]);
            }
            else
            {
                if(mm[temp]!=t[i])
                {
                    return false;
                }
            }
        }
        return true;
}
int main()
{
    string s,t;
    cout<<"Enter The Strings: ";
    cin>>s>>t;
    bool ans=fun(s,t);
    if(ans)
        cout<<s<<" and "<<t<<" are ISOMORPHIC !"<<endl;
    else
        cout<<"No They Are Not!"<<endl;
    return 0;
}
