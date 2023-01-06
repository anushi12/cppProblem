class Solution {
public:
    // Function to check if two strings are isomorphic
    bool isIsomorphic(string s, string t) {
        // Hash maps to store the mapping of characters in 's' and 't'
        int map_s[128] = {0};  // ASCII characters range from 0 to 127
        int map_t[128] = {0};

        // Iterate through all characters in both strings
        for(int i = 0; i < s.size(); i++) {
            // If the mapping of character 's[i]' in 's' is not the same as the mapping of character 't[i]' in 't'
            if(map_s[s[i]] != map_t[t[i]])
                // The strings are not isomorphic
                return false;

            // Otherwise, update the mapping of characters in both strings
            map_s[s[i]] = i + 1;  // i+1 is used because 0 is a valid index
            map_t[t[i]] = i + 1;
        }

        // If we reach here, it means that the strings are isomorphic
        return true;
    }
};
