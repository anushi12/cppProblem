/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // This function returns the preorder traversal of a given binary tree
    vector<int> preorderTraversal(TreeNode* root) {
        // Create a vector to store the preorder traversal
        vector<int>nodes;
        // Call the recursive function to perform the preorder traversal
        preorder(root,nodes);
        // Return the vector containing the preorder traversal
        return nodes;
    }
    private: 
    // Recursive function to perform the preorder traversal
    void  preorder(TreeNode* root, vector<int>&nodes)
    {
        // If the current node is null, return
        if(!root){return; }

        // Add the value of the current node to the vector
        nodes.push_back(root->val);
        // Recursively traverse the left subtree
        preorder(root->left,nodes);
        // Recursively traverse the right subtree
        preorder(root->right,nodes);
    }
};
