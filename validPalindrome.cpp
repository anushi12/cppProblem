class Solution {
public:   
     bool isPalindrome(string s) {
     // Initialize left and right pointers to the beginning and end of the string
     int left = 0, right = s.length()-1;
     
     // While the left pointer is less than the right pointer, do the following:
    while(left<right)
    {
        // If the character at the left pointer is not an alphanumeric character, increment the left pointer
        if(!isalnum(s[left])) left++;
        
        // If the character at the right pointer is not an alphanumeric character, decrement the right pointer
        else if(!isalnum(s[right])) right--;
        
        // If the characters at the left and right pointers are not equal, return false
        else if(tolower(s[left])!=tolower(s[right]))
          return false; 
          
        // If the characters at the left and right pointers are equal, increment the left pointer and decrement the right pointer
        else{left++,right--;}

    }
    
    // If the loop finishes, return true
    return true;
    }                    
};
