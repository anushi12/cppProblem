class Solution
{
    public:
    int select(int arr[], int i)
    {
        //code here
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       //traversing the array
       for(int i=0;i<n-1;i++){
         
         //asumming the first index to be minimum
           int minIndex = i;
         // traverse the array from i+1 to check if there is minimum element present then the minimum considered 
        for(int j=i+1;j<n;j++){
          
          // if minimum is present then the minIndex
        if(arr[j]<arr[minIndex])
          
          // update the minIndex
        minIndex=j;
       }
         
        // swap the minIndex with the array i
       swap(arr[minIndex],arr[i]);
       }
    }
};
