#include<bits/stdc++.h>
using namespace std;

// We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it,
//  mat[i][j] gives us the number of chocolates. We have two friends ‘Alice’ and ‘Bob’.
//   initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1).
//    Both of them can move only to the cells below them in these three directions: to the bottom
//     cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).

// When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can
//  happen that they visit the same cell, in that case, the chocolates need to be considered only once.

// They cannot go out of the boundary of the given matrix, we need to return the maximum number of 
// chocolates that Bob and Alice can together collect.


// Pseudocode

/*
f(i, j1, j2) {
    if(j1<0 || j1>=m || j2<0 || j2>=m)
        return -1e9
    if(i==n-1) {
        if(j1==j2)
            return mat[i][j1]
        else
            return mat[i][j1] + mat[i][j2]
    }

    maxi = INT_MIN
    for(int di = -1; di<=1; di++){
        for(int dj = -1; dj<=1; dj++){

            if(j1==j2)
                ans = mat[i][j1] + f(i, j1+di, j2+dj)
            else
                ans = mat[i][j1] + mat[i][j2] + f(i, j1+di, j2+dj)
            
            maxi = max(maxi, ans)
        }
    }
    return maxi
}
*/

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    if(j1<0 || j1 >=m || j2<0 || j2>=m)
        return -1e9;
    
    if(i==n-1) {
        if(j1==j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    
    int maxi = INT_MIN;
    for(int di = -1; di <= 1; di++) {
        for(int dj = -1; dj<=1; dj++) {
            int ans;
            if(j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i+1, j1+di, j2+dj, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i+1, j1+di, j2+dj, n, m, grid, dp);
            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m, -1)));
    return maxChocoUtil(0, 0, m-1, n, m, grid, dp);
}

int main()
{
    vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
    return 0;
}