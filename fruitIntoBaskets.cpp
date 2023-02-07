class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Create a map to store the frequency of each unique fruit
        map<int, int> mpp;

        // Initialize ans to store the length of the longest subarray
        // and j to keep track of the start of the subarray
        int ans = 0, j = 0;
  
        // Iterate through the fruits vector
        for (int i = 0; i < fruits.size(); i++) {
            // Increment the frequency of the current fruit in the map
            mpp[fruits[i]]++;

            // Check if the size of the map is less than or equal to 2
            if (mpp.size() <= 2) {
                // If so, calculate the total count of all the fruits
                int cnt = 0;
                for (auto it : mpp) {
                    cnt += it.second;
                }

                // Update the ans variable with the maximum count
                ans = max(ans, cnt);
            } else {
                // If the map size is greater than 2
                // Keep decrementing the frequency of the first fruit in the subarray
                // until the size of the map is reduced to 2
                while (mpp.size() > 2) {
                    if (mpp[fruits[j]] == 1) {
                        mpp.erase(fruits[j]);
                    } else {
                        mpp[fruits[j]]--;
                    }
                    j++;
                }
            }
        }

        // Return the length of the longest subarray
        return ans; 
    }
};
