#include<bits/stdc++.h>
using namespace std;


// Given two values M and N, which represent a matrix[M][N]. We need to find the total unique paths from
//  the top-left cell (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).

// At any cell we are allowed to move in only two directions:- bottom and right.

// Memoization

/*
int countWaysUtil(int i, int j, vector<vector<int>>& dp) {
    if(i==0 || j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = countWaysUtil(i-1, j, dp);
    int left = countWaysUtil(i, j-1, dp);

    return dp[i][j] = up+left;
}

int countWays(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countWaysUtil(m-1, n-1, dp);
}

int main()
{
    int m = 3;
    int n = 2;
    
    cout<<countWays(m, n);
    return 0;
}

*/


// Tabulation

/*
int countWaysUtil(int m, int n, vector<vector<int>>& dp) {
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i==0 && j==0){
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

    return dp[m-1][n-1];
}

int countWays(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countWaysUtil(m, n, dp);
}

int main()
{
    int m = 3;
    int n = 2;
    
    cout<<countWays(m, n);
    return 0;
}
*/

int countWays(int m, int n){
    vector<int> prev(n, 0);
    for(int i = 0; i<m; i++){
        vector<int> temp(n, 0);
        for(int j=0; j<n; j++){
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

int main()
{
    int m = 3;
    int n = 2;
    
    cout<<countWays(m, n);
    return 0;
}