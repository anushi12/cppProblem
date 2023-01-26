// This class "Solution" defines a function "get" that takes in two integer arguments, "a" and "b"
// The function returns a pair of integers, where the values of "a" and "b" have been swapped

class Solution{
public:
// The function takes in two integers, "a" and "b"
pair<int, int> get(int a, int b){
// Create a pair "p" to store the values of "a" and "b" after swapping
pair<int,int>p;
// Use bitwise XOR operator to swap the values of "a" and "b"
a = a^b;
b = a^b;
a = a^b;
// Assign the swapped values of "a" and "b" to the pair "p"
 p.first=a;
 p.second=b;
 // Return the pair "p"
 return p;
}
};
