// Brute force

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
    int maxDiff;
    void findMax(TreeNode* root, TreeNode* child){
        if(!root || !child) return;
        maxDiff = max(maxDiff, abs(root->val - child->val));
        findMax(root, child->left);
        findMax(root, child->right);
    }
    void callAllNode(TreeNode* root){
        if(!root) return;
        findMax(root, root->left);
        findMax(root, root->right);

        callAllNode(root->left);
        callAllNode(root->right);

    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = -1;
        callAllNode(root);
        return maxDiff;
    }
};




// optimal approach

class Solution {
public:
    int findMax(TreeNode* root, int maxi, int mini){
        if(root == NULL) return abs(maxi-mini);
         maxi = max(maxi,root->val);
         mini = min(mini, root->val);

      int left =   findMax(root->left, maxi,mini);
      int right =  findMax(root->right, maxi, mini);
    return max(left,right);
    }
   
    int maxAncestorDiff(TreeNode* root) {
       return findMax(root, root->val, root->val);
    }
