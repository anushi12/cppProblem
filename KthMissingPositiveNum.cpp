class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        // create a map to store the count of each number in the array
        map<int,int> mpp;
        for(int i=0; i<arr.size(); i++) {
            mpp[arr[i]] = 0;
        }
        
        // count the occurrence of each number in the array
        for(int i=0; i<arr.size(); i++) {
            mpp[arr[i]]++;
        }
        
        // loop through all possible numbers from 1 to 2001
        for(int i=1; i<=2001; i++) {
            // if the number is not present in the array
            if(mpp[i] == 0) {
                // decrement k
                k--;
            }
            // if we have found the kth missing number
            if(k == 0) {
                // return the current number
                return i;
            }
        }
        // if the kth missing number is not found, return -1
        return -1;
    }
};
