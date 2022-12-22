class Solution {
public:
    // This function takes an integer as input and returns a boolean value
    // indicating whether the integer is a palindrome or not
    bool isPalindrome(int x) {
        // Convert the integer to a string
        string st = to_string(x);

        // Check if the string is equal to its reverse
        // st.rbegin() returns a reverse iterator pointing to the last element of the string
        // st.rend() returns a reverse iterator pointing to the element before the first element of the string
        // string(st.rbegin(),st.rend()) creates a new string with the elements in the range [st.rbegin(), st.rend())
        if(st == string(st.rbegin(), st.rend())) {
            // If the string is equal to its reverse, return true
            return true;
        } else {
            // If the string is not equal to its reverse, return false
            return false;
        }
    }
};
