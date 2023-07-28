//memoisation
#include <bits/stdc++.h>

// Recursive function to find the maximum value that can be obtained from a knapsack
// using dynamic programming (top-down approach).
int f(int ind, int W, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp) {
    // Base case: If there are no items or no capacity left in the knapsack, return 0.
    if (ind == 0 || W == 0) {
        if (weight[0] <= W)
            return value[0]; // If the first item's weight can be accommodated, return its value.
        else
            return 0; // Otherwise, return 0 as no items can be taken.
    }

    // If the value for the current subproblem has already been calculated, return it from the DP table.
    if (dp[ind][W] != -1)
        return dp[ind][W];

    // Calculate the value when not taking the current item.
    int notTake = 0 + f(ind - 1, W, weight, value, dp);

    // Calculate the value when taking the current item.
    int take = INT_MIN;
    if (weight[ind] <= W)
        take = value[ind] + f(ind - 1, W - weight[ind], weight, value, dp);

    // Choose the maximum value between taking and not taking the current item and store it in the DP table.
    return dp[ind][W] = max(take, notTake);
}

// Function to find the maximum value that can be obtained from a knapsack.
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    int W = maxWeight; // Maximum capacity of the knapsack.
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // DP table to store intermediate results.

    // Call the recursive function to find the maximum value.
    return f(n - 1, W, weight, value, dp);
}


//space optimization

#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int>prev(maxWeight+1),cur(maxWeight+1);

	for(int W = weight[0]; W<=maxWeight;W++) prev[W] = value[0];
		for(int ind = 1; ind<n;ind++){
			for(int W = 0; W<=maxWeight; W++){
				int notTake = 0 + prev[W];
	            int take = INT_MIN;
	        if(weight[ind]<=W) take = value[ind] + prev[W-weight[ind]];
            cur[W] = max(take, notTake);
			}
          prev = cur;
		}
	return prev[maxWeight];
}

//most optimised way

#include <bits/stdc++.h>

// Function to find the maximum value that can be obtained from a knapsack.
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Create a 1D DP table to store the maximum values that can be obtained for different capacities.
	// prev[W] represents the maximum value that can be obtained for a knapsack of capacity W.
	vector<int> prev(maxWeight+1);

	// Base case: For the first item, initialize the DP table considering the available weight.
	for(int W = weight[0]; W <= maxWeight; W++)
		prev[W] = value[0];

	// Iterate through the remaining items and update the DP table.
	for(int ind = 1; ind < n; ind++) {
		for(int W = maxWeight; W >= 0; W--) {
			// Calculate the value when not taking the current item.
			int notTake = 0 + prev[W];

			// Calculate the value when taking the current item.
			int take = INT_MIN;
			if(weight[ind] <= W)
				take = value[ind] + prev[W - weight[ind]];

			// Choose the maximum value between taking and not taking the current item and store it in the DP table.
			prev[W] = max(take, notTake);
		}
	}

	// The maximum value that can be obtained for the knapsack of capacity 'maxWeight' is stored in prev[maxWeight].
	return prev[maxWeight];
}

