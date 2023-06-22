//MEMOISATION

#include <bits/stdc++.h>

// Recursive function to calculate the minimum path sum
// i: current row index
// j: current column index
// n: total number of rows in the triangle
// triangle: the triangle matrix
// dp: memoization table for dynamic programming
int f(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    // Base case: if we reach the last row, return the value in the triangle
    if (i == n - 1)
        return triangle[n - 1][j];

    // If the result for this cell is already computed, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // Calculate the minimum path sum by moving down and diagonally
    int down = triangle[i][j] + f(i + 1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + f(i + 1, j + 1, n, triangle, dp);

    // Store the minimum path sum in the memoization table
    return dp[i][j] = min(down, diagonal);
}

// Function to calculate the minimum path sum in the triangle
// triangle: the triangle matrix
// n: total number of rows in the triangle
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    // Create a memoization table initialized with -1
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Call the recursive function to calculate the minimum path sum
    return f(0, 0, n, triangle, dp);
}




//TABULATION

#include <bits/stdc++.h>

// Function to calculate the minimum path sum in the triangle
// triangle: the triangle matrix
// n: total number of rows in the triangle
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    // Create a 2D memoization table initialized with zeros
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the last row of the memoization table
    // with the values from the last row of the triangle
    for (int j = n - 1; j >= 0; j--) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Calculate the minimum path sum for each cell
    // starting from the second-to-last row up to the first row
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum by moving down and diagonally
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum path sum in the current cell of the memoization table
            dp[i][j] = min(down, diagonal);
        }
    }

    // The minimum path sum is stored in the top-left cell of the memoization table
    return dp[0][0];
}



//SPACE OPTIMISATION

#include <bits/stdc++.h>

// Function to calculate the minimum path sum in the triangle
// triangle: the triangle matrix
// n: total number of rows in the triangle
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    // Create two vectors to store the current and front rows of the memoization table
    vector<int> front(n, 0);  // Represents the front row
    vector<int> cur(n, 0);    // Represents the current row

    // Initialize the front row with the values from the last row of the triangle
    for (int j = n - 1; j >= 0; j--) {
        front[j] = triangle[n - 1][j];
    }

    // Calculate the minimum path sum for each row starting from the second-to-last row up to the first row
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum by moving down and diagonally
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];

            // Store the minimum path sum in the current cell of the current row
            cur[j] = min(down, diagonal);
        }
        // Update the front row to be the current row
        front = cur;
    }

    // The minimum path sum is stored in the first element of the front row
    return front[0];
}
