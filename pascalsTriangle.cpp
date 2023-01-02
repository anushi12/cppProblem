class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       // Initialize the vector of vectors with numRows number of rows
       vector<vector<int>>ans(numRows);

       // Iterate through each row
       for(int i=0; i<numRows; i++){
          // Resize the inner vector to have i+1 number of elements
          ans[i].resize(i+1);
          // Set the first and last element of the inner vector to 1
          ans[i][0] = ans[i][i] =1;
          // Set the elements in between the first and last element to the sum of the elements above it
          for(int j=1;j<i;j++)
             ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
       }
       // Return the completed vector of vectors
       return ans;
    }
};
