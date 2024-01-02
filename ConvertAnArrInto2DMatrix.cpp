class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>list;
        
        unordered_map<int,int>mp;
        for(auto num : nums){
            mp[num]++;
        }
        while(!mp.empty()){
            vector<int>ans;
            for(auto it = mp.begin(); it != mp.end();){
                ans.push_back(it->first);
                it->second--;

                if(it->second == 0){
                    it = mp.erase(it);
                }else{
                   it++;
                 }
            }
            list.push_back(ans);
        }
      return list;
    }
};
