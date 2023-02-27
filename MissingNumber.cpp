class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int sum=0;
      int cnt=0;
      
      for(int i=0;i<nums.size();i++){
          cnt++;
          sum += nums[i]; // sum of numbers present in the array
      } 
      int req_sum= (cnt*(cnt+1))/2; // total sum of all the numbers
      return req_sum - sum; //  total sum - sum
    }
};
