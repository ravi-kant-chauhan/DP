#include<bits/stdc++.h>
using namespace std;

int solve(string& s1, string &s2, int n, int m, vector<vector<int>>& dp) {
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int lcs(string& s1, string &s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    return n+m-solve(s1, s2, n, m, dp);
}

int main() {

  string s1= "AGGTAB";
  string s2= "GXTXAYB";
                                 
  cout<<"The length of shortest Common SuperSubsequence is "<<lcs(s1,s2);
}