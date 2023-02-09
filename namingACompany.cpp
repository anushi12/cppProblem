class Solution {
public:
    // This function returns the count of distinct names that can be formed
    long long distinctNames(vector<string>& ideas) {
        long long distinctName=0; // To store the count of distinct names

        // Create a vector of 26 unordered_sets to store the names starting with each letter of the alphabet
        vector<unordered_set<string>>arr(26); 

        // Iterate through all the ideas in the input vector
        for(string i :ideas)
            // Insert the rest of the string after the first character into the unordered_set corresponding to that letter
            arr[i[0]-'a'].insert(i.substr(1));

        // Loop through all the unordered_sets in the vector and compare each pair of unordered_sets
        for(int j=0;j<25;j++){
            for(int k=j+1;k<26;k++){
                // Create a new unordered_set to store the union of the current pair of unordered_sets
                unordered_set<string>set;
                set.insert(arr[j].begin(),arr[j].end());
                set.insert(arr[k].begin(),arr[k].end());

                // Add the number of distinct names that can be formed using the names in the current pair of unordered_sets
                distinctName += (arr[j].size()-set.size())*(arr[k].size()-set.size());
                
            }
        }
        
        // Return the count of distinct names, multiplied by 2 to account for the reverse combinations
        return distinctName*2;
    }
};
