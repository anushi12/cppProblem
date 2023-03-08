class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;  // initialize the range of possible eating speeds
        while (left < right) {  // binary search loop
            int mid = left + (right - left) / 2;  // calculate the midpoint of the range
            if (canEatAll(piles, h, mid)) {  // check if it's possible to eat all piles within h hours at speed k = mid
                right = mid;  // update the upper bound of the range
            } else {
                left = mid + 1;  // update the lower bound of the range
            }
        }
        return left;  // the minimum eating speed that can eat all piles within h hours is left
    }

    bool canEatAll(const vector<int>& piles, int h, int k) {
        int hours = 0;  // initialize the total hours needed to eat all piles
        for (int pile : piles) {
            hours += (pile + k - 1) / k;  // calculate the number of hours needed to eat one pile at speed k
        }
        return hours <= h;  // check if the total hours needed is less than or equal to h
    }
};
