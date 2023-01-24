class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // The function takes in two parameters, an integer 'n' and an integer 'k'
        // It checks if the Kth bit of the binary representation of 'n' is set (1) or not (0)
        // It returns a boolean value - true if the Kth bit is set, false otherwise
        // The function uses bitwise AND operator (&) to check the Kth bit
        // It shifts the number 1 by k positions to the left using left shift operator (<<)
        // This results in a number with only the kth bit set (1) and all other bits set to 0
        // When this number is ANDed with the binary representation of 'n',    
      if(n & (1<<k))
      // if the kth bit of 'n' is also set, the result will be non-zero and the function returns true
      return true;
      else 
      // Otherwise, the result will be zero and the function returns false
      return false;
    }
};
