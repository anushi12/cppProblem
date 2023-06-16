#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Create a dynamic programming array to store the minimum cost for reaching each position
    vector<int> dp(n, 0);
    
    // Initialize the first position with cost 0
    dp[0] = 0;
    
    // Initialize the right variable to maximum possible value
    int right = INT_MAX;
    
    // Iterate through each position starting from the second position
    for(int i = 1; i < n; i++)
    {
        // Calculate the cost of jumping from the previous position to the current position (left jump)
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        
        // Calculate the cost of jumping from the position two steps back to the current position (right jump)
        // This condition checks if it is possible to jump two steps back without going out of bounds
        if (i > 1) 
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        // Store the minimum cost between left and right jumps in the dp array
        dp[i] = min(left, right);
    }
    
    // Return the minimum cost to reach the last position
    return dp[n-1];
}






// space optimisation
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Initialize variables to store the previous and previous-to-previous minimum costs
    int prev = 0;
    int prev2 = 0;
    
    // Iterate through each position starting from the second position
    for(int i = 1; i < n; i++)
    {
        // Calculate the cost of jumping from the previous position to the current position (left jump)
        int left = prev + abs(heights[i] - heights[i-1]);
        
        // Initialize the cost of jumping from two positions back to the current position (right jump)
        int right = INT_MAX;
        
        // Check if it is possible to jump two steps back without going out of bounds
        if (i > 1)
        {
            // Calculate the cost of jumping from two positions back to the current position (right jump)
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }
        
        // Determine the minimum cost between the left jump and the right jump
        int cur = min(left, right);
        
        // Update the previous and previous-to-previous minimum costs
        prev2 = prev;
        prev = cur;
    }
    
    // Return the minimum cost to reach the last position
    return prev;
}
