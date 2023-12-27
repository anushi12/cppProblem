class Solution {
public:
    long long func(int dice, int faces, int target,vector<vector<long long>>&dp){
        if(target == 0 && dice == 0) return 1;
        if((target != 0 && dice == 0) || (target == 0 && dice!= 0)) return 0;
        if(dp[dice][target] != -1) return dp[dice][target];
        long long ans = 0;
        for(int  i = 1; i<=faces; i++){
            if(target - i >= 0){
           ans = (ans + func(dice - 1, faces, target -i,dp)) % 1000000007;
            }
        }
       
        return dp[dice][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(n+1, vector<long long>(target + 1, -1));
        return func(n, k, target,dp);
    }
};
