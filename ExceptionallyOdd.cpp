class Solution {
public:
    int getOddOccurrence(int arr[], int n) {
        // Initialize a map to store the frequency of each number in the array
        map<int, int> mpp;

        // Loop through the array to count the frequency of each number
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }

        // Loop through the map to find the number with an odd frequency
        for (auto it : mpp) {
            if (it.second % 2 != 0) {
                // If a number with an odd frequency is found, return it
                return it.first;
            }
        }
    }
};
