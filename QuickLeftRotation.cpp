// Define a class called Solution
class Solution{
	
	// Declare a public method called leftRotate that takes an integer array called arr, an integer called k, and an integer called n as input parameters
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Declare a new vector called vec with size n
	   vector<int>vec(n);
	   
	   // Iterate over the indices of the original array arr
	   for(int i=0;i<n;i++){
	      // Assign the value of the original array at index (i+k)%n to the corresponding index in the new vector vec
	      vec[i]=arr[(i+k)%n];
	   }
	   
	   // Iterate over the indices of the original array arr again
	   for(int i=0;i<n;i++){
	      // Copy the elements from the new vector vec back into the original array arr
	      arr[i]=vec[i];
	   }
	
	} 
		 

};
