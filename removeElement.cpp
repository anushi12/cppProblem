class Solution {
public:
    // Function to remove all occurrences of a given value from a vector of integers
    // and return the new length of the modified vector
    int removeElement(vector<int>& nums, int val) {
       // Initialize index 'i' to zero
       int i=0;

       // Iterate through the vector
       for( int j=0;j<nums.size();j++){
           // If the current element is not equal to the given value,
           // copy it to the element at index 'i' and increment 'i'
           if(nums[j]!=val)
           nums[i++]=nums[j];
       }

       // Return the new length of the modified vector
       return i;
    }
};
