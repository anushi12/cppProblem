class Solution {
    public:
        vector<int> AllPrimeFactors(int N) {
            // Create an empty vector to store prime factors
            vector<int> ans;
            
            // Create an unordered set to keep track of factors that have already been added to the vector
            unordered_set<int> s;
            
            // Loop through all possible prime factors less than or equal to the square root of N
            for(int i = 2; i * i <= N; i++) {
                // While i is a factor of N, add it to the ans vector and insert it into the set if it hasn't been added already
                while(N % i == 0) {
                    if(s.find(i) == s.end()) { // Check if i has already been added to the ans vector
                        ans.push_back(i);
                        s.insert(i);
                    }
                    N /= i; // Divide N by i so we can find the remaining prime factors
                }
            }
            
            // If there is still a factor greater than the square root of N, add it to the ans vector
            if(N > 1) {
                ans.push_back(N);
            }
            
            // Return the vector of prime factors
            return ans;
        }
};
