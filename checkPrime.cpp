class Solution
{
public:
// This function checks whether a given integer is prime.
// It takes an integer n as input and returns true if n is prime, false otherwise.
bool isPrime(int n){
// Iterate through all possible divisors up to the square root of n.
for(int i=2; i*i<=n; i++){
// If n is divisible by i, then it is not prime.
if(n%i==0){
return false;
}
}
// If no divisors are found, then n is prime.
return true;
}
  
  // This function generates a vector of all prime numbers between 2 and N.
// It takes an integer N as input and returns a vector of all primes between 2 and N.
vector<int> sieveOfEratosthenes(int N)
{
    // Initialize an empty vector to store the prime numbers.
    vector<int> ans;
    
    // Iterate through all numbers from 2 to N.
    for(int i=2; i<=N; i++){
        // Check if i is prime using the isPrime function.
        if(isPrime(i)){
            // If i is prime, add it to the ans vector.
            ans.push_back(i);
        }
    }
    
    // Return the ans vector containing all prime numbers between 2 and N.
    return ans;
}
};
