//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long reversedBits(long long X) {
        // Initialize variables to store the result and the current index
        long long ans = 0;
        int index = 31;

        // Iterate through the bits of X
        while (X != 0) {
            // If the current least significant bit is 1, add 2^index to the result
            if (X % 2 == 1) {
                ans += pow(2, index);
            }
            // Decrement the index and move on to the next bit
            index--;
            X /= 2;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin >> X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
