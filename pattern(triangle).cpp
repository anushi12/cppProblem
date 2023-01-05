
#include <bits/stdc++.h>

using namespace std;



// Solution class to implement the function to print a triangle of size n
class Solution {
public:
// Function to print a triangle of size n
void printTriangle(int n) {
// Iterate through the rows of the triangle
for(int i=0; i<n; i++) {
// Iterate through the columns of the triangle
for(int j=0; j<=i; j++) {
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

Copy code
// Iterate through the test cases
while (t--) {
    // Read in the size of the triangle
    int n;
    cin >> n;

    // Create an object of the Solution class
    Solution ob;

    // Call the printTriangle function on the object
    ob.printTriangle(n);
}
return 0;
}
