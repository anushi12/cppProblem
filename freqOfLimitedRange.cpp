class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // Declare an unordered_map to store the frequency count of all elements in the input array
        unordered_map<int,int> mpp;
        // Iterate through the input array and for each element, increment the value stored in the unordered_map at the key of that element
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        // Initialize a variable to keep track of the current index in the input array
        int j=0;
        // Iterate through all elements from 1 to N
        for(int i=1;i<=N;i++){
            // Check if the current element is present in the unordered_map
            if(mpp.find(i)!=mpp.end())
            // If present, assign the frequency count of that element from the unordered_map to the corresponding position in the input array
             arr[j++]=mpp[i];
            //If not present, assign 0 to the corresponding position in the input array
             else
             arr[j++]=0;
        }
    }
};
