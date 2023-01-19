#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string & s, int i, int j){
    if(i>=j) return true;

    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}


// int solve(string & s, vector<vector<int>>& dp, int i, int j){
//     if(i>=j) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];

//     if(isPalindrome(s, i, j)) return 0;

//     int ans = INT_MAX;
//     for(int k = i; k<j; k++) {
//         int temp = solve(s, dp, i, k) + solve(s, dp, k+1, j) + 1;
//         ans = min(temp, ans);
//     }

//     return dp[i][j] = ans;
// }


//  Optimized

int solve(string & s, vector<vector<int>>& dp, int i, int j){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(isPalindrome(s, i, j)) return 0;

    int ans = INT_MAX;
    for(int k = i; k<j; k++) {
        int left, right;
        if(dp[i][k]!=-1)
            left = dp[i][k];
        else{
            left = solve(s, dp, i, k);
            dp[i][k] = left;
        }
        
        if(dp[k+1][j]!=-1)
            right = dp[k+1][j];
        else{
            right = solve(s, dp, k+1, j);
            dp[k+1][j] = right;
        }

        int temp = left + right + 1;
        ans = min(temp, ans);
    }

    return dp[i][j] = ans;
}


int palindromePartioning(string & s, int n){
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return solve(s, dp, 0, n-1);
}

int main()
{
    string s = "asbsbacadb";

    cout<<"The maximum partioning to make it palindromw is "<<palindromePartioning(s, s.length());
    return 0;
}