class Solution {
public:
    bool check(vector<int>& nums) {
        // create a new vector with the same size as the input vector
        vector<int> vec(nums.size());
        // variable to keep track of how many times a number is out of order
        int cnt = 0;
        // iterate through the input vector
        for (int i = 0; i < nums.size(); i++) {
            // if the current number is greater than the next number (wrapping around to the beginning if necessary)
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                // increment the out of order count
                cnt++;
            }
        }
        // return true if the number of out of order pairs is less than or equal to 1, and false otherwise
        return (cnt <= 1);
    }
};
