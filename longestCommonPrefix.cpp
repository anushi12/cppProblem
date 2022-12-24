class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      
      // Sort the strings in the vector in ascending order
     sort(strs.begin(),strs.end());
      
      // Initialize an empty string to store the longest common prefix
     string answer= "";
      
      // Store the first and last strings in the vector in separate variables
     string a = strs[0];
     string b = strs[strs.size()-1];
     
      // Iterate through the characters of the first string
     for(int i= 0; i<a.length();i++){
       // If the characters at the current index are the same in both strings
         if(a[i]==b[i]){
           // Add the character to the result string
             answer += a[i];
         }
       
        // If the characters are not the same, break the loop
         else break;
     } 
      // Return the result string
     return answer;  
    }
};
