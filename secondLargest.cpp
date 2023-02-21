//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	   sort(arr,arr+n);
	   for(int i=n-2;i>=0;i--){
	       if(arr[i]!=arr[n-1]){
	           return arr[i];
	       }
	   }
	    return -1;
	}
};




//second approach
// User function template for C++
class Solution{
public:	
	// Function returns the second largest element
	int print2largest(int arr[], int n) {
	    // Initialize max and max2 variables to track the largest and second largest element
	   int max=-1, max2=-1;
	   
	   // Loop through the array to find the largest element
	   for(int i=0;i<n;i++){
	       if(arr[i]>max){
	           max=arr[i];
	       }
	   }
	   
	   // Loop through the array again to find the second largest element
	   // The element must be smaller than the largest element, but larger than any other element
	     for(int i=0;i<n;i++){
	       if(arr[i]<max && arr[i]>max2){
	           max2=arr[i];
	       }
	}
	
	// Return the second largest element
	return max2;
	}
};
