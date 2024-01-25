class Solution {
public:
/****** MEMOIZATION *******/
    int func(int ind1, int ind2,string text1, string text2, vector<vector<int>>&dp){
        if(ind1 >= text1.size() || ind2 >= text2.size()) {
            return 0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(text1[ind1] == text2[ind2]){
           return 1 + func(ind1 + 1, ind2 + 1, text1, text2,dp);
        }
        return max(func(ind1 + 1, ind2, text1, text2,dp), func(ind1, ind2+1, text1, text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return func(0,0, text1, text2, dp);
    }
};

/**** TABULATION ******/
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i =0; i<=m; i++){
            dp[n][i] = 0;
        }
        for(int j =0; j<=n; j++){
            dp[j][m] = 0;
        }
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int take = 0, notTake = 0;
                if(text1[i] == text2[j]){
                    take = 1 + dp[i + 1][j + 1];
                }
                 notTake = max(dp[i + 1][j], dp[i][j+1]);
                 dp[i][j] = max(take, notTake);
            }
        }

       return dp[0][0];
    }
};


/******* SPACE OPTI ********/
int func(string text1, string text2, int&n, int &m){
    vector<int>next(m+1,0); vector<int>cur(m+1,0);
        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                    
                if(text1[i] == text2[j]){
                     cur[j] = 1 + next[j + 1];
                }
                else cur[j] = max(next[j], cur[j+1]);
            }
            next = cur; 
         }

     return next[0];
}

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        return func(text1, text2, n,m);
    }
};
