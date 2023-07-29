#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x)
{
    // Function to find the minimum number of elements required
    // from the vector 'num' to form the sum 'x'.

    int n = num.size(); // Get the size of the vector 'num'.
    vector<vector<int>> dp(n, vector<int>(x + 1, 0)); // Create a 2D DP array.

    // Initialize the base case for the first element of 'num'.
    // It calculates the minimum number of occurrences of num[0]
    // required to form the target sum 'tar'.
    for (int tar = 0; tar <= x; tar++) {
        if (tar % num[0] == 0)
            dp[0][tar] = tar / num[0]; // Minimum number of occurrences of num[0].
        else
            dp[0][tar] = 1e9; // If 'tar' is not divisible by num[0], set it to a very high value.
    }

    // Fill the DP array using a bottom-up approach.
    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= x; tar++) {
            int notTake = dp[ind - 1][tar]; // Number of elements required without considering num[ind].
            int take = INT_MAX; // Initialize the number of elements required considering num[ind].

            // If 'num[ind]' is less than or equal to the target 'tar',
            // we can choose to include it and reduce the target.
            if (num[ind] <= tar)
                take = 1 + dp[ind][tar - num[ind]]; // 1 indicates we have taken num[ind].

            dp[ind][tar] = min(take, notTake); // Choose the minimum between take and notTake.
        }
    }

    int ans = dp[n - 1][x]; // The result will be in the last cell of the DP array.
    if (ans >= 1e9)
        return -1; // If no valid combination is found, return -1.
    return ans; // Return the minimum number of elements required to form the target sum.
}
