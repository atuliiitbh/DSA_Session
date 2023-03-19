// Height
int height(struct Node* node){
        if(node==NULL){return 0;}
        return 1+max(height(node->left),height(node->right));
    }

// Size
int getSize(Node* node)
{
   if(node==NULL){return 0;}
   return 1+getSize(node->left)+getSize(node->right);
}

// Diameter
    // Function to return the diameter of a Binary Tree
    int height(Node* root,int &ans)
    {
        if(root==NULL){return 0;}
        int lh=height(root->left,ans);
        int rh=height(root->right,ans);
        int temp=1+lh+rh;
        ans=max(temp,ans);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
        int ans=0;
        int x=height(root,ans);
        return ans;
    }
