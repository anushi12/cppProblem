//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    public:  
    // Function to calculate GCD of two numbers
    int gdc(int A, int B){
        // If B is 0, return A as GCD
        if(B==0) {
            return A;
        }
        
        // Recursively calculate GCD using Euclidean Algorithm
        return gdc(B,A%B);
    }

    // Function to calculate LCM and GCD of two numbers
    vector<long long> lcmAndGcd(long long A , long long B) {
        // Vector to store the result (LCM and GCD)
        vector<long long int>ans;

        // Calculate GCD of A and B
        long long int a = gdc(A,B);
        // Calculate LCM of A and B using the formula LCM = (A*B)/GCD
        long long int b = (A*B)/gdc(A,B);
        // Store LCM and GCD in the result vector
        ans.push_back(b);
        ans.push_back(a);
       
        // Return the result vector
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        // Read values of A and B
        cin>>A>>B;

        // Create an object of the Solution class
        Solution ob;
        // Call the lcmAndGcd function of the Solution class and store the result in a vector
        vector<long long> ans = ob.lcmAndGcd(A,B);
        // Print the LCM and GCD values stored in the vector
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
