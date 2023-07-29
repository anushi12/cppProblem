#include <bits/stdc++.h> 

// Function to find the number of ways to achieve a target sum 'tar'
// using elements from the vector 'arr'.
int findWays(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<int> prev(tar + 1, 0), cur(tar + 1, 0);

    // Base cases for the first element of 'arr'.
    // If arr[0] is 0, we have 2 ways to achieve a sum of 0 (considering or not considering arr[0]).
    // Otherwise, we have 1 way if arr[0] is less than or equal to 'tar'.
    if (arr[0] == 0)
        prev[0] = 2;
    else if (arr[0] <= tar)
        prev[arr[0]] = 1;

    // Fill the DP array using a bottom-up approach.
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= tar; sum++) {
            int notTake = prev[sum]; // Number of ways without considering arr[ind].
            int take = 0;
            if (arr[ind] <= sum)
                take = prev[sum - arr[ind]]; // Number of ways considering arr[ind].

            cur[sum] = (take + notTake); // Total number of ways for the current sum.
        }
        prev = cur; // Update the previous array with the current array.
    }

    return prev[tar]; // Return the number of ways to achieve the target sum 'tar'.
}

// Function to count the partitions of the vector 'arr' into two sets
// such that their difference equals 'd'.
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for (auto &it : arr) totSum += it;

    // If the total sum minus 'd' is negative or odd, it is not possible to partition.
    if (totSum - d < 0 || (totSum - d) % 2 != 0) return 0;

    // Find the number of ways to achieve a target sum of (totSum - d) / 2.
    return findWays(arr, (totSum - d) / 2);
}

// Function to find the number of ways to achieve the target sum 'target'
// using elements from the vector 'arr'.
int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}
