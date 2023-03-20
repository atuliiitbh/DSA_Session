// GFG: https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root==NULL){return NULL;}
    if(root->data<X)
    {
        root->right=deleteNode(root->right,X);
    }
    else if(root->data>X)
    {
        root->left=deleteNode(root->left,X);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left==NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* temp=root->right;
            while(temp->left)
            {
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
            return root;
        }
    }
    return root;
}
