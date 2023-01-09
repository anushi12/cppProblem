#include<bits/stdc++.h> 
using namespace std;

// Solution class definition
class Solution{
public:
    // function to count number of digits in N that evenly divide N
    int evenlyDivides(int N){
        // initialize counter to 0
        int cnt = 0;
        // store a copy of N
        int n = N;
        // while n is greater than 0
        while(n > 0) {
            // get the rightmost digit of n
            int digit = n % 10;
            // if the digit is not 0 and N is evenly divisible by the digit, increment the counter
            if(digit != 0 && N % digit == 0) cnt++;
            // divide n by 10 to remove the rightmost digit
            n /= 10;
        }
        // return the final count
        return cnt;
    }
};

// main function
int main() 
{ 
    // number of test cases
    int t;
    cin >> t;
    // for each test case
    while(t--)
    {
        // input N
        int N;
        cin >> N;
        // create an instance of the Solution class
        Solution ob;
        // print the number of digits in N that evenly divide N
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
