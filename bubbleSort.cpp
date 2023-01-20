class Solution
{
    public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // outer loop to iterate through the entire array
        for(int i=0; i<n; i++){
            // inner loop to compare and swap adjacent elements
            for(int j=0;j<n-1;j++){
                // if current element is greater than the next element, swap them
                if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
            }
        }
    }
};
