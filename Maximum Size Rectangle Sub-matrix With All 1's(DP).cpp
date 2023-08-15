#include<bits/stdc++.h>

// Function to calculate the largest rectangle area given a histogram
int largestRectangleArea(vector<int>& histo) {
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

// Function to calculate the maximal area of a submatrix of all 1s
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>>& mat, int n, int m) {
    int maxArea = 0;
    vector<int> height(m, 0); // To store the histogram of heights
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1)
                height[j]++; // Increase the height if the cell value is 1
            else
                height[j] = 0; // Reset height if the cell value is 0
        }
        
        // Calculate the largest rectangle area using the histogram of heights
        int area = largestRectangleArea(height);
        maxArea = max(area, maxArea); // Update maxArea if a larger area is found
    }
    
    return maxArea; // Return the maximal area of the submatrix of all 1s
}

int main() {
    // Your code to take inputs and call the maximalAreaOfSubMatrixOfAll1 function
    // ...

    return 0;
}
