class Solution {
public:
    int maxPower(string s) {
        // initialize the maximum count of consecutive characters to the smallest integer value
        int maxi = INT_MIN;
        // initialize the count of consecutive characters to 1
        int cnt= 1;
        // iterate through each character in the string
        for(int i=0;i<s.size();i++){
            // if the current character is the same as the next character
            if(s[i]==s[i+1])
                // increment the count of consecutive characters
                cnt++;
            
            else{
                // update the maximum count of consecutive characters if the current count is greater
                maxi = max(maxi,cnt);
                // reset the count of consecutive characters to 1
                cnt=1;
            }
        }
        // return the maximum count of consecutive characters
        return maxi;
    }
};
