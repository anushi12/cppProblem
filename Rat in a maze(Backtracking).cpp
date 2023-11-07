#include<bits/stdc++.h>
void solve(int i, int j, vector < vector < int >> & mat, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    //upward
    if(i-1>=0 && mat[i-1][j] == 1 && !vis[i-1][j]){
       vis[i][j] = 1;
       solve(i-1,j,mat,n,ans,move + 'U', vis);
       vis[i][j] = 0;
    }
    //downward
     if(i+1<n && mat[i+1][j] == 1 && !vis[i+1][j]){
       vis[i][j] = 1;
       solve(i+1,j,mat,n,ans,move + 'D', vis);
       vis[i][j] = 0;
    }

    //left
      if(j-1>=0 && mat[i][j-1] == 1 && !vis[i][j-1]){
       vis[i][j] = 1;
       solve(i,j-1,mat,n,ans,move + 'L', vis);
       vis[i][j] = 0;
    }

    //right
     if(j+1<n && mat[i][j+1] == 1 && !vis[i][j+1]){
       vis[i][j] = 1;
       solve(i,j+1,mat,n,ans,move + 'R', vis);
       vis[i][j] = 0;
    }
}

vector<string> ratMaze(vector<vector<int>> &mat) {
   vector<string>ans;
   int n = mat.size();
   vector<vector<int>>vis(n, vector<int>(n,0));
   if(mat[0][0]==1) solve(0,0,mat,n,ans,"",vis);
   return ans;
}
