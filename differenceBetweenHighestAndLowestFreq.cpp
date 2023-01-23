class Solution{
  public:
    int findDiff(int arr[], int n) {
        // unordered_map is a container that stores elements in no particular order
        unordered_map<int , int> mpp;
        // iterate through the array
        for(int i=0;i<n;i++){
            // add the element to the map and increment the count if it already exists
            mpp[arr[i]]++;
        }
         // initialize maxi and mini to the lowest and highest possible integer values
         int maxi = INT_MIN;
         int mini = INT_MAX;
         //iterate through the map
         for(auto it:mpp){
             //update maxi with maximum count value
             maxi = max(it.second,maxi);
             //update mini with minimum count value
             mini = min(it.second,mini);
         }
        
       return (maxi - mini); // return the difference between maxi and mini
    }
};
