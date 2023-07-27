int minSubsetSumDifference(vector<int>& arr, int n) {
    int totSum = 0; // Initialize a variable to store the total sum of all elements in the 'arr' vector.
    for (int i = 0; i < n; i++)
        totSum += arr[i]; // Calculate the total sum by iterating through the array.

    int k = totSum; // 'k' represents the maximum possible sum of a subset of 'arr'.

    // Create a 2D DP array with 'n' rows and 'k+1' columns, initialized with 'false'.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = true; // For any subset, sum=0 is always possible (by taking no elements).

    if (arr[0] <= k)
        dp[0][arr[0]] = true; // Marking the first element of 'arr' as reachable (possible sum).

    // Now, we iterate through all elements of 'arr' to fill the DP array.
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool notTake = dp[ind - 1][target]; // Consider not taking the current element.
            bool take = false;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]]; // Consider taking the current element.
            dp[ind][target] = take | notTake; // Update the DP table for current 'ind' and 'target'.
        }
    }

    int mini = 1e9; // Initialize 'mini' to a large value (effectively positive infinity).

    // Find the minimum difference between sums of two subsets of 'arr'.
    // We iterate over all possible sums 's1' for the first subset (from 0 to totalSum/2).
    for (int s1 = 0; s1 <= totSum / 2; s1++) {
        if (dp[n - 1][s1] == true) { // If 's1' is reachable, calculate the difference.
            mini = min(mini, abs((totSum - s1) - s1)); // Calculate and update the minimum difference.
        }
    }

    return mini; // Return the minimum difference between two subset sums.
}
