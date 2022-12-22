class Solution {
public:
    bool isPalindrome(int x) {
        // Initialize result to 0
        int result =0;
        
        // If x is negative or ends with 0 (but is not 0 itself), it cannot be a palindrome
        if(x<0 || (x%10==0) && x!=0) return false;
        
        // Keep extracting the last digit of x and adding it to the result until x is greater than the result
        while(x>result)
        {
            int curr= x%10; // Extract the last digit of x
            x/=10; // Remove the last digit from x
            result= result*10+ curr; // Add the extracted digit to the result
        }
        
        // Return true if x is equal to the result, or if x is equal to the result with the last digit removed (for odd-length palindromes)
        return x == result || x == result/10;
    }
};
