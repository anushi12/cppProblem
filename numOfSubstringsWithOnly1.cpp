class Solution {
public:
    int numSub(string s) {
        // Initialize two variables
        long cnt=0,ans=0;
        // Loop through the string s
        for(int i=0;i<s.size();i++){
            // If the current character is '1', increment cnt
            if(s[i]=='1'){
                cnt++;
            }
            // If the current character is '0', calculate the number of substrings
            else {
                // Formula to calculate the number of substrings: (n * (n+1))/2
                ans += (cnt *(cnt+1))/2;
                // Reset cnt to 0
                cnt=0;
            }
        }
        // If the string ends with '1', calculate the number of substrings again
        return (ans+(cnt *(cnt+1))/2)% 1000000007;
    }
};
