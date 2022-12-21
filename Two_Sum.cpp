class Solution {
public:
    // This function takes in a vector of integers and a target value
    // and returns a vector of integers containing the indices of
    // the elements in the input vector that sum to the target value
    vector<int> twoSum(vector<int>& nums, int target) {
        // Initialize an empty vector to store the indices
        vector<int>ans;
        
        // Loop through the input vector
        for(int i=0;i<nums.size();i++){
            // Loop through the rest of the vector, starting from the element after i
            for(int j= i+1;j<nums.size();j++){
                // If the elements at indices i and j sum to the target value
                if(nums[i]+nums[j]==target){
                    // Add the indices to the result vector
                    ans.push_back(i);
                    ans.push_back(j);
                    // Break out of the inner loop
                    break;
                }
            }
        }
        // Return the result vector
        return ans;
    }
};
