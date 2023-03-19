// TOP VIEW OF BINARY TREE
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> m;
        while(!q.empty())
        {
            Node* temp=q.front().first;
            int hd=q.front().second;
            q.pop();
            if(m.count(hd)==0)
            {
                m[hd]=temp->data;
            }
            if(temp->left){q.push({temp->left,hd-1});}
            if(temp->right){q.push({temp->right,hd+1});}
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
// BOTTOM VIEW OF BINARY TREE
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int> m;
        q.push({root,0});
        while(!q.empty())
        {
            Node* temp=q.front().first;
            int hd=q.front().second;
            q.pop();
            m[hd]=temp->data;
            if(temp->left){q.push({temp->left,hd-1});}
            if(temp->right){q.push({temp->right,hd+1});}
        }
        for(auto i:m){ans.push_back(i.second);}
        return ans;
    }
