class Solution {
public:

// Function to perform depth-first search
int dfs(vector<int>adj[],vector<bool> &hasApple,int node, int root){
  // Initialize distance variable
  int dist=0;
  // Iterate through all adjacent nodes
  for(auto i: adj[node]){
    // Check if the node is not the parent node
    if(i!=root){
      // Recursively call dfs on the adjacent node
      int temp=dfs(adj, hasApple, i, node);
      // If the adjacent node has an apple, add distance to the total distance
      if(hasApple[i]){
        dist+=(2+temp);
        // Mark current node as having an apple
        hasApple[node]=true;
      }
    }
  } 
  // Return total distance
  return dist;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
  // Initialize the adjacency list
  vector<int>adj[n];
  // Build the adjacency list
  for(int i=0;i<edges.size();i++){
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }
  // Call dfs function starting at node 0
  // and return the total distance
  return dfs(adj,hasApple,0,0);
}

};
