class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // Starting from the rightmost digit, add k to the corresponding digits of num
        // If the sum is greater than or equal to 10, set k to the carry-over value and
        // update the current digit of num accordingly.
        for(int i = num.size()-1; i >= 0; i--){
            num[i] += k; // Add k to the current digit of num
            k = num[i] / 10; // Compute the carry-over value
            num[i] %= 10; // Update the current digit of num
        }
        
        // If there is any carry-over value remaining, insert it at the beginning of num
        while(k > 0){
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        
        // Return the updated num vector
        return num;
    }
};
