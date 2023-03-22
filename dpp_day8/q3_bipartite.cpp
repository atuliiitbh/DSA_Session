// Leetcode https://leetcode.com/problems/is-graph-bipartite/submissions/
class Solution {
public:
    void fun(vector<vector<int>>& graph,vector<bool> &vis,vector<int> &col,int s,bool &ans)
    {
        queue<int> q;
        q.push(s);
        vis[s]=true;
        col[s]=1;
        
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto k:graph[temp])
            {
                if(vis[k]==true)
                {
                    if(col[k]!=col[temp]*(-1)){ans=false;}
                }
                else
                {
                    vis[k]=true;
                    q.push(k);
                    col[k]=col[temp]*(-1);
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<int> col(n,0);
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                fun(graph,vis,col,i,ans);
            }
            if(ans==false){return false;}
        }
        return true;    
    }
};

