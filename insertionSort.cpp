class Solution
{
    public:
    // Insert function is not being used in this code
    void insert(int arr[], int i)
    {
        // This function is not used in this code
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
     
       // outer loop starts at index 1 (second element) and runs until n
       for (int i=1; i<n;i++){
           // store current element in temp variable
           int temp = arr[i];
           int j= i-1;
           // inner loop starts at the previous index and runs until j is greater than or equal to 0
           for(;j>=0;j--){
               // if the previous element is greater than the current element, move the previous element to the next index
               if(arr[j]>temp)
               arr[j+1] = arr[j];
               // if the previous element is less than or equal to the current element, break the loop
               else
               break;
           }
           // insert the current element in its correct position
            arr[j+1] = temp;
       }
      
    }
};
