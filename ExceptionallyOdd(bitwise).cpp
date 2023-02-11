//User function template for C++

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        // code here
         int ans=0;
        for(int i=0; i<n; i++){
          //XOR of same number is 0
            ans = ans^arr[i];
        }
        return ans;
            
    }
};
