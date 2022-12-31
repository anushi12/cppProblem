class Solution {
public:
    // This function returns the index at which the target value should be inserted
    // in the sorted array nums, such that the resulting array remains sorted.
    int searchInsert(vector<int>& nums, int target) {
        // Initialize the start and end indices of the search range
        int start=0,end=nums.size()-1;
        
        // Keep searching until the start index is greater than the end index
        while(start<=end){
            // Calculate the midpoint of the search range
            int mid = start + (end- start)/2;
            // If the target value is found at the midpoint, return the index
            if(nums[mid]==target)
                return mid;
            // If the target value is greater than the value at the midpoint, update the start index to search the right half of the array
            else if(target>nums[mid])
                     start=mid+1;  
            // If the target value is less than the value at the midpoint, update the end index to search the left half of the array
            else
                 end=mid-1;
        }
        
        // If the target value is not found in the array, return the start index (where the target value should be inserted)
        return start;
    }
};
