#include<bits/stdc++.h>
using namespace std;

// Check if s1 is a subsequence of s2 or vice versa

bool solve(string & s1, string& s2, int n, int m, vector<vector<int>>& dp){
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return (dp[n][m] == min(n, m));
}

bool lcs(string & s1, string & s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    return solve(s1, s2, n, m, dp);
}

int main() {

  string s1= "adb";
  string s2= "dcakddb";
                                 
  if(lcs(s1,s2)){
    cout<<"Yes";
  }
  else
    cout<<"No";
}