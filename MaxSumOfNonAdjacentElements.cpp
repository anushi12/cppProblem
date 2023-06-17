//Brute Force using memoization
// time complexity - O(N)
//space complexity - O(N) + O(N)

#include <bits/stdc++.h>

int f(int ind, vector<int> &nums, vector<int>&dp){
    if(ind == 0) return nums[ind];
    if(ind<0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int pick = nums[ind] + f(ind - 2,nums,dp);
    int notpick = 0 + f(ind -1,nums,dp);

    return dp[ind] = max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}




// second approach through space optimisation
// time complexity - O(N)
//space complexity - O(1)

#include <bits/stdc++.h>

// Function to find the maximum sum of non-adjacent elements in a vector
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];     // Initialize previous sum as the first element
    int prev2 = 0;          // Initialize previous sum of the element two positions before

    for(int i=1; i<n;i++){  // Loop through the vector starting from the second element
        int pick = nums[i]; // Selecting the current element

        // If we are not at the beginning of the vector, add the previous sum of two positions before
        if(i > 1) 
            pick += prev2;

        int notpick = 0 + prev; // Not selecting the current element, take the previous sum

        int curi = max(pick,notpick); // Choose the maximum sum between picking and not picking the current element

        prev2 = prev;   // Update the previous sum of two positions before
        prev = curi;    // Update the previous sum
    }
    
    return prev;    // Return the maximum sum of non-adjacent elements
}
