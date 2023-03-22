// DFS UNDIRECTED DISCONNECTED GRAPH
// GFG https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Function to return a list containing the DFS traversal of the graph.
    void fun(int i,vector<int> adj[],vector<bool> &vis,vector<int> &ans)
    {
         vis[i]=true;
         ans.push_back(i);
         for(int j: adj[i])
         {
             if(vis[j]==false)
             {
                 fun(j,adj,vis,ans);
             }
         }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                fun(i,adj,vis,ans);
            }
        }
        return ans;
    }
