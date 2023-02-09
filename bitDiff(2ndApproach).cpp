class Solution{
    public:
    // Function to find the number of set bits in an integer
    int countSetBit(int n){
        // Initialize the answer to 0
        int ans=0;
        
        // Keep looping until n becomes 0
        while(n>0){
            // Clear the least significant bit of n
            n = n & (n-1);
            // Increment the answer
            ans++;
        }
        // Return the answer
        return ans;
    }
    
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // XOR of a and b gives us a number whose set bits are the bits that are different between a and b
        int Xor = a^b;
        
        // Return the number of set bits in the XOR result
        return countSetBit(Xor);   
    }
};
