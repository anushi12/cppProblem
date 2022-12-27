class Solution {
public:
    // This function takes in a vector of integers (nums) and removes any duplicates from it.
    // It returns the number of unique elements in the modified vector.
    int removeDuplicates(vector<int>& nums) {
        // If the vector is empty, there are no elements to remove, so we return 0.
        if(nums.size()==0)
            return 0; 
        
        // We use two pointers, i and j, to keep track of the elements we're looking at.
        // Initially, i is set to the first element in the vector (index 0) and j is set to the second element (index 1).
        int i=0;
        for(int j=1;j<nums.size();j++){
            // If the elements pointed to by i and j are different, we increment i and set nums[i] to nums[j].
            // This effectively removes any duplicates between nums[0] and nums[j].
            if(nums[i]!=nums[j])
                i++;
             nums[i]=nums[j];     
        } 
        // Finally, we return the number of unique elements in the modified vector, which is equal to i+1.
        return i+1;  
    }
};
