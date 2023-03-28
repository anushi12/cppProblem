class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int longest =1;
       if(nums.size()==0) return 0;
       unordered_set<int>s;
       for(int i=0;i<nums.size();i++){
           s.insert(nums[i]);
       } 
       for(auto it:nums){
           if(s.find(it-1)==s.end())
           {
               int cnt=1;
               int x = it;
           while(s.find(x+1)!=s.end()){
               x = x+1;
               cnt = cnt +1;
           }
           longest = max(longest,cnt);
       }
    } 
       return longest;
    }
};
