// GFG  https://practice.geeksforgeeks.org/problems/floor-in-bst/1
// FLOOR IN BST 
int floor(Node* root, int x) {
    // Code here
    int ans=-1;
    while(root)
    {
        if(root->data==x){return x;} 
        if(root->data<x){
            ans=root->data;
            root=root->right;
        }
        else if(root->data>x){root=root->left;}
    }
    return ans;
}


// GFG  https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    int ans=-1;
    while(root)
    {
        if(root->data==input){return input;}
        if(root->data>input)
        {
            ans=root->data;
            root=root->left;
        }
        else if(root->data<input)
        {
            root=root->right;   
        }
    }
    return ans;
}
