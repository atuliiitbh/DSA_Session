// LEFT VIEW 
//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(root==NULL){return ans;}
   queue<Node*> q;
   q.push(root);
   while(!q.empty())
   {
       int n=q.size();
       for(int k=0;k<n;k++)
       {
           Node* temp=q.front();q.pop();
           if(k==0){ans.push_back(temp->data);}
           if(temp->left){q.push(temp->left);}
           if(temp->right){q.push(temp->right);}
       }
   }
   return ans;
}
// RIGHT VIEW
//https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
//Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       queue<Node*> q;
       q.push(root);
       while(!q.empty())
       {
           int n=q.size();
           for(int i=0;i<n;i++)
           {
               Node* temp=q.front();q.pop();
               if(i==n-1){ans.push_back(temp->data);}
               if(temp->left){q.push(temp->left);}
               if(temp->right){q.push(temp->right);}
           }
       }
       return ans;
    }
