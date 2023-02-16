// Define a class Solution
class Solution {
public:
    // Define a method called print_divisors that takes an integer n as input and returns nothing
    void print_divisors(int n) {
        // Create an empty set of integers called s
        set<int> s;
        
        // Loop from 1 to the square root of n
        for(int i = 1; i * i <= n; i++) {
            // If i is a divisor of n, add i and n/i to the set s
            if(n % i == 0) {
                s.insert(i);
                s.insert(n/i);
            }
        }
        
        // Loop through the set s and print each element to the console
        for(auto it: s) {
            cout << it << " ";
        }
    }
};
