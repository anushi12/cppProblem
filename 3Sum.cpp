class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the input array in ascending order
        sort(nums.begin(), nums.end());

        // Create a vector to store the resulting triplets
        vector<vector<int>> res;

        // Iterate through the array
        for (int i = 0; i < (int)(nums.size()) - 2; i++) {
            // Skip duplicates (if the current number is the same as the previous number)
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                // Find a pair of numbers in the remaining array that sum up to the target
                int low = i + 1, high = (int)(nums.size()) - 1, sum = 0 - nums[i];

                while (low < high) {
                    // If the current pair sums up to the target
                    if (nums[low] + nums[high] == sum) {
                        // Create a vector to store the triplet
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);

                        // Add the triplet to the result vector
                        res.push_back(temp);

                        // Skip duplicates (if the next number is the same as the current number)
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;

                        // Move the pointers to continue searching for triplets
                        low++;
                        high--;
                    }
                    // If the current pair is smaller than the target, move the left pointer
                    else if (nums[low] + nums[high] < sum)
                        low++;
                    // If the current pair is larger than the target, move the right pointer
                    else
                        high--;
                }
            }
        }

        // Return the resulting vector of triplets
        return res;
    }
};


// time complexity: O(N*N)
// space complexity: O(M)(for return result) otherwise auxillary space complexity is O(1)
