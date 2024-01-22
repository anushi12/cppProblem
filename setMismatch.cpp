class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int>mp;
        int actualSum = 0;
        for(int i =0; i<nums.size(); i++){
               actualSum += nums[i];
        }
        int duplicate = 0;
        for(auto it: nums){
           if(mp.contains(it)){
               duplicate = it;
               break;
           }
           mp.insert({it,1});
        }
        int n = nums.size();
        int expectedSum = n*(n+1)/2;
    
       
        auto missing = expectedSum -(actualSum - duplicate);
        return {duplicate, missing};
    }
};
