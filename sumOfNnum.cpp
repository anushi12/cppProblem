//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // variable to store the sum of the series
    long long sum =0;
   
    // function to find the sum of the series
    long long sumOfSeries(long long N) {
        // code here
        // formula for sum of series is (N*(N+1))/2
        sum = N*(N+1)/2;
        // return the square of the sum
        return sum*sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    // number of test cases
    cin >> t;
    while (t--) {
        long long N;
        // input N
        cin >> N;
        Solution ob;
        // call the function to find the sum of the series
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends
