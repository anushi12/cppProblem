class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // Add an extra 0 at the beginning and the end of the flowerbed to avoid edge cases
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        // Loop through each element in the flowerbed, except the first and last elements
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            // Check if the current element and its neighbors are all 0, indicating an empty space to plant a flower
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                // If an empty space is found, decrement the number of flowers to be planted and skip the next element since it is adjacent to the current empty space
                n--;
                i++;
            }
        }

        // Return true if all flowers can be planted, false otherwise
        return n <= 0;
    }
};
