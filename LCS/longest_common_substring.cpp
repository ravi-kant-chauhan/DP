#include<bits/stdc++.h>
using namespace std;


// Tabulation

int solve(string& s1, string& s2, int n, int m, vector<vector<int>> & dp){
    int ans= 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

int lcs(string & s1, string & s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    return solve(s1, s2, n, m, dp);
}

int main() {

  string s1= "ablsdkfjalcjklack";
  string s2= "acjkp";
                                 
  cout<<"The Length of Longest Common Substring is "<<lcs(s1,s2);
}