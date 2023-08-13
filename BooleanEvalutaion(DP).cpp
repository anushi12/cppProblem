#include<bits/stdc++.h>
#define ll long long

int mod = 1000000007;

// Function to evaluate the number of ways to make the given expression true or false.
long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>>& dp) {
    // Base case: if i crosses j, there are no ways to evaluate the expression.
    if (i > j) return 0;

    // Base case: when i and j point to the same character.
    if (i == j) {
        if (isTrue) {
            return exp[i] == 'T';
        } else {
            return exp[i] == 'F';
        }
    }

    ll ways = 0;
    // Check if the result for this subproblem is already calculated and stored in dp.
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    // Iterate through all possible operators in the expression.
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        // Calculate the number of ways for different combinations of subexpressions.
        ll leftTrue = f(i, ind - 1, 1, exp, dp);
        ll rightTrue = f(ind + 1, j, 1, exp, dp);
        ll leftFalse = f(i, ind - 1, 0, exp, dp);
        ll rightFalse = f(ind + 1, j, 0, exp, dp);

        // Evaluate the expression based on the current operator.
        if (exp[ind] == '&') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            } else {
                ways = (ways + (leftTrue * rightFalse) % mod +
                        (leftFalse * rightTrue) % mod +
                        (rightFalse * leftFalse) % mod) % mod;
            }
        } else if (exp[ind] == '|') {
            if (isTrue) {
                ways = (ways + (leftTrue * rightFalse) % mod +
                        (leftFalse * rightTrue) % mod +
                        (leftTrue * rightTrue) % mod) % mod;
            } else {
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
            }
        } else {
            if (isTrue) {
                ways = (ways + (leftTrue * rightFalse) % mod +
                        (leftFalse * rightTrue) % mod) % mod;
            } else {
                ways = (ways + (leftTrue * rightTrue) % mod +
                        (rightFalse * leftFalse) % mod) % mod;
            }
        }
    }
    
    // Store the calculated result in dp to avoid recomputation.
    return dp[i][j][isTrue] = ways;
}

// Function to initiate the evaluation of the expression.
int evaluateExp(string &exp) {
    int n = exp.size();
    // Initialize the dynamic programming table with -1.
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    // Call the recursive function to evaluate the expression.
    return f(0, n - 1, 1, exp, dp);
}
