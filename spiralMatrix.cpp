vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    // Get the dimensions of the matrix
    int n = MATRIX.size();
    int m = MATRIX[0].size();
    
    // Initialize the boundaries of the matrix traversal
    int top = 0, bottom = n-1;
    int left =0, right = m-1;
    
    // Initialize an empty vector to store the result
    vector <int>ans;
    
    // Traverse the matrix in a spiral order
    while(top<=bottom && left<=right){
        // Traverse the top row from left to right
        for(int i= left;i<=right;i++){
            ans.push_back(MATRIX[top][i]);
        }
        // Move down to the next row
        top ++;
        
        // Traverse the right column from top to bottom
        for(int i= top;i<=bottom;i++){
            ans.push_back(MATRIX[i][right]);
        }
        // Move left to the next column
        right--;
        
        // If there is a row left to traverse, traverse the bottom row from right to left
        if(top<=bottom){
            for(int i= right;i>=left;i--){
                ans.push_back(MATRIX[bottom][i]);
            }
            // Move up to the next row
            bottom--;
        }
        
        // If there is a column left to traverse, traverse the left column from bottom to top
        if(left<=right){
            for (int i = bottom; i >= top; i--) {
                ans.push_back(MATRIX[i][left]);
            }
            // Move right to the next column
            left++;
        }
    }
    
    // Return the result vector
    return ans;
}
