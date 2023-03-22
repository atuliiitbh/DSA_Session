// GFG https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void fun(vector<vector<int>>& adj,vector<bool> &vis,stack<int> &st,int i)
	{
	    for(auto k:adj[i])
	    {
	        if(vis[k]==false)
	        {
	            vis[k]=true;
	            fun(adj,vis,st,k);
	        }
	    }
	    st.push(i);
	}
	void fun2(vector<vector<int>>& tran,vector<bool> &vis,stack<int> &st,int i)
	{
	    for(auto k:tran[i])
	    {
	        if(vis[k]==false)
	        {
	            vis[k]=true;
	            fun2(tran,vis,st,k);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // STEP 1
        vector<bool> vis(V,false);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                fun(adj,vis,st,i);
            }
        }
        
        // STEP 2
        vector<vector<int>> tran(V);
        for(int i=0;i<V;i++)
        {
            vis[i]=false;
            for(auto k:adj[i])
            {
                tran[k].push_back(i);
            }
        }
        
        // STEP 3
        int ans=0;
        while(!st.empty())
        {
            int i=st.top();st.pop();
            if(vis[i]==false)
            {
                vis[i]=true;
                ans++;
                fun2(tran,vis,st,i);
            }
        }
        return ans;
    }
};
