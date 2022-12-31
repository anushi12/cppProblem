class Solution {
public:
    // This function takes a vector of integers as input and returns a vector of integers
    // representing the input vector with one added to it.
    vector<int> plusOne(vector<int>& digits) {
     // Start a loop that iterates through the digits in the input vector from the last element to the first
     for(int i= digits.size()-1;i>=0;i--){
         // If the current digit is not 9, we can simply add 1 to it and return the modified vector
         if(digits[i]!=9){
            digits[i]++;
         return digits;
     }  
     // Otherwise, set the current digit to 0 and continue iterating
     else digits[i]=0;
     }
     // If the loop finishes and all the digits are 9, it means we need to add a leading 1 to the vector
     digits.insert(digits.begin(),1);
     // Return the modified vector
     return digits;
    }
};
