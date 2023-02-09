class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Counter for the number of bits that need to be flipped
        int cnt=0;
        
        // Loop through all 32 bits of the integers
        for(int i=0;i<32;i++){
            
            // Get the least significant bit of 'a'
            int a1 = a & 1;
            
            // Get the least significant bit of 'b'
            int b1 = b & 1;
            
            // If the bits are different, increment the counter
            if(a1 != b1){
                cnt++;
            }
            
            // Right shift 'a' and 'b' to get the next bit
            a=a>>1;
            b=b>>1;
        }
     
        // Return the number of bits that need to be flipped
        return cnt;   
    }
};
