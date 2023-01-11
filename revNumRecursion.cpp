#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void print(int i,int n){
    //base case
      if(i>n) return;
    //recursive call to the function with i+1
      print(i+1,n);
    //printing the value of i
      cout<<i<<" ";
      
  }
    void printNos(int N) {
        // code here
    //Calling the helper function
        print(1,N);
    }
};
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}
