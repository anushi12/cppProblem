#include <bits/stdc++.h> 
int mod = (int)(1e9 + 7);

/* This function calculates the number of ways to select a subset of the elements
   in the 'arr' array such that their sum is equal to 'tar'.
   It uses a dynamic programming approach to optimize the solution.
*/
int findWays(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<int> prev(tar + 1, 0), cur(tar + 1, 0);

    // Handling the base cases for the first element of the array
    if (arr[0] == 0)
        prev[0] = 2; // Two ways: take it or don't take it
    else
        prev[0] = 1; // Only one way: take it if it equals the target sum

    if (arr[0] != 0 && arr[0] <= tar)
        prev[arr[0]] = 1; // If the first element equals the target sum, one way to take it

    // Starting from the second element of the array
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= tar; sum++) {
            int notTake = prev[sum]; // Number of ways to get 'sum' without considering the current element
            int take = 0; // Number of ways to get 'sum' by taking the current element

            // If the current element can be included in the sum, update 'take'
            if (arr[ind] <= sum)
                take = prev[sum - arr[ind]];

            // Calculate the total ways for the current 'sum' using both take and notTake
            cur[sum] = (take + notTake) % mod;
        }
        prev = cur; // Update the previous row to the current row for the next iteration
    }

    return prev[tar]; // Return the number of ways to get the target sum
}

/* This function counts the number of ways to partition the 'arr' array into two subsets
   such that their difference is equal to 'd'. It uses the 'findWays' function to solve the problem.
   If it's not possible to form subsets with the given difference 'd', it returns 0.
   Otherwise, it returns the number of ways to form such subsets.
*/
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;

    // Calculate the total sum of all elements in the 'arr' array
    for (auto &it : arr)
        totSum += it;

    // If the difference 'd' exceeds the total sum or the difference is odd, it's not possible to form subsets
    if (totSum - d < 0 || (totSum - d) % 2)
        return 0;

    // Find the number of ways to form subsets with the required difference
    return findWays(arr, (totSum - d) / 2);
}
