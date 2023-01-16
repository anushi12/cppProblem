class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // vector to store the final output
        vector<vector<int>>res;
        // if the root is NULL, return an empty vector
        if(root==NULL) return res;
        // queue to store nodes to be processed
        queue<TreeNode*>q;
        // push the root node to the queue
        q.push(root);
        // boolean to keep track of the traversal direction
        bool leftToRight = true;

        // while there are still nodes to be processed
        while(!q.empty()){
            // get the number of nodes at the current level
            int size= q.size();
            // vector to store the values of the nodes at the current level
            vector<int>row(size);
        
            // iterate through the nodes at the current level
            for(int i=0; i<size;i++){
                // get the front node
                TreeNode* node = q.front();
                q.pop();
                // if the node has a left child, push it to the queue
                if(node->left)
                {
                    q.push(node->left);
                }
                // if the node has a right child, push it to the queue
                if(node->right){
                    q.push(node->right);
                }
                // determine the correct index for the node's value based on the traversal direction
                int index =leftToRight ? i : (size-1-i); 
                // store the node's value at the correct index
                row[index]= node->val;
            }
            // toggle the traversal direction
            leftToRight = !leftToRight;
            // add the current level's values to the final output
            res.push_back(row);
        }

        return res;
    }
};
