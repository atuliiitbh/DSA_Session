// GFG: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL){return NULL;}
        if(root->data==n1 || root->data==n2){return root;}
        Node* l=lca(root->left,n1,n2);
        Node* r=lca(root->right,n1,n2);
        if(l && r){return root;}
        if(l && !r){return l;}
        if(!l && r){return r;}
    }
};
