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
    int ans =0;
    void help(TreeNode* root, unordered_map<int, int>&mp){
        if(!root) return;
        mp[root->val]++;

        if(root->left == NULL && root->right == NULL){
            int oddFreq = 0;
            for(auto it: mp){
                if(it.second % 2 == 1) {
                    oddFreq++;
                }
            }
            if(oddFreq <= 1) ans++;
        }
        
        help(root->left, mp);
        help(root->right, mp);
        mp[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return 1;
        unordered_map<int, int>mp;
        help(root, mp);
        return ans;
    }
};
