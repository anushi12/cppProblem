#include <bits/stdc++.h> 

/*int f(int i,int j, vector<int>& a, vector<vector<int>>&dp){
	if(i>j) return 0;
     
	int maxi = INT_MIN;
	if(dp[i][j]!=-1) return  dp[i][j];
	for(int ind = i;ind<=j;ind++){
		int coins = a[i-1]*a[ind]*a[j+1] + f(i,ind-1,a,dp) + f(ind +1,j,a,dp);
        maxi = max(maxi,coins);
	}
	return dp[i][j] = maxi;
}*/
int maxCoins(vector<int>& a) {
    // Get the size of the input vector
    int n = a.size();
    
    // Add two extra elements (1 at the beginning and 1 at the end)
    // This is done to simulate the effect of bursting adjacent balloons even outside the given range
    a.push_back(1);
    a.insert(a.begin(), 1);
    
    // Create a 2D vector to store the dynamic programming results
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Iterate from the last balloon to the first
    for (int i = n; i >= 1; i--) {
        // Iterate from the first balloon to the last within the current range
        for (int j = 1; j <= n; j++) {
            if (i > j) continue;  // Skip invalid cases where i > j
            
            int maxi = INT_MIN;  // Initialize a variable to store the maximum coins achievable
            
            // Iterate through each balloon in the current range
            for (int ind = i; ind <= j; ind++) {
                // Calculate the coins obtained from bursting the current balloon
                int coins = a[i - 1] * a[ind] * a[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                
                // Update the maximum coins achievable within the current range
                maxi = max(maxi, coins);
            }
            
            // Store the maximum coins achievable for the current range in the DP table
            dp[i][j] = maxi;
        }
    }
    
    // Return the maximum coins achievable for the entire range (1 to n)
    return dp[1][n];
}
