class Solution {
public:
    int lengthOfLastWord(string s) {
      // Initialize a variable to store the length of the last word
        int ans=0;
      
      // Iterate through the string in reverse order
        for(int i=s.size()-1;i >= 0;i--){
          
         // If we have already found the last word and we encounter a space,
        // we return the length of the last word
        if(ans>0 && s[i]==' ')
        return ans;
          
        // If we encounter a non-space character, we increment the length of the last word
        if(s[i]!=' ')
        ans++;
        }
      
      //return length of last word
        return ans;
    }
};
