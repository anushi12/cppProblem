// This function generates a single row of Pascal's Triangle, given its row number
vector<int> generateRows(int row){
    long long ans = 1; // Initialize a variable to store the current value in the row, starting at 1
    vector<int> triangle; // Initialize an empty vector to store the row
    triangle.push_back(1); // The first element in each row is always 1
    for(int col=1; col<row; col++){ // Loop through each column in the row
        ans = ans * (row - col); // Calculate the current value in the row
        ans = ans / col; // Calculate the current value in the row
        triangle.push_back(ans); // Add the current value to the row
    }
    return triangle; // Return the completed row
}

// This function generates the entire Pascal's Triangle up to a given row number
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> res; // Initialize an empty vector to store the triangle
    for(int i=1; i<=N; i++){ // Loop through each row number up to the given number
        res.push_back(generateRows(i)); // Generate the row and add it to the triangle vector
    }
    return res; // Return the completed triangle
}
