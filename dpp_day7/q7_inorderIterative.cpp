// GFG
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        Node* temp=root;
        stack<Node*> s;
        while(!s.empty() || temp!=NULL)
        {
            while(temp)
            {
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();s.pop();
            ans.push_back(temp->data);
            temp=temp->right;
        }
        return ans;
    }
};
