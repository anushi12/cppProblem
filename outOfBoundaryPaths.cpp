class Solution {
public:
    int mod = 1e9 + 7;
    int allPaths(int i, int j, int remMoves, int &row, int &col, vector<vector<vector<int>>>&dp){
        if(remMoves < 0) return 0;
        if(i < 0 || j<0 || i == row || j == col){
            return 1;
        }
        if(dp[i][j][remMoves] != -1) {
            return dp[i][j][remMoves];
        }
        long ans = 0;
        ans += allPaths(i-1, j, remMoves - 1, row, col, dp); // up
        ans += allPaths(i+1, j, remMoves - 1, row, col, dp); // down
        ans += allPaths(i, j+1, remMoves - 1, row, col, dp); // right
        ans += allPaths(i, j-1, remMoves - 1, row, col, dp); // left
        ans %= mod;
        return dp[i][j][remMoves] = ans ;
    }
    int findPaths(int row, int col, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(row, vector<vector<int>>(col, vector<int>(maxMove +1, -1)));
        return allPaths(startRow, startColumn,maxMove, row, col, dp);
    }
};
