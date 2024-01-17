class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        set<int>st;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: mp){
            st.insert(it.second);
        }
        return (st.size() == mp.size());
    }
};
