class Solution {
public:
    // int func(int i, int j ,vector<vector<int>>& matrix, vector<vector<int>>&dp){
    //     if(j < 0 || j>= matrix[0].size()) return 1e8;
    //     if(i == 0) return matrix[0][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int up = matrix[i][j] + func(i-1, j, matrix,dp);
    //     int upleft = matrix[i][j] + func(i-1,j-1,matrix,dp);
    //     int upright = matrix[i][j] + func(i-1, j+1,matrix,dp);

    // return dp[i][j] = min(up, min(upleft, upright));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        for(int j =0; j<m; j++) dp[0][j] = matrix[0][j];

        for(int i =1; i<n; i++){
            for(int j=0; j<m; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int upleft = matrix[i][j] ;
                if(j-1>=0) upleft += dp[i-1][j-1];
                else upleft += 1e8;
                
                int upright = matrix[i][j];
                if(j+1 <m) upright += dp[i-1][j+1];
                else upright += 1e8;
                dp[i][j] = min(up, min(upleft, upright));
            }
        }

        int mini = 1e8;
        for(int j =0; j<m;j++){
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};
