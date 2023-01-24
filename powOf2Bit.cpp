class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        // Check if the number is zero
        if(n==0) return false;
        // Using bitwise AND operator, check if the number is a power of 2
        // If a number is a power of 2, it only has one bit set to 1 and all the others are 0
        // Therefore, n & (n-1) will be 0 for a power of 2
        return !(n & (n-1));
    }
};
