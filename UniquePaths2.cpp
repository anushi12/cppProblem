//MEMOISATION APPROACH
int mod = (int)(10e9 + 7); // A constant variable used for taking the modulo of the result

// Recursive function to calculate the number of paths
// i, j: current position in the matrix
// mat: input matrix
// dp: memoization table for storing previously computed results
int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1; // Base case: Reached the top-left corner, return 1
    if (i < 0 || j < 0) return 0; // Base case: Out of bounds, return 0
    if (i >= 0 && j >= 0 && mat[i][j] == -1) return 0; // Base case: Obstacle encountered, return 0

    if (dp[i][j] != -1) return dp[i][j]; // If the result is already computed, return it from memoization table

    // Recursive calls to explore paths from the top and left positions
    int up = f(i - 1, j, mat, dp); 
    int left = f(i, j - 1, mat, dp);

    // Store the result in the memoization table, taking modulo to avoid large values
    return dp[i][j] = (up + left) % mod;
}

// Function to find the number of paths in the maze
// n, m: dimensions of the matrix
// mat: input matrix with obstacles
int mazeObstacles(int n, int m, vector<vector<int>>& mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization table to store computed results
    return f(n - 1, m - 1, mat, dp); // Start the recursive function from the bottom-right corner
}



// TABULATION APPROACH
int mazeObstacles(int n, int m, vector<vector<int>>& mat) {
    // Write your code here
    int dp[n][m]; // Dynamic programming table to store computed results

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1)
                dp[i][j] = 0; // If an obstacle is encountered, set the value in the dp table to 0
            else if (i == 0 && j == 0)
                dp[i][j] = 1; // Base case: Reached the top-left corner, set the value to 1
            else {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j]; // Value from the cell above
                if (j > 0)
                    left = dp[i][j - 1]; // Value from the cell on the left

                dp[i][j] = (up + left) % mod; // Calculate and store the result in the dp table, taking modulo to avoid large values
            }
        }
    }

    return dp[n - 1][m - 1]; // Return the result stored at the bottom-right corner of the dp table
}



//SPACE OPTIMISATION

int mazeObstacles(int n, int m, vector< vector<int> > &mat) {
    // Initialize the previous row with zeros
    vector<int> prev(m, 0);

    // Traverse each row of the matrix
    for (int i = 0; i < n; i++) {
        // Initialize the current row with zeros
        vector<int> cur(m, 0);

        // Traverse each column of the current row
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1)
                cur[j] = 0; // Obstacle cell, set the current count to zero
            else if (i == 0 && j == 0)
                cur[j] = 1; // Starting cell, set the current count to one
            else {
                int up = 0, left = 0;
                // Check if there is a valid cell above the current cell
                if (i > 0)
                    up = prev[j];
                // Check if there is a valid cell to the left of the current cell
                if (j > 0)
                    left = cur[j - 1];

                // Calculate the current count as the sum of counts from above and left cells,
                // then take the modulo of 'mod' to prevent overflow
                cur[j] = (up + left) % mod;
            }
          
         }
        prev = cur;
    }
    return prev[m-1] ; 
}
