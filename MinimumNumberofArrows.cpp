class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Initialize last to the first point's end coordinate, and cnt to 1
        int last= points[0][1];
        int cnt=1;

        // Sort the points by start coordinate
        sort(points.begin(),points.end());

        // Iterate through each point
        for(int i=0;i<points.size();i++){
            // If the current point's start coordinate is after the last point's end coordinate, increment cnt and update last to the current point's end coordinate
            if(points[i][0]>last){
            cnt++;
            last = points[i][1];
            }
            // Otherwise, update last to the minimum of last and the current point's end coordinate
            else last = min(last, points[i][1]);
        }
       // Return the total number of arrows needed
       return cnt; 
    }
};
