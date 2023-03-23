class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Create a new vector `ans` of the same size as the input vector `nums`
        // Initialize all elements of `ans` to 0
        vector<int> ans(nums.size(), 0);
        
        // Initialize two variables, `posNum` and `negNum`, to keep track of the 
        // positions where positive and negative numbers will be placed in `ans`
        int posNum = 0, negNum = 1;
        
        // Loop through all elements of `nums`
        for(int i = 0; i < nums.size(); i++){
            // If the current element of `nums` is negative, place it in `ans` 
            // at position `negNum` and update `negNum` by 2 to skip the next 
            // position where a negative number will be placed
            if(nums[i] < 0){
                ans[negNum] = nums[i];
                negNum += 2;
            }
            // If the current element of `nums` is positive, place it in `ans` 
            // at position `posNum` and update `posNum` by 2 to skip the next 
            // position where a positive number will be placed
            else{
                ans[posNum] = nums[i];
                posNum += 2;
            }
        }
        
        // Return the rearranged array
        return ans;
    }
};
