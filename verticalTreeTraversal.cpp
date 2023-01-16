class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map to store nodes, where key is the x coordinate, value is another map
        // where key is the y coordinate and value is a multiset containing node values
        map<int,map<int,multiset<int>>>nodes;
        // queue to store nodes to be processed
        queue<pair<TreeNode*,pair<int,int>>>todo;
        // push the root node and its coordinates (0,0) to the queue
        todo.push({root,{0,0}});
        // while there are still nodes to be processed
        while(!todo.empty()){
            // get the front node and its coordinates
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y= p.second.second;
            // insert the node's value into the corresponding location in the map
            nodes[x][y].insert(node->val);
            // if the node has a left child, push it to the queue with updated coordinates
            if(node->left){
                todo.push({node->left,{x-1,y+1}});
            }
            // if the node has a right child, push it to the queue with updated coordinates
            if(node->right){
                todo.push({node->right,{x+1,y+1}});
            }
        }
        // vector to store the final output
        vector<vector<int>>ans;
        // iterate through the map and extract the values in the correct order
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
