class Solution {
public:
    // This function returns the minimum number of rounds required to finish the given tasks.
    int minimumRounds(vector<int>& tasks) {
        // Create a map to store the frequency of each task.
        map<int,int>mp;
        for(int i=0;i<tasks.size();i++)
            mp[tasks[i]]++;

        int ans=0;
        // Iterate through the map and calculate the minimum number of rounds required for each task.
        for(auto element : mp){
            // If there is only one task of this type, it cannot be completed. Return -1.
            if(element.second ==1)
                return -1;
            // If the number of tasks of this type is divisible by 3, add the quotient to the answer.
            // Otherwise, add the quotient + 1.
            if(element.second % 3 ==0)
                ans += element.second/ 3;
            else
                ans += element.second/3 +1;
        }
        return ans;
    }
};
