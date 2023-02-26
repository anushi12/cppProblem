// User function template for C++
class Solution{
public:
    void pushZerosToEnd(int arr[], int n) {
        // Initialize left pointer to zero
        int l = 0; //left
        // Loop through the array
        for(int r=0; r<n; r++){
            // If the current element is not zero
            if(arr[r]!=0){
                // Swap the current element with the element at the left pointer
                swap(arr[l], arr[r]);
                // Increment the left pointer
                l++;
            }
        }
    }
};
