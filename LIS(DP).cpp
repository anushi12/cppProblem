class Solution {
public:
    int func(int ind,int prevInd,vector<int>& nums,vector<vector<int>>&dp){
        if(ind == nums.size()) return 0;

        if(dp[ind][prevInd +1] != -1) return dp[ind][prevInd +1];
        int notTake = 0 + func(ind +1, prevInd, nums,dp);
        int take =0;
        if(prevInd == -1 || nums[ind]>nums[prevInd]){
        take = 1 + func(ind +1, ind, nums,dp);
        }

        return dp[ind][prevInd +1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(0, -1,nums,dp);
    }
};
