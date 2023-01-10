class Solution {
public:
    int reverse(int x) {
        // Initialize a variable to store the reversed number
        int ans = 0;
        // Make a copy of the input number
        int num = x;
  
        // While there are still digits left to process
        while (num) {
            // Check if the current reversed number will overflow or underflow
            // If it will, return 0 (as per the problem statement)
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            } else {
                // Otherwise, add the next digit to the reversed number
                ans = ans * 10 + num % 10;
                // Remove the last digit from the input number
                num = num / 10;
            }
        }
  
        // Return the reversed number
        return ans;
    }
};
