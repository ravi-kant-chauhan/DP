#include<bits/stdc++.h>
using namespace std;

// Recursive code
/*
f(ind, arr[]) {
    if(ind==0) return arr[ind]
    if(ind<0) return 0

    pick = arr[ind]+f(ind-2, arr)
    notPick = 0 + f(ind-1, arr)

    return max(pick, nonPick)
}
*/


// Memoization

/*
int solveUtil(int ind, vector<int>& arr, vector<int>& dp)
{
    if(dp[ind]!=-1) return dp[ind];

    if(ind==0) return arr[ind];
    if(ind<0) return 0;

    int pick = arr[ind]+solveUtil(ind-2, arr, dp);
    int nonPick = 0 + solveUtil(ind-1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n, -1);
    return solveUtil(n-1, arr, dp);
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout<<solve(n, arr);
    return 0;
}

*/


// Tabulation

/*
int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    dp[0] = arr[0];

    for(int i = 1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0 + dp[i-1];

        dp[i] = max(pick, nonPick);
    }

    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n, -1);
    return solveUtil(n-1, arr, dp);
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout<<solve(n, arr);
    return 0;
}

*/


// Optimized

int solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 = 0;

    for(int i = 1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;

        int curr_i = max(pick, nonPick);
        prev2 = prev;
        prev = curr_i;
    }
    return prev;
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout<<solve(n, arr);
    return 0;
}