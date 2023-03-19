// https://practice.geeksforgeeks.org/problems/level-order-traversal-line-by-line/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Method 1: Using For Loop And Size Of Queue
vector<vector<int>> levelOrder(Node* node)
{
  //Your code here
  vector<vector<int>> ans;
  queue<Node*> q;
  q.push(node);
  while(!q.empty())
  {
      int s=q.size();
      vector<int> vec;
      for(int k=1;k<=s;k++)
      {
          Node* temp=q.front();q.pop();
          vec.push_back(temp->data);
          if(temp->left){q.push(temp->left);}
          if(temp->right){q.push(temp->right);}
      }
      ans.push_back(vec);
  }
  return ans;
}
// Method 2: Using NULL Pointers
vector<vector<int>> levelOrder(Node* node)
{
  //Your code here
  vector<vector<int>> vec;
  queue<Node*> q;
  q.push(node);
  q.push(NULL);
  vector<int> ans;
  while(q.size()>1)
  {
      Node* temp=q.front();q.pop();
      if(temp==NULL)
      {
          q.push(NULL);
          vec.push_back(ans);
          ans.clear();
      }
      else
      {
          if(temp->left){q.push(temp->left);}
          if(temp->right){q.push(temp->right);}
          ans.push_back(temp->data);
      }
  }
  vec.push_back(ans);
  return vec;
}
