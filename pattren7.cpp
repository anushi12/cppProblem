//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // This loop is for printing each row of the triangle
        for(int i=0;i<n;i++){
            // This loop is for printing the spaces before the row
            for( int j=0;j<n-i-1;j++){
                cout<<" ";
            }
            // This loop is for printing the asterisks in the row
            for( int j=0;j<2*i+1;j++){
                cout<<"*";
            } 
            // This loop is for printing the spaces after the row
            for( int j = 0;j<n-i-1;j++){
                cout<<" ";
            }
            // Move to the next line
            cout<<"\n";
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends
