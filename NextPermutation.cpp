class Solution {
public:
    // This function modifies the input vector to the next lexicographically larger permutation
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); // Store the length of the vector
        int i, k; // Declare loop variables

        // Find the first element from the right that is smaller than its right neighbor
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }         
        }

        // If no such element is found, the permutation is already at its maximum, so we reverse the whole vector
        if (i < 0) {
            reverse(nums.begin(), nums.end());     
        }
        // Otherwise, we proceed to modify the permutation
        else {
            // Find the first element from the right that is larger than nums[i]
            for (k = n - 1; k > i; k--) {
                if (nums[k] > nums[i]) {
                    break;
                }
            }   
            // Swap nums[i] and nums[k]
            swap(nums[i], nums[k]);
            // Reverse the elements to the right of i to get the next permutation
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
