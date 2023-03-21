// BFS Undirected and Disconnected Graph.
// Function to return Breadth First Traversal of given graph.
    void fun(int i,vector<bool> &vis,vector<int> &ans,vector<int> adj[])
    {
        queue<int> q;
        q.push(i);
        vis[i]=true;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto i:adj[temp])
            {
                if(vis[i]==false){
                    vis[i]=true;
                    q.push(i);
                }   
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                fun(i,vis,ans,adj);
            }
        }
        return ans;
        
    }
