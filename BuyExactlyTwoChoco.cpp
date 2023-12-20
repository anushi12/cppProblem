class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int sum = 0;
        sort(prices.begin(), prices.end());
        for(int i =0 ;i <prices.size();i++){
            sum  = prices[i] + prices[i+1];
            if(sum <= money){
                return money - sum;
            }
             else
              return money;
        }
        return money;
    }
};
