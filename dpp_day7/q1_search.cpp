// Leetcod: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Method 1: Recursive
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){return NULL;}
        if(root->val==val){return root;}
        if((root->val)>val){return searchBST(root->left,val);}
        if((root->val)<val){return searchBST(root->right,val);}
        return root;
    }
};
