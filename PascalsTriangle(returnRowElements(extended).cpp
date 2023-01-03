// This function returns the row of the Pascal's Triangle given the row index
vector<int> getRow(int rowIndex) {
  // Declare variables for loop indices
  int i, j;

  // Declare a 2D vector to store the rows of the Pascal's Triangle
  vector<vector<int>> ans;

  // Loop through each row of the triangle
  for (i = 0; i <= rowIndex; i++) {
    // Create a vector to store the elements of the current row
    // Initialize it with 1s since the first and last elements of each row are always 1
    vector<int> row(i + 1, 1);

    // Loop through the elements of the current row, excluding the first and last elements
    for (j = 1; j < i; j++) {
      // Calculate the element at the current index using the elements of the previous row
      row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
    }

    // Add the current row to the triangle
    ans.push_back(row);
  }

  // Return the row with the specified index
  return ans[rowIndex];
}
