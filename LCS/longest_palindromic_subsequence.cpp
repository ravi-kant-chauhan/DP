#include<bits/stdc++.h>
using namespace std;

int solve(string & s1, string& s2, int n, int m, vector<vector<int>>& dp){
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int lcs(string & s1){
    int n = s1.length();
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    return solve(s1, s2, n, n, dp);
}

int main() {

  string s= "agcbcbca";
                                 
  cout<<"The Longest Palindromic Subsequence is "<<lcs(s);
}