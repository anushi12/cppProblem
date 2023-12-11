class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int maxi = INT_MIN; int ans;
        map<int,int>mp;
        for(int i = 0; i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it: mp){
            if(it.second > maxi){
                maxi = it.second;
                ans = it.first;
            }
           
        }
        return ans ;
    }
};
