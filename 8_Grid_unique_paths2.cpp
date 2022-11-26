#include<bits/stdc++.h>
using namespace std;

// We are given an “N*M” Maze. The maze contains some obstacles. A cell is ‘blockage’ in the maze 
// if its value is -1. 0 represents non-blockage. There is no path possible through a blocked cell.

// We need to count the total number of unique paths from the top-left corner of the maze to the
//  bottom-right corner. At every cell, we can move either down or towards the right.



// Memoization


/*
int mazeObstaclesUtil(int i, int j, vector<vector<int>>& maze, vector<vector<int>>& dp) {
    if(i>0 && j>0 && maze[i][j]==-1) return 0;
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = mazeObstaclesUtil(i-1, j, maze, dp);
    int left = mazeObstaclesUtil(i, j-1, maze, dp);

    return dp[i][j] = up+left;
}


int mazeObstacles(int n, int m, vector<vector<int>> & maze) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return mazeObstaclesUtil(n-1, m-1, maze, dp);
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}
*/



// Tabulation

/*

int mazeObstaclesUtil(int n, int m, vector<vector<int>>& maze, vector<vector<int>>& dp) {
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) {
            if(i>0 && j>0 && maze[i][j]==-1) {
                dp[i][j] = 0;
                continue;
            }
            if(i==0 && j==0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i>0)
                up = dp[i-1][j];
            if(j>0)
                left = dp[i][j-1];
            
            dp[i][j] = up+left;
        }
    }
    return dp[n-1][m-1];
}

int mazeObstacles(int n, int m, vector<vector<int>> & maze) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return mazeObstaclesUtil(n, m, maze, dp);
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}

*/

// Optimized


int mazeObstacles(int n, int m, vector<vector<int>>& maze) {
    vector<int> prev(m, 0);
    for(int i = 0; i<n; i++){
        vector<int> temp(m, 0);
        for(int j = 0; j<m; j++){
            if(i>0 && j>0 && maze[i][j]==-1){
            temp[j] = 0;
            continue;
            }
            if(i==0 && j==0){
                temp[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
        
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n-1];
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}