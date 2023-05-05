/*better solution*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       map<int,int> mpp; // Initialize a map to store the count of each element
       vector<int> res; // Initialize a vector to store the majority elements
       for(int i=0; i<nums.size(); i++){ // Loop through each element in the input vector
           mpp[nums[i]]++; // Increment the count of the current element in the map
       } 
       for(auto it : mpp){ // Loop through each element in the map
           if(it.second > (nums.size() / 3)) // If the count of the element is more than a third of the total elements
               res.push_back(it.first); // Add the element to the majority element vector
       }
       return res; // Return the majority element vector
    }
};


// OPTIMIZED SOLUTION(MOORE'S VOTING ALGORITHM)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 =-1, ele2 =-2; // Initialize two variables to store the two most frequent elements
        int cnt1=0, cnt2=0; // Initialize two variables to store the counts of the two most frequent elements
        for(int i=0; i<nums.size(); i++){ // Loop through each element in the input vector
           if(ele1 == nums[i]){ // If the current element is equal to the first most frequent element
               cnt1++; // Increment the count of the first most frequent element
           }
           else if(ele2 == nums[i]){ // If the current element is equal to the second most frequent element
               cnt2++; // Increment the count of the second most frequent element
           }
           else if(cnt1 == 0){ // If the count of the first most frequent element is zero
               ele1 = nums[i]; // Set the first most frequent element to the current element
               cnt1++; // Increment the count of the first most frequent element
           }
           else if(cnt2 == 0){ // If the count of the second most frequent element is zero
               ele2 = nums[i]; // Set the second most frequent element to the current element
               cnt2++; // Increment the count of the second most frequent element
           }
           else{ // If the current element is not equal to either of the two most frequent elements
               cnt1--; // Decrement the count of the first most frequent element
               cnt2--; // Decrement the count of the second most frequent element
           }
        }

        vector<int>res; // Initialize a vector to store the majority elements
        cnt1=0; // Reset the count of the first most frequent element
        cnt2=0; // Reset the count of the second most frequent element
        for(auto it:nums){ // Loop through each element in the input vector
            if(ele1 == it) cnt1++; // If the current element is equal to the first most frequent element, increment its count
            else if(ele2 == it) cnt2++; // If the current element is equal to the second most frequent element, increment its count
        }
        if(cnt1> nums.size()/3) res.push_back(ele1); // If the count of the first most frequent element is more than n/3, add it to the result vector
        if(cnt2> nums.size()/3) res.push_back(ele2); // If the count of the second most frequent element is more than n/3, add it to the result vector
        return res; // Return the result vector
    }
};
