#include<bits/stdc++.h>
using namespace std;

// Recursive function to find the maximum sum of subarrays
// with the constraint that each subarray has at most 'k' elements
int f(int i, vector<int> &arr, int k, vector<int> &dp) {
    int n = arr.size();

    // Base case: If we have processed all elements in the array
    if (i == n) return 0;

    // If the result for the current index 'i' is already calculated, return it
    if (dp[i] != -1) return dp[i];
    
    int len = 0;  // Length of the current subarray
    int maxi = INT_MIN;  // Maximum element in the current subarray
    int maxAns = INT_MIN;  // Maximum sum calculated so far

    // Loop to explore subarrays starting from index 'i' up to 'i+k-1'
    for (int j = i; j < min(i + k, n); j++) {
        len++;  // Increment the length of the subarray
        maxi = max(maxi, arr[j]);  // Update the maximum element in the subarray
        int sum = (len * maxi) + f(j + 1, arr, k, dp);  // Calculate the sum of this subarray and recursive call
        maxAns = max(maxAns, sum);  // Update the maximum sum calculated so far
    }
    
    // Store the result in the DP table and return it
    return dp[i] = maxAns;
}

// Function to find the maximum sum of subarrays with at most 'k' elements
int maximumSubarray(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);  // DP table to store intermediate results
    return f(0, arr, k, dp);  // Call the recursive function starting from index 0
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    int result = maximumSubarray(arr, k);
    cout << "Maximum sum of subarrays with at most " << k << " elements: " << result << endl;
    
    return 0;
}
