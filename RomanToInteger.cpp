class Solution {
public:
    // Function to return the corresponding integer value of a given Roman numeral
    int value(char r)
    {
        if(r=='I') return 1;
        if(r=='V') return 5;
        if(r=='X') return 10;
        if(r=='L') return 50;
        if(r=='C') return 100;
        if(r=='D') return 500;
        if(r=='M') return 1000;
        
        // Return -1 if the input is invalid
        return -1;
    }

    int romanToInt(string s) {
        // Initialize result and the values of the current and next characters
        int result = 0;
        int sFirst = 0;
        int sSecond = 0;

        // Iterate through the string and add the values of each character
        for(int i = 0; i < s.length(); i++) {
            // Get the value of the current character
            sFirst = value(s[i]);

            // Get the value of the next character if it exists
            if (i + 1 <= s.length()) {
              sSecond = value(s[i+1]);
            }

            // If the current character has a higher or equal value to the next character, add it to the result
            if (sFirst >= sSecond) {
                result += sFirst;
            }
            // Otherwise, the current character is a "subtractive" Roman numeral and should be subtracted from the next character
            else {
                result += sSecond - sFirst;
                i++;
            }
        }

        // Return the final result
        return result;
    }
};
