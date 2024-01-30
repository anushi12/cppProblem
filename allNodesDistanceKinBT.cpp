/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*> &mp){
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            if(node->left){
                mp[node->left] = node;
                queue.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                queue.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>mp;
        parent(root, target, mp);

        queue<TreeNode*>queue;
        queue.push(target);

        unordered_map<TreeNode*, bool> vis;
        vis[target] = true;

        int level = 0;
        while(!queue.empty()){
            int size = queue.size();
            if(level++ == k) break;
            for(int i =0; i<size; i++){
               TreeNode* cur = queue.front();
               queue.pop();
               if(cur->left && !vis[cur->left]){
                   queue.push(cur->left);
                   vis[cur->left] = true;
               }
               if(cur->right && !vis[cur->right]){
                   queue.push(cur->right);
                   vis[cur->right] = true;
               }
               if(mp[cur] && !vis[mp[cur]]){
                   queue.push(mp[cur]);
                   vis[mp[cur]] = true;
               }
            }
        }
        vector<int>res;
        while(!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            res.push_back(node->val);
        }
        return res;
    }
};
