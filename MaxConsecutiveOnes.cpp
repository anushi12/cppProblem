class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0; // variable to keep track of current count of consecutive ones
        int  maxi=0; // variable to keep track of maximum count of consecutive ones
        for(int i=0;i<nums.size();i++){ // loop through the vector
            if(nums[i]==1){ // if current element is 1
                cnt++; // increase count of consecutive ones
            }
            else{ // if current element is not 1 (i.e. 0)
                cnt = 0; // reset count of consecutive ones
            }
            maxi = max(maxi,cnt); // update maximum count of consecutive ones
        }
     
        return maxi; // return the maximum count of consecutive ones
    }
};
