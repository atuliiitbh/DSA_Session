// GFG: https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Slight Modifications in Diameter of binary tree fn.
// Just like we calculated height, we are calculating max path sum in either subtree.


class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int fun(Node* root,int &ans)
    {
        if(!root){return 0;}
        int lcost=fun(root->left,ans);
        int rcost=fun(root->right,ans);
      // MAIN CODES :: FOLLOWING 2 LINES
        int heightsum=max(max(lcost,rcost)+root->data,root->data); // Either lcost+root or rcost+root or just root -- (due to the presence of -ve values)
        int sum=max(heightsum, root->data+lcost+rcost);
        ans=max(ans,sum);
        return heightsum;
    }
    int findMaxSum(Node* root)
    {
        int ans=INT_MIN;
        fun(root,ans);
        return ans;
    }
};
