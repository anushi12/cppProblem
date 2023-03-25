// The function superiorElements takes a vector of integers as input, and returns a new vector of integers.
vector<int> superiorElements(vector<int>& a) {
    
    // Declare an empty vector to store the result.
    vector<int> ans;
    
    // Initialize the maximum value as the smallest possible integer value.
    int maxi = INT_MIN;
    
    // Get the size of the input vector.
    int n = a.size();
    
    // Traverse the input vector from the end.
    for(int i = n-1; i >= 0; i--){
        
        // If the current element is greater than the maximum value found so far,
        // then add it to the result vector.
        if(a[i] > maxi){
            ans.push_back(a[i]);
        }
        
        // Update the maximum value with the current element.
        maxi = max(maxi, a[i]);
    }
    
    // Sort the result vector in ascending order.
    sort(ans.begin(), ans.end());
    
    // Return the result vector.
    return ans;
}
