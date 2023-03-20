// GFG: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Method 1: Iterative Insert
// Function to insert a node in a BST.
Node* insert(Node* root, int key) {
    Node* prev=root;
    bool flag=0;
    while(root)
    {
        if(root->data==key){return root;}
        if(root->data<key)
        {
            prev=root;
            root=root->right;
            flag=1;
        }
        else if(root->data>key)
        {
            prev=root;
            root=root->left;
            flag=0;
        }
    }
    Node* temp= new Node(key);
    if(flag==0){prev->left=temp;}
    if(flag==1){prev->right=temp;}
    return temp;
}


// Method 2: Recursive Insert
// Function to insert a node in a BST.
Node* insert(Node* root, int key) {
    // Your code here
    if(!root){Node* t=new Node(key);return t;}
    if(root->data==key){return root;}
    if(root->data<key){root->right=insert(root->right,key);}
    if(root->data>key){root->left=insert(root->left,key);}
    return root;
}
