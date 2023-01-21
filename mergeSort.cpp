class Solution
{
    public:
    // This function is used to merge two sorted arrays (firsthalf and secondhalf) into the original array (arr)
    void merge(int arr[], int s, int mid, int e)
    {
        // Calculate the length of the first and second halves of the original array
        int len1 = mid-s+1;
        int len2 = e - mid;

        // Create two new arrays to store the first and second halves of the original array
        int*firsthalf = new int[len1];
        int*secondhalf = new int[len2];

        // Copy the elements of the first half of the original array into the firsthalf array
        int mainArrayIndex = s;
        for(int i=0;i<len1;i++){
            firsthalf[i] =arr[ mainArrayIndex++];
        }

        // Copy the elements of the second half of the original array into the secondhalf array
        mainArrayIndex =mid+1;
        for(int i=0;i<len2;i++){
            secondhalf[i] =arr[ mainArrayIndex++];
        }

        // Initialize indices for the firsthalf, secondhalf, and original arrays
        int index1=0;
        int index2=0;
        mainArrayIndex =s;

        // Compare elements from the firsthalf and secondhalf arrays and insert the smaller element into the original array
        while(index1<len1 && index2<len2){
            if(firsthalf[index1]<secondhalf[index2]){
                arr[mainArrayIndex++] = firsthalf[index1++];
            }
            else{ arr[mainArrayIndex++] = secondhalf[index2++];}
        }

        // Insert any remaining elements from the firsthalf array into the original array
        while(index1<len1){
            arr[mainArrayIndex++] = firsthalf[index1++];
        }

        // Insert any remaining elements from the secondhalf array into the original array
        while(index2<len2){
            arr[mainArrayIndex++] = secondhalf[index2++];
        }

        // Deallocate memory for the firsthalf and secondhalf arrays
        delete []firsthalf;
        delete []secondhalf;
    }
    
    public:
    // This function is used to sort an array using the merge sort algorithm
    void mergeSort(int arr[], int s, int e)
    {
        // Base case: if the start index is greater than or equal to the end index, return as the array is already sorted
        if(s>=e){
            return;
        }
        // Calculate the middle index of the array
        int mid =(s+e)/2;

        // Recursively sort the left half of the array
        mergeSort(arr,s,mid);

        // Recursively sort the right half of the array
        mergeSort(arr,mid+1,e);

        // Merge the two sorted halves of the array
        merge(arr,s,mid,e);
    }
};
