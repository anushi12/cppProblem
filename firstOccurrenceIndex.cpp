class Solution {
public:
    int strStr(string haystack, string needle) {
        // Store the lengths of the haystack and needle strings
        int n = haystack.size();
        int m = needle.size();
    
        // Iterate through the haystack string
        for(int i=0; i<=n-m;i++){
            // Initialize a second loop variable to 0
            int j=0;
            // Iterate through the needle string
            for(;j<m;j++){
                // Compare the jth character of the needle with the (i+j)th character of the haystack
                if(haystack[i+j]!=needle[j])
                // If they are not equal, break out of the loop
                break;
            }
            // If the loop completed without breaking, it means that the needle has been found in the haystack starting from index i
            if(j==m){
            // Return the index of the start of the needle
            return i;
            } 
        }   
        
        // If the needle was not found, return -1
        return -1;
    }
};
