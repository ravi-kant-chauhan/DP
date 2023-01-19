#include<bits/stdc++.h>
using namespace std;

string solve(string & s1, string& s2, int n, int m, vector<vector<int>>& dp){
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    string s = "";
    int i = n, j = m;
    while(i>0 && j>0) {
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if(dp[i][j-1]>dp[i-1][j]){
                s.push_back(s2[j-1]);
                j--;
            }
            else {
                s.push_back(s1[i-1]);
                i--;
            }
        }
    }

    while(i>0){
        s.push_back(s1[i-1]);
        i--;
    }

    while(j>0){
        s.push_back(s2[j-1]);
        j--;
    }

    reverse(s.begin(), s.end());

    return s;
}

string lcs(string & s1, string & s2){
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    return solve(s1, s2, n, m, dp);
}

int main() {

  string s1= "AGBTAB";
  string s2= "GXTXAYB";
                                 
  cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
}