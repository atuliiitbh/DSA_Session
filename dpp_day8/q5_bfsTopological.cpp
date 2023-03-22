//GFG https://practice.geeksforgeeks.org/problems/topological-sort/1
//Function to return list containing vertices in Topological order. 

.
// METHOD 01 : TOPOLOGICAL SORT USING BFS
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    // counting the indegrees;
	    vector<int> ind(V,0);
	    for(int i=0;i<V;i++){
	        for(int k:adj[i]){
	            ind[k]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){if(ind[i]==0){q.push(i);}}
	    while(!q.empty())
	    {
	        int temp=q.front();q.pop();
	        ans.push_back(temp);
	        for(auto i:adj[temp])
	        {
	            ind[i]--;
	            if(ind[i]==0){q.push(i);}
	        }
	    }
	    return ans;
	}

// METHOD 02 : TOPOLOGICAL SORT USING DFS

	void fun(vector<int> adj[],vector<bool> &vis,stack<int> &s,int i)
	{
	    vis[i]=true;
	    for(auto j:adj[i])
	    {
	        if(vis[j]==false)
	        {
	            fun(adj,vis,s,j);
	        }
	    }
	    s.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V,false);
	    stack<int> s;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==false)
	        {
	            fun(adj,vis,s,i);
	        }
	    }
	    vector<int> ans;
	    while(!s.empty())
	    {
	        ans.push_back(s.top());s.pop();
	    }
	    return ans;
	}
