//recursive

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
    //Inorder traversal of a binary tree
    //The function takes in the root node of the binary tree
    //It returns a vector containing the inorder traversal of the tree
    vector<int> inorderTraversal(TreeNode* root) {
      //initialize an empty vector to store the inorder traversal
      vector<int>nodes;
      //recursive helper function that traverses the tree and adds the nodes to the vector
      inorder(root,nodes);
      //return the vector with the inorder traversal
      return nodes;  
    }

    private:
    //Helper function that traverses the tree and adds the nodes to the vector
    //Takes in the current node and the vector as parameters
    void inorder(TreeNode* root, vector<int>&nodes){
        //base case: if the current node is null, return
        if(!root){return;}
        //recursive call to left subtree
        inorder(root->left,nodes);
        //add the current node's value to the vector
        nodes.push_back(root->val);
        //recursive call to the right subtree
        inorder(root->right,nodes); 
    }
};






// iterative way

class Solution {
public:
    // Inorder traversal of a binary tree using stack
    vector<int> inorderTraversal(TreeNode* root) {
        // stack to store nodes
        stack<TreeNode*>st;
        // vector to store inorder traversal
        vector<int>inorder;
        // pointer to current node
        TreeNode* node= root;
        // loop until all nodes are traversed
        while(true){
            // if current node is not null, push it to stack and move to its left child
            if(node!=NULL){
                st.push(node);
                node= node->left;
            }
            // if current node is null and stack is not empty
            // pop the top node from stack, add its value to inorder vector, and move to its right child
            else{
                if(st.empty()== true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node= node->right;
            }
        }
        // return the inorder traversal
        return inorder;
    }
};
