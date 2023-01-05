
#include <bits/stdc++.h>

using namespace std;



// Solution class to implement the function to print a square of size n
class Solution {
  public:
    // Function to print a square of size n
    void printSquare(int n) {
        // Iterate through the rows of the square
        for(int i=0; i<n; i++) {
            // Iterate through the columns of the square
            for(int j=0; j<n; j++) {
                // Print a star for each column in the row
                cout<<"* ";
            }
            // After printing all columns in the row, go to the next line
            cout<<"\n";
        }
    }
};



int main() {
    // Read in the number of test cases
    int t;
    cin >> t;

    // Iterate through the test cases
    while (t--) {
        // Read in the size of the square
        int n;
        cin >> n;

        // Create an object of the Solution class
        Solution ob;

        // Call the printSquare function on the object
        ob.printSquare(n);
    }
    return 0;
}

