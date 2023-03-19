//https://practice.geeksforgeeks.org/problems/level-order-traversal/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      vector<int> ans;
      queue<Node*> q;
      q.push(node);
      while(!q.empty())
      {
          Node* temp=q.front();q.pop();
          ans.push_back(temp->data);
          if(temp->left){q.push(temp->left);}
          if(temp->right){q.push(temp->right);}
      }
      return ans;
    }
};
