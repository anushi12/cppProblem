class Solution {
public:
    void sortColors(vector<int>& nums) {
       int low=0, mid=0, high=nums.size()-1; // initialize pointers for low, mid, and high indices
       for(int i=0;i<nums.size();i++){ // loop through the entire vector
           if(nums[mid]==0){ // if current element is 0, swap with the element at the low index
            swap(nums[low], nums[mid]); 
            low++; // increment low index
            mid++; // increment mid index
           }
           else if( nums[mid]==1){ // if current element is 1, move mid index forward
            mid++;
           }
           else{ // if current element is 2, swap with the element at the high index
            swap( nums[mid], nums[high]);
            high--; // decrement high index
           }
       }
    }
};
