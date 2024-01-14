class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> str1(26,0), str2(26,0);
        for(auto c : word1) ++str1[c - 'a'];
        for(auto c : word2) ++str2[c - 'a'];

        for(int i =0; i<26; i++){
            if((str1[i] == 0 && str2[i]>0) || (str2[i] == 0 && str1[i]>0))
            return false;
        }
         sort(str1.begin(), str1.end());
         sort(str2.begin(), str2.end());

        
        return (str1 == str2);
    }
};
