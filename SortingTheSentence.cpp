class Solution {
public:
    string sortSentence(string s) {
        // `initial` keeps track of the initial position of the current word being read
        int initial = 0;
        // `mpp` is a map that will store the words in the sentence
        // mapped to their corresponding position numbers
        map<int,string> mpp;
        // Loop through all characters in the string
        for(int i=0; i<s.size(); i++){
            // Check if the current character is a digit
            if(isdigit(s[i])){
                // If it is, the current word ends at position `i-1`
                // and starts at position `initial`
                // We extract the word using the `substr` function
                mpp[s[i]] = s.substr(initial, i - initial);
                // We skip the space between the word and the digit
                i++;
                // We set the new initial position to be one position after the digit
                initial = i+1;
            }
        }
        // `res` is a string that will store the sorted sentence
        string res;
        // Loop through all elements in the map
        for(auto it : mpp){
            // Concatenate the words in the order of their position numbers
            res += it.second + " ";
        }
        // Remove the trailing space at the end of the sentence and return it
        return res.substr(0,res.size()-1);
    }
};
