#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	// Write your code here.
	int m = arr.size();
	
	// Sorting the input intervals based on their start times
	sort(arr.begin(),arr.end());
	
	vector<vector<int>> ans;
	
	for(int i = 0; i < m; i++){
		// Extracting the start and end times of the current interval
		int start = arr[i][0];
	    int end = arr[i][1];

		// Checking if the 'ans' vector is not empty and if the current interval overlaps with the last interval in 'ans'
		if(!ans.empty() && end <= ans.back()[1]){
			continue; // Skip to the next iteration if there is an overlap
		}
		
		// Merge overlapping intervals
		for(int j = i + 1; j < m; j++){
			if(arr[j][0] <= end){
				// Update the end time if the current interval overlaps with the previous interval
				end = max(end, arr[j][1]);
			} else {
				break; // Stop merging intervals if there is no overlap
			}
		}
		
		// Add the merged interval to the 'ans' vector
		ans.push_back({start, end});
	}
	
	return ans;
}
