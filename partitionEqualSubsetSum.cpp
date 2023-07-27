bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1,0) , cur(k+1,0);
    
    prev[0] = cur[0] = true;
    if(arr[0]<=k) prev[arr[0]] = true;

    for(int ind = 1;ind<=n-1;ind++){
        for(int target = 1; target <= k; target ++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target) take = prev[target - arr[ind]];

        cur[target] = take|notTake;
        }
        prev = cur;
    }
    return prev[k];
}



bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int totSum = 0;
	for(int i = 0;i<n;i++) totSum += arr[i];
	if(totSum % 2) return false;
	int target = totSum/2;

	return subsetSumToK(n,target,arr);
	
}
