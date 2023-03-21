class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0, ans =0; // initialize variables cnt and ans to 0
        for(int i=0;i<nums.size();i++){ // loop through each element in the vector
            if(nums[i]==0){ // if the current element is 0
                cnt++; // increment the counter
            }
              else if(nums[i]!=0){ // if the current element is not 0
                  ans += cnt*(cnt+1)/2; // calculate the number of subarrays with 0s and add to ans
                  cnt=0; // reset the counter
              }
        }
        return ans +=(cnt*(cnt+1)/2); // calculate the number of subarrays with 0s at the end and return the total
    }
};
