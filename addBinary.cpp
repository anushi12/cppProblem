class Solution {
public:
    // This function adds two binary strings and returns the result
    string addBinary(string a, string b) {
        // Initialize variables to store the lengths of the input strings and the carry value
        int i = a.size()-1;  
        int j = b.size()-1;
        int carry=0;
        // Initialize an empty result string
        string res;
        // Loop until we have processed both input strings
        while(i>=0 || j>=0)  
        {
            // Initialize the sum to the carry value
            int sum = carry;
            // If we have not processed the entire first input string, add the value at the current index to the sum
            if(i>=0) sum += a[i--]-'0';
            // If we have not processed the entire second input string, add the value at the current index to the sum
            if(j>=0) sum += b[j--]-'0';
            // Update the carry value
            carry = sum>1? 1:0;
            // Append the least significant digit of the sum to the result string
            res += to_string(sum%2);
        }    
        // If there is a remaining carry value, append it to the result string
        if(carry)
            res += to_string(carry);
        // Reverse the result string before returning it
        reverse(res.begin(),res.end());
        return res;
    }
};
