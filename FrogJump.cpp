bool canCross(vector<int>& stones) {
    int n = stones.size();
    
    // dp[i][j] represents whether the frog can reach stone j with a jump of size i.
    vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
    
    // The frog can start at the first stone and make an initial jump of size 1.
    dp[0][1] = true;

    // Iterate over each stone starting from the second one.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = stones[i] - stones[j];
            
            // If the difference between the current stone and the previous stone
            // is greater than n or it's not possible to reach the previous stone
            // with the given difference, then continue to the next iteration.
            if (diff > n || !dp[j][diff]) 
                continue;

            // If the current stone is the last stone, then the frog can successfully
            // cross the river, and we return true.
            if (i == n - 1) 
                return true;

            // Mark that the frog can reach the current stone with the given difference.
            dp[i][diff] = true;

            // Consider possible next jumps: (diff - 1) and (diff + 1).
            if (diff - 1 >= 0) 
                dp[i][diff - 1] = true;
            if (diff + 1 <= n) 
                dp[i][diff + 1] = true;
        }
    }

    // If the loop completes without returning true, then the frog cannot cross
    // the river, and we return false.
    return false;
}
