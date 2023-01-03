class Solution {
public:
    // This function returns the row of the Pascal's Triangle with the given index
    vector<int> getRow(int rowIndex) {
        // Initialize variables for looping through the rows and elements of the triangle
        int i, j;

        // Initialize a 2D vector to store the rows of the Pascal's Triangle
        vector<vector<int>> ans; 
       
        // Loop through the rows of the triangle
        for(i = 0; i <= rowIndex; i++) {
            // Initialize a new row with `i+1` elements, all set to 1
            vector<int> row(i+1, 1);

            // Loop through the elements of the row (excluding the first and last elements, which are always 1)
            for(j = 1; j < i; j++) {
                // Set the current element to the sum of the two elements in the previous row
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            // Add the current row to the triangle
            ans.push_back(row);
        }

        // Return the requested row
        return ans[rowIndex];
    }
};
