// GFG https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//Function to return a list containing the level order traversal in spiral form.
// Using vector reverse , not using another stack
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root==NULL){return ans;}
    queue<Node*>q;
    q.push(root);
    bool flag=false;
    int size=0;
    while(!q.empty())
    {
        int n=q.size();
        if(flag)
        {
            for(int i=0;i<n;i++)
            {
                Node* temp=q.front();q.pop();
                ans.push_back(temp->data);
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            flag=false;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                Node* temp=q.front();q.pop();
                ans.push_back(temp->data);
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
            reverse(ans.begin()+size,ans.end());
            flag=true;
        }
        size=size+n;
    }
    return ans;
}

