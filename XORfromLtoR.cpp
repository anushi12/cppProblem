class Solution {
public:
  // Function to find XOR value of a number
  int find(int num){
    // If the number is divisible by 4, return the number itself
    if(num % 4==0) return num;
    // If the number is divisible by 4 with a remainder of 1, return 1
    if(num % 4==1) return 1;
    // If the number is divisible by 4 with a remainder of 2, return the number plus 1
    if(num % 4==2) return num + 1;
    // If the number is divisible by 4 with a remainder of 3, return 0
    if(num % 4==3) return 0;
  }
  
  // Function to find XOR of all numbers in the given range [l, r]
  int findXOR(int l, int r) {
    // Call the find function to find the XOR value of l-1
    int x = find(l-1);
    // Call the find function to find the XOR value of r
    int y = find(r);
    
    // Return the XOR of x and y
    return x^y;
  }
};
