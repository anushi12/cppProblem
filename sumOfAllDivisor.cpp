#include<bits/stdc++.h> 
using namespace std; 

// User function Template for C++
class Solution
{
public:
    // This function calculates the sum of all the divisors of a number N
    long long sumOfDivisors(int N)
    {
        long sum =0; // variable to store the sum of divisors
        // Iterate through all numbers from 1 to N
        for(long i=1;i<=N;i++){
            // If N is divisible by i, add i to the sum
            sum +=((N/i)*i);
        }
        // Return the sum
        return sum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
