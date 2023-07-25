#include <bits/stdc++.h>
using namespace std;

// Function to check if there exists a subset of 'arr' that sums up to 'target'.
bool f(int ind, int target, vector<int> &arr, vector<vector<int>>& dp) {
    // Base case: If the target is 0, we have found a valid subset.
    if (target == 0) return true;

    // Base case: If 'ind' becomes 0, we cannot form the target sum.
    if (ind == 0) return (arr[0] == target);

    // If we have already calculated the result for the current state, return it.
    if (dp[ind][target] != -1) return dp[ind][target];

    // Recursive case: We have two choices - either take the current element or not take it.
    bool notTake = f(ind - 1, target, arr, dp); // Don't take the current element.
    bool take = false;
    if (arr[ind] <= target)
        take = f(ind - 1, target - arr[ind], arr, dp); // Take the current element.

    // Save the result for the current state and return it.
    return dp[ind][target] = take | notTake;
}

// Function to check if there exists a subset of 'arr' that sums up to 'k'.
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a 2D DP array with -1 to store the results of subproblems.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // Call the helper function to check if there exists a subset with sum 'k'.
    return f(n - 1, k, arr, dp);
}

// Example usage:
// int main() {
//     vector<int> arr = {2, 4, 7, 1, 5};
//     int n = arr.size();
//     int k = 10;
//     if (subsetSumToK(n, k, arr))
//         cout << "There exists a subset with sum " << k << " in the array.";
//     else
//         cout << "No subset with sum " << k << " found in the array.";
//     return 0;
// }


//TABULATION 

#include <bits/stdc++.h>


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n, vector<bool>(k+1,0));
    
    for(int ind = 0; ind <= n-1;ind++) dp[ind][0] = true;
    dp[0][arr[0]] = true;

    for(int ind = 1;ind<=n-1;ind++){
        for(int target = 1; target <= k; target ++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];

         dp[ind][target] = take|notTake;
        }
    }
    return dp[n-1][k];
}



//SPACE OPTIMIZATION
#include <bits/stdc++.h>


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1,0) , cur(k+1,0);
    
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;

    for(int ind = 1;ind<=n-1;ind++){
        for(int target = 1; target <= k; target ++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target) take = prev[target - arr[ind]];

        cur[target] = take|notTake;
        }
        prev = cur;
    }
    return prev[k];
}
