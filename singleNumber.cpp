class Solution {
public:
    // function to find the single number in a given array
    int singleNumber(vector<int>& nums) {
        // sort the array
        sort(nums.begin(),nums.end());
        
        // iterate through the array, starting at the second element
        for(int i=1;i<nums.size();i+=2){
          // if the current element is not equal to the previous element
          if(nums[i]!=nums[i-1])
          // return the previous element (which is the single number)
          return nums[i-1];
        } 
        // if no single number is found, return the last element
        return nums[nums.size()-1];  
    }
};



//optimised solution

class Solution {
public:
    // function to find the single number in a given array
    int singleNumber(vector<int>& nums) {
        // variable to store the result
        int ans=0;
        //iterating through the array
        for(auto x:nums){
            //using XOR operation
            ans^=x;
        }  
        //returning the result
        return ans; 
    }
};

