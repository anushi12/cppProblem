class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = neededTime[0];
        int maxCost = neededTime[0];
        for(int i = 1; i<colors.size(); i++){
             if(colors[i] != colors[i-1]){
               ans -= maxCost;
               maxCost = 0;
            }
            ans += neededTime[i];
            maxCost = max(maxCost,neededTime[i]);
        }
        return ans - maxCost;
    }
};
