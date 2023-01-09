//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // Initialize sum to 0
        int sum=0;
        // Make a copy of n to be used in loop
        int dup=n;
        // While loop to sum the cube of each digit of n
        while(dup>0){
            // Get the last digit of n
            int last=dup%10;
            // Add the cube of the digit to the sum
            sum =(last*last*last)+sum;
            // Divide n by 10 to get rid of the last digit
            dup /=10;
        }
        // If the sum equals n, return "Yes"
        if(sum == n)
        return "Yes";
        // Otherwise, return "No"
        else
        return "No";      
    }
};

//{ Driver Code Starts.
int main() {
    // Read in the number of test cases
    int t;
    cin >> t;
    // For each test case
    while (t--) {
        // Read in the number to be checked
        int n;
        cin >> n;
        // Create a Solution object
        Solution ob;
        // Call the armstrongNumber function on n and print the result
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
