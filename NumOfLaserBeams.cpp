class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int prev = 0, newCount = 0, ans =0;
       for(auto str: bank){
           newCount = 0;
           for(auto ch : str){
               if(ch == '1') newCount++;
           }
           if(newCount != 0){
               ans += newCount * prev;
               prev = newCount;
           }
       } 
       return ans;
    }
};
