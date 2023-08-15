int countSquares(int n, int m, vector<vector<int>> &arr) {
    // Create a 2D vector to store the dynamic programming values
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the first row of the dp matrix with the values from the input array's first row
    for (int j = 0; j < m; j++)
        dp[0][j] = arr[0][j];

    // Initialize the first column of the dp matrix with the values from the input array's first column
    for (int i = 0; i < n; i++)
        dp[i][0] = arr[i][0];

    // Fill in the rest of the dp matrix using dynamic programming
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0)
                dp[i][j] = 0; // If the current element in the input array is 0, no square can be formed here
            else {
                // Calculate the value for the current cell based on the minimum of its neighbors in the dp matrix
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }

    int sum = 0;

    // Calculate the sum of all values in the dp matrix, which represents the total number of squares
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }

    return sum; // Return the total count of squares
}




