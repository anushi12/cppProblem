class Solution {
public:
    int countHomogenous(string s) {
        //initialize variables to keep track of count and answer
        int cnt=0,ans=0;
        
        //iterate through each character in the string
        for(int i=0;i<s.size();i++){
            //if the current character is the same as the previous character
            if(i>0 && s[i-1]==s[i])
                //increment the count
                cnt++;
            else
                //if the current character is different from the previous one,
                //reset the count to 1
                cnt=1;
                
            //update the answer by adding the current count modulo 10^9+7
            ans = (ans+cnt)% 1000000007;
        } 
        
        //return the final answer
        return ans;
    }
};
