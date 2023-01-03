class Solution {
public:
    // This function returns the minimum number of columns that need to be deleted
    // from the input vector of strings in order for the strings to be lexicographically sorted
    // (i.e., in alphabetical order).
    int minDeletionSize(vector<string>& strs) {
        // Initialize a counter to keep track of the number of columns that need to be deleted
        int cnt = 0;
        
        // Get the number of rows (i.e., the number of strings) and the number of columns (i.e., the length of each string)
        int row = strs.size();
        int col = strs[0].size();
        
        // Iterate through each column in the strings
        for(int j=0; j< col; j++){
            // Iterate through each row (except the last one)
            for(int i=0; i < row-1; i++){
                // If the character at the current position in the current row is greater than the character at the same position
                // in the next row, we need to delete this column
                if(strs[i][j] > strs[i+1][j]){
                    cnt++;
                    // We can break out of the inner loop once we find that a column needs to be deleted
                    break;
                }
            }
        }
        
        // Return the number of columns that need to be deleted
        return cnt;
    }
};
