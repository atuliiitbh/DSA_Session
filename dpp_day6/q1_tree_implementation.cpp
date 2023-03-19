
// Recursive Implementation of tree traversals::

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
void preorder(Node* root)
{
    if(root)
    {
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
}
int main()
{
    Node* root=new  Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout<<"Printing PRERDER "<<endl;
    preorder(root);
    cout<<endl<<"Printing INORDER "<<endl;
    inorder(root);
    cout<<endl<<"Printing POSTORDER "<<endl;
    postorder(root);
    
    return 0;
}
