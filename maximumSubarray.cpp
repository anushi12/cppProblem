class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi= INT_MIN; // Initialize the maximum subarray sum to the minimum possible value
        int sum=0; // Initialize the current sum to zero
        for(auto it: nums){ // Loop through each element of the input array
            sum += it; // Add the current element to the running sum
            maxi = max(sum,maxi); // Update the maximum subarray sum seen so far
            if(sum<0){ // If the running sum is negative
                sum = 0; // Reset the running sum to zero
            }
        }
        return maxi; // Return the maximum subarray sum seen
    }
};
