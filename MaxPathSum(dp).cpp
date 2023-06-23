//  MEMOISATION

#include <bits/stdc++.h>

int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // If the column index is out of bounds, return a very small value as a sentinel.
    if (j < 0 || j >= matrix[0].size()) return -1e8;
    
    // If we have reached the first row, return the value in the matrix at the current position.
    if (i == 0) return matrix[0][j];
    
    // If the value has already been calculated and stored in the dp matrix, return it.
    if (dp[i][j] != -1) return dp[i][j];
    
    // Recursively calculate the maximum sum by moving up, up-left, and up-right.
    int up = matrix[i][j] + f(i - 1, j, matrix, dp);
    int upLeft = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    int upRight = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

    // Store the calculated maximum sum in the dp matrix and return it.
    return dp[i][j] = max(up, max(upLeft, upRight));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    // Write your code here.
    
    // Get the number of rows and columns in the matrix.
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Create a dp matrix to store the computed values for dynamic programming.
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    // Initialize the maximum sum with a very small value.
    int maxi = -1e8;
    
    // Iterate over each column of the last row to find the maximum sum.
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, f(n - 1, j, matrix, dp));
    }
    
    // Return the maximum sum.
    return maxi;
}




//TABULATION

#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    
    // Get the number of rows and columns in the matrix.
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Create a dp matrix to store the computed values for dynamic programming.
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // Initialize the first row of the dp matrix with the values from the matrix.
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }
    
    // Iterate over each row (starting from the second row) and each column to calculate the maximum path sum.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + dp[i-1][j];
            int upLeft = matrix[i][j];
            
            // Check if it's possible to move to the left (j-1) and include its value in the sum.
            if (j-1 >= 0) {
                upLeft += dp[i-1][j-1];
            } else {
                // If moving left is not possible, assign a very small value as a sentinel.
                upLeft += -1e8;
            }
            
            int upright = matrix[i][j];
            
            // Check if it's possible to move to the right (j+1) and include its value in the sum.
            if (j+1 < m) {
                upright += dp[i-1][j+1];
            } else {
                // If moving right is not possible, assign a very small value as a sentinel.
                upright += -1e8;
            }
            
            // Calculate the maximum sum at the current position and store it in the dp matrix.
            dp[i][j] = max(up, max(upLeft, upright)); 
        }
    }

    // Find the maximum sum in the last row of the dp matrix.
    int maxi = -1e8;
    for (int j = 0; j < m; j++) {
       maxi = max(maxi, dp[n-1][j]);
    }
    
    // Return the maximum sum.
    return maxi;
}



//SPACE OPTIMISATION

#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    
    // Get the number of rows and columns in the matrix.
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Create two vectors to store the computed values for dynamic programming.
    // `prev` represents the previous row, and `cur` represents the current row.
    vector<int> prev(m, 0), cur(m, 0);
    
    // Initialize the first row of `prev` with the values from the matrix.
    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j];
    }
    
    // Iterate over each row (starting from the second row) and each column to calculate the maximum path sum.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];
            int upLeft = matrix[i][j];
            
            // Check if it's possible to move to the left (j-1) and include its value in the sum.
            if (j-1 >= 0) {
                upLeft += prev[j-1];
            } else {
                // If moving left is not possible, assign a very small value as a sentinel.
                upLeft += -1e8;
            }
            
            int upright = matrix[i][j];
            
            // Check if it's possible to move to the right (j+1) and include its value in the sum.
            if (j+1 < m) {
                upright += prev[j+1];
            } else {
                // If moving right is not possible, assign a very small value as a sentinel.
                upright += -1e8;
            }
            
            // Calculate the maximum sum at the current position and store it in the `cur` vector.
            cur[j] = max(up, max(upLeft, upright)); 
        }
        // Update `prev` with the values of `cur` for the next iteration.
        prev = cur;
    }

    // Find the maximum sum in the last row (`prev` vector).
    int maxi = -1e8;
    for (int j = 0; j < m; j++) {
       maxi = max(maxi, prev[j]);
    }
    
    // Return the maximum sum.
    return maxi;
}
