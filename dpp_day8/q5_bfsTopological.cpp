//GFG https://practice.geeksforgeeks.org/problems/topological-sort/1
//Function to return list containing vertices in Topological order. 
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
