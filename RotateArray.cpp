class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Create a new vector with the same size as the input vector
        vector<int> vec(nums.size());
        
        // Loop through the input vector
        for(int i = 0; i < nums.size(); i++) {
            // Calculate the new index for the current element
            int newIndex = (i + k) % nums.size();
            
            // Set the element at the new index to the current element
            vec[newIndex] = nums[i];
        }
        
        // Replace the input vector with the rotated vector
        nums = vec;
    } 
};
