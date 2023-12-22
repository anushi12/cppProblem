class Solution {
public:
    int maxScore(string s) {
      int maxi = INT_MIN;
      int lcnt = 0, rcnt = 0, ans;

      for(int i = 0; i<s.size(); i++){
          if(s[i]== '1') rcnt++;
      }
      for(int i = 0; i<s.size()-1; i++){
            if(s[i] == '1') rcnt--; 
            if(s[i] == '0') lcnt++;
            int ans = lcnt + rcnt;
            maxi = max(maxi, ans);
          }
          
        
      return maxi;
    }
};
