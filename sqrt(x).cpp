class Solution {
public:
    // Function to find the square root of a given number x
    int mySqrt(int x) {
        // Initialize start and end variables for binary search
        long long start=0, end = x;
        
        // Initialize variable to store the final answer
        long long ans;

        // Use binary search to find the square root
        while(start<=end){
            // Calculate the mid point
            long long mid = (start+end)/2;
            
            // Check if mid is the square root
            if(mid*mid == x){
                // If mid is the square root, return mid
                return mid;
            }
            // If mid^2 is less than x, set start to mid+1 and update ans to mid
            else if(mid*mid<x){
                start = mid+1;
                ans=mid;
            }
            // If mid^2 is greater than x, set end to mid-1
            else{
                end = mid - 1;
            }
        }
        
        // Return the final answer
        return ans; 
    }
};
