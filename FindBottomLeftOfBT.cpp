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
    void Preorder(TreeNode* root, int level,vector<int>&ans){
        if(!root) return;

        if(ans.size() == level) ans.push_back(root->val);
        Preorder(root->left, level+1, ans);
        Preorder(root->right, level+1, ans);

    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int>ans;
        Preorder(root, 0, ans);
        int bottomVal = ans[ans.size()-1];
        return bottomVal;
    }
};
