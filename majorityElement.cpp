class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int ele, cnt=0; // Initialize variables ele (current majority element) and cnt (count of current majority element)
       for(int i=0;i<nums.size();i++){ // Loop through the elements of the vector
           if(cnt){ // If cnt is not 0, i.e. there is a current majority element
               cnt+= (nums[i]==ele ? 1 : -1); // Increment cnt if nums[i] is equal to the current majority element, decrement otherwise
           }
           else{ // If cnt is 0, i.e. there is no current majority element
               ele = nums[i]; // Set the current majority element to nums[i]
               cnt=1; // Set the count of current majority element to 1
           }
       }
         return ele; // Return the majority element    
    }
};
