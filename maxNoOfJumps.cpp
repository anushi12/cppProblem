//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // If the first element of the array is 0 and there are more than 1 elements in the array, return -1
        // (since it is not possible to jump forward from the first element if it is 0)
        if(arr[0]==0 && n>1) return -1;
        // If there is only 1 element in the array, return 0 (since no jump is required)
        if(n==1) return 0;
        // Initialize the maximum reachable index to 0 and the number of jumps to 0
        int far = 0;
        int jump = 0;
        // Initialize the current index to 0
        int curr = 0;
        // Iterate through the array
        for(int i=0; i<n-1; i++){
            // Update the maximum reachable index by taking the maximum of the current maximum reachable index and the current index plus the element at the current index
            far = max(far, i+arr[i]);
            // If the current index is equal to the current maximum reachable index, increment the number of jumps and update the current index to the new maximum reachable index
            if(i==curr){
                jump++;
                curr=far;
            }
        }
        // If the current index is less than the last index of the array, return -1 (since it is not possible to reach the end of the array)
        if(curr<n-1) return -1;
        // Return the number of jumps
        return jump;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
