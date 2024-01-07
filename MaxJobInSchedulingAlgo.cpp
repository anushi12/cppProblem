class Solution {
public:
    int find(int i, vector<vector<int>>&jobs, vector<int>& startTime, int n, vector<int>&dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ind = lower_bound(startTime.begin(), startTime.end(),jobs[i][1]) - startTime.begin();
        int notTake = find(i+1, jobs, startTime, n,dp);
        int take = jobs[i][2] + find(ind, jobs, startTime, n, dp);

        return dp[i] = max(notTake, take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        int n = startTime.size();
        vector<int>dp(n,-1);
        for(int i =0; i<n ;i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(), startTime.end());
        return find(0,jobs,startTime,n,dp);
    }
};
