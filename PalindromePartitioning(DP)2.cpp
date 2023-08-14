#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MAX

using namespace std;

// Function to check if a substring of 's' from index 'i' to 'j' is a palindrome
bool isPalindrome(int i, int j, string s) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Function to calculate the minimum number of partitions needed for palindrome partitioning
int f(int i, int n, string &a, vector<int> &dp) {
    if (i == n)
        return 0;

    int mini = INT_MAX; // Initialize the minimum cost to a large value
    if (dp[i] != -1)
        return dp[i]; // If already computed, return the stored value
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, a)) {
            int cost = 1 + f(j + 1, n, a, dp); // Calculate cost for current partition
            mini = min(mini, cost); // Update minimum cost
        }
    }
    return dp[i] = mini; // Store and return the computed minimum cost
}

// Function to calculate the minimum number of partitions needed for palindrome partitioning
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n, -1); // Initialize a DP array to store computed values
    // Minus 1 is subtracted because the code does a partition at the last character.
    // For example, ABC --> A|B|C|, but it should be A|B|C.
    return f(0, n, str, dp) - 1; // Call the recursive function and subtract 1 from the result
}

int main() {
    string input = "abcba";
    int result = palindromePartitioning(input);
    cout << "Minimum partitions needed: " << result << endl;
    return 0;
}


// 2. TABULATION

int palindromePartitioning(string str)
{ 
    int n = str.size();
    vector<int>dp(n+1,0);
    dp[n] =0;
    for(int i = n-1;i>=0;i--){
        int mini = INT_MAX;
        for(int j = i; j<n;j++){
            if(isPalindrome(i,j,str)){
            int cost = 1 + dp[j+1];
            mini = min(mini,cost);
         }
     }
    dp[i] = mini;
    }
    //do a minus 1 bcoz the code does a partition at the last.
    //ABC --> A|B|C|   it should be A|B|C.
    return dp[0]-1;
}
