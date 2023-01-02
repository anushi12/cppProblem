class Solution {
public:
    // This function returns a boolean indicating whether the capitalization of the characters in the
    // input string is correct.
    bool detectCapitalUse(string word) {
        // Initialize a count to keep track of the number of capital letters in the string.
        int count = 0;

        // If the string has only one character, it is considered correctly capitalized.
        if(word.size()==1) {
            return true;
        }

        // Iterate through the characters in the string and increment the count for each capital letter.
        for(int i=0; i<word.size();i++) {
            if(isupper(word[i])) {
                count++;
            }
        }

        // If the first letter is capitalized and there is only one capital letter in the string, the
        // capitalization is correct.
        if(isupper(word[0]) && count ==1) {
            return true;
        }

        // If there are no capital letters in the string, or if all of the letters are capitalized, the
        // capitalization is correct.
        if(count==0 || word.size()==count) {
            return true;
        }

        // If none of the above conditions are met, the capitalization is incorrect.
        else {
            return false;
        }
    }
};
