
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  // Declare a variable to count the number of times "GFG" has been printed
  int cnt=0;
    void printGfg(int N) {
       // Base case to end the recursion
       if(cnt==N) return;
       // Print "GFG"
       cout<<"GFG"<<" ";
       // Increment the count
       cnt++;
       // Call the function again
       printGfg(N);
    }
};


/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    // Loop for each testcase
    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printGfg(N);
        cout << "\n";
    }
    return 0;
}

