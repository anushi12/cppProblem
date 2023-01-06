class Solution {
public:
    // This function returns the maximum number of ice cream cones
    // that can be bought with the given amount of coins
    int maxIceCream(vector<int>& costs, int coins) {
       int ans=0;
      
        // Sort the costs of the ice cream cones in ascending order
        sort(costs.begin(),costs.end());
        
        // Iterate through the costs of the ice cream cones
        for(int i=0; i<costs.size();i++){
           // If the cost of the current ice cream cone is more than the available coins, we can't buy it
           if(costs[i]>coins)
           break;
           // Subtract the cost of the current ice cream cone from the available coins
           coins -= costs[i];
           // Increment the number of ice cream cones bought
           ans++;
        }
        // Return the number of ice cream cones bought
        return ans;
    }
};
