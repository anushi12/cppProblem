class Solution {
public:
    bool halvesAreAlike(string s) {
        int a =0, b =0;
        int n = s.size();
        int half = s.size()/2;
        string str = "aeiouAEIOU";

        for(int i = 0; i < half; i++){
            if(count(str.begin(), str.end(),s[i]))
            a++;
        }
        for(int i = half; i < n; i++){
            if(count(str.begin(), str.end(),s[i]))
            b++;
        }

        return (a == b);
    }
};
