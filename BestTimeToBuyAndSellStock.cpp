class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // initialize the variables for maximum profit and lowest price seen so far
        int max_profit=0;
        int low = INT_MAX;
        // variable to hold the current profit
        int curr =0;
        
        // loop through the prices vector
        for(int i=0;i<prices.size();i++){
            // if the current price is lower than the lowest price seen so far, update the lowest price
            if(prices[i]<low){
                low =prices[i];
            }
            // calculate the maximum profit that can be made with the current price
            max_profit = prices[i] - low;
            // if the current profit is greater than the previously seen maximum profit, update the current profit
            if(curr<max_profit){
                curr = max_profit;
            }
        }
        // return the maximum profit that can be made
        return curr;
    }
};
