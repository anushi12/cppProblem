#include<bits/stdc++.h>

// Function to count subarrays with sum equal to b
int subarraysWithSumK(vector < int > a, int b) {
    // Initialize variables
    int xr = 0; // Stores the XOR of elements in the subarray
    map<int,int>mpp; // Map to store XOR values and their frequency
    mpp[xr]++; // Initialize the map with {0, 1} since XOR of an empty subarray is 0

    int cnt = 0; // Counter for the number of subarrays with sum b

    // Iterate through the array
    for(int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i]; // Calculate XOR of elements up to the current index

        int x = xr ^ b; // Calculate the XOR value that should be present in the map

        cnt += mpp[x]; // Add the frequency of the XOR value to the counter

        mpp[xr]++; // Increment the frequency of the current XOR value in the map
    }

    return cnt; // Return the total count of subarrays with sum equal to b
}
