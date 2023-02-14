//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // Create a map to store the frequency of each number in the array
        map<int,int> mpp;
        // Create a vector to store the odd numbers in the array
        vector<long long int> ans;
        
        // Loop through the array and update the frequency of each number in the map
        for(int i=0; i<N; i++){
            mpp[Arr[i]]++;
        }
        
        // Loop through the map and find the odd frequency numbers
        for(auto it: mpp){
            if(it.second % 2 != 0){
                // Add the odd frequency number to the vector
                ans.push_back(it.first);
            }
        }
        
        // Sort the vector in descending order
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        
        // Return the vector of odd frequency numbers
        return ans;
    }
};
