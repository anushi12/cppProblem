class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false; // A flag to indicate if the first row has a zero
        bool col = false; // A flag to indicate if the first column has a zero
        
        // Check each element in the matrix and mark the corresponding
        // row and column in the first row and first column with a zero.
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    if(i==0) row = true;    // Mark first row if a zero is found
                    if(j==0) col = true;    // Mark first column if a zero is found
                    matrix[0][j]= matrix[i][0] =0; // Mark the corresponding row and column in the first row and first column with a zero
                }
            }
        }
        
        // Iterate over the matrix again, and for each element,
        // if the corresponding row or column in the first row or
        // first column is marked with a zero, set the element to zero.
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        
        // Finally, if any of the flags is set to true, set all the
        // elements in the corresponding row or column to zero.
        if(row){
            for(int j =0 ;j<matrix[0].size();j++) matrix[0][j]=0; // Set all elements in the first row to zero
        } 
        if(col){
            for(int i=0;i<matrix.size();i++) matrix[i][0] =0;    // Set all elements in the first column to zero
        }
    }
};
