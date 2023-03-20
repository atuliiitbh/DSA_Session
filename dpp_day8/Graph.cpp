#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void dfsRec(vector<vector<int>> adj,vector<bool> &vis,int n,int i)
{
    vis[i]=true;
    cout<<i<<"  ";
    for(auto k:adj[i])
    {
        if(vis[k]==false)
        {
            dfsRec(adj,vis,n,k);
        }
    }
}
int main()
{
    vector<vector<int>> adj(8);
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    
    adj[1].push_back(0);
    adj[1].push_back(2);
    
    adj[5].push_back(6);
    adj[5].push_back(7);
    
    adj[6].push_back(5);
    adj[6].push_back(7);
    
    adj[2].push_back(0);
    
    adj[3].push_back(2);
    adj[3].push_back(4);
    
    adj[4].push_back(3);
    
    adj[2].push_back(1);
    adj[2].push_back(3);
    
    adj[7].push_back(5);
    adj[7].push_back(6);
    /*
    for(int i=0;i<8;i++)
    {
        cout<<i<<" -> ";
        for(int j: adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    */
    // dfsRec
    int n=8;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false)
            dfsRec(adj,vis,n,i);
    }
    return 0;
}
