// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1 
// Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,vector<int>> m;
        while(!q.empty())
        {
            Node* temp=q.front().first;
            int hd=q.front().second;
            q.pop();
            m[hd].push_back(temp->data);
            if(temp->left){q.push({temp->left,hd-1});}
            if(temp->right){q.push({temp->right,hd+1});}
        }
        for(auto i:m)
        {
            for(int k:i.second)
            {
                ans.push_back(k);
            }
        }
        return ans;
    }
