bool isParentSum(Node *root){
    // Write your code here.
    if(root == NULL || (root->left == NULL &&root->right == NULL)){
        return true;
    }
    int ans =0;
    if(root->left) ans += root->left->data;
    if(root->right) ans+= root->right->data; 
    if(ans == root->data){ 
            return isParentSum(root->left) &&
                isParentSum(root->right);
     }
     else return false;

}
