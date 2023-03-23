#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int p,int c)//p=parent,c=child
{
    adj[p].push_back(c);
    adj[c].push_back(p);
}
// BFS
void bfstraverse(vector<vector<int>> adj,vector<bool> &vis,vector<int> &ans,int i)
{
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        ans.push_back(u);
        for(auto k:adj[u])
        {
            if(vis[k]==false)
            {
                vis[k]=true;
                q.push(k);
            }
        }
    }
}
void bfs(vector<vector<int>> adj)
{
    int v=adj.size();
    vector<bool> vis(v,false);
    vector<int> ans;
    for(int i=1;i<v;i++)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            bfstraverse(adj,vis,ans,i);
        }
    }
    cout<<"BFS: ";
    for(auto a:ans){cout<<a<<" ";}
    cout<<endl;
}
// DFS
void dfstraverse(vector<vector<int>> adj,vector<bool> &vis,vector<int> &ans,int i)
{
    ans.push_back(i);
    for(auto k:adj[i])
    {
        if(vis[k]==false)
        {
            vis[k]=true;
            dfstraverse(adj,vis,ans,k);
        }
    }
    
}
void dfs(vector<vector<int>> adj)
{
    int v=adj.size();
    vector<bool> vis(v,false);
    vector<int> ans;
    for(int i=1;i<v;i++)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            dfstraverse(adj,vis,ans,i);
        }
    }
    cout<<"DFS: ";
    for(auto i:ans){cout<<i<<" ";}
    cout<<endl;
}
// Connected Components
void ccfun(vector<vector<int>> adj,vector<bool> &vis,int s)
{
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto j:adj[u])
        {
            if(vis[j]==false)
            {
                vis[j]=true;
                q.push(j);
            }
        }
    }
}
void cc(vector<vector<int>> adj)
{
    int n=adj.size();
    vector<bool> vis(n,false);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(vis[i]==false)
        {
            ans++;
            vis[i]=true;
            ccfun(adj,vis,i);
        }
    }
    cout<<"Connected Components: "<<ans<<endl;
}

// CHECKING BIPARTITE
void bipartfun(vector<vector<int>> adj,vector<bool> &vis,vector<int> &col,int i,int &ans)
{
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto k:adj[u])
        {
            if(vis[k]==false)
            {
                col[k]=col[i]*-1;
                vis[k]=true;
                q.push(k);
            }
            if(col[k]!=col[i]*-1){ans=false;return;}
        }
    }
}
void bipart(vector<vector<int>> adj)
{
    int v=adj.size();
    vector<bool> vis(v,false);
    vector<int> col(v,0);
    int ans=false;
    
    for(int i=1;i<v;i++)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            col[i]=1;
            bipartfun(adj,vis,col,i,ans);
        }
    }
    if(ans){cout<<"Yes The Graph Is Bipartite.";}
    else{cout<<"No The Graph Is Not Bipartite.";}
}

int main()
{
    int v=9; // no. of vertices 1-based indexing
    vector<vector<int>> adj(v);
    addEdge(adj,1,2);
    addEdge(adj,1,5);
    addEdge(adj,5,4);
    addEdge(adj,5,2);
    addEdge(adj,2,4);
    addEdge(adj,2,3);
    addEdge(adj,4,3);
    
    // for(int i=1;i<v;i++)
    // {
    //     cout<<i<<"->  ";
    //     for(auto j:adj[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    bfs(adj);
    cout<<endl;
    dfs(adj);
    cout<<endl;
    cc(adj);
    cout<<endl;
    bipart(adj);
    
    return 0;
}
