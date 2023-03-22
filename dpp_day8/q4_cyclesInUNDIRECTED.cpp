// GFG https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Function to detect cycle in an undirected graph.
    
    // We are simply doing bfs traversal , keeping a list of visited nodes
    // If a node is visited but it is not the parent , then it contains a cycle.
    
    bool fun(vector<int> adj[],vector<bool> &vis,bool &ans, int s,int parent)
    {
        vis[s]=true;
        for(auto k: adj[s])
        {
            if(vis[k]==false){fun(adj,vis,ans,k,s);}
            else{
                if(k!=parent){ans=true;}
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        bool ans=false;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                fun(adj,vis,ans,i,-1);
            }
            if(ans==true){return true;}
        }
        return false;
    }
