class Solution {
public:
    // This function returns true if the input integer n is a power of 2, and false otherwise
    bool isPowerOfTwo(int n) {
        // If n is less than or equal to 0, it cannot be a power of 2, so return false
        if(n<=0){
            return false;
        }
        // If n is equal to 1, then it is a power of 2, so return true
        if(n==1){
            return true;
        }
        // If n is not evenly divisible by 2, then it cannot be a power of 2, so return false
        if(n%2!=0){
            return false;
        }
        // If none of the above conditions were met, then n must be evenly divisible by 2.
        // Call the function again with n/2 as the input. The function will continue to do this until
        // either a base case is reached (n is 1 or n is less than or equal to 0) or it is determined that
        // n is not a power of 2.
        return isPowerOfTwo(n/2);
    }
};
