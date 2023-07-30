#include <bits/stdc++.h>

/*int f(int ind, int W, vector<int> &pro,vector<int> &wt,vector<vector<int>>&dp){
    if(ind == 0){
     return ((int)(W/wt[0]))*pro[0];  
    }
    if(dp[ind][W] != -1) return dp[ind][W];
    int notTake = 0 + f(ind-1,W,pro,wt,dp);
    int take = 0;
    if(wt[ind]<=W) take = pro[ind] + f(ind,W-wt[ind],pro,wt,dp);

    return dp[ind][W] = max(take,notTake);
}*/

int unboundedKnapsack(int n, int w, vector<int> &pro, vector<int> &wt){
    // Write Your Code Here.
    vector<vector<int>>dp(n,vector<int>(w+1,0));

    for (int W = 0; W <= w; W++) {
      dp[0][W] = ((int)(W / wt[0])) * pro[0];
    }
    for(int ind = 1;ind<n;ind++){
        for(int W = 0;W<=w;W++){
            int notTake = 0 + dp[ind-1][W];
            int take = 0;
            if(wt[ind]<=W) take = pro[ind] + dp[ind][W-wt[ind]];

           dp[ind][W] = max(take,notTake);
        }
    }
    return dp[n-1][w];
}




// space optimisation
int unboundedKnapsack(int n, int w, vector<int> &pro, vector<int> &wt){
    // Write Your Code Here.
    vector<int>prev(w+1,0);

    for (int W = 0; W <= w; W++) {
      prev[W] = ((int)(W / wt[0])) * pro[0];
    }
    for(int ind = 1;ind<n;ind++){
        for(int W = 0;W<=w;W++){
            int notTake = 0 + prev[W];
            int take = 0;
            if(wt[ind]<=W) take = pro[ind] + prev[W-wt[ind]];
            prev[W] = max(take,notTake);
        }
    }
    return prev[w];
}
