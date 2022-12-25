class Solution {
public:
    bool isValid(string s) {
        // create an empty stack to store characters
        stack<char> st;

        // iterate through each character in the string
        for (char c : s) {
            // if the stack is empty or the character is an opening bracket, push it onto the stack
            if (st.empty() || c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            // if the character is a closing bracket
            else {
                // if the top element on the stack does not match the corresponding opening bracket for the closing bracket, return false
                if ((st.top() != '(' && c == ')') || 
                    (st.top() != '[' && c == ']') ||
                    (st.top() != '{' && c == '}')) {
                    return false;
                }
                // if the top element on the stack does match the corresponding opening bracket, pop it off the stack
                st.pop();
            }    
        }

        // return true if the stack is empty (all brackets have been matched), otherwise return false
        return st.empty();
    }
};
