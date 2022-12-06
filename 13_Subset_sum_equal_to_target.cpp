#include<bits/stdc++.h>
using namespace std;

// Recursion

/*
f(int, target) {
    if(target==0) return true
    if(ind==0) return arr[ind]==target

    bool notTaken = f(ind-1, target)
    bool taken = false

    if(arr[ind]<=target)
        taken = f(ind-1, target-arr[ind])

    return notTaken|| taken
}
*/


// Memoization

/*
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp) {
    if(target==0)
        return true;

    if(ind == 0)
        return arr[0]==target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    
    bool notTaken = subsetSumUtil(ind-1, target, arr, dp);

    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumUtil(ind-1, target-arr[ind], arr, dp);
    
    return dp[ind][target] = notTaken||taken;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    return subsetSumUtil(n-1, k, arr, dp);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4}; 
    int k=10;
    int n = arr.size();

    if(subsetSumToK(n, k, arr))
        cout<<"Found";
    else
        cout<<"Not Found";
    return 0;
}

*/



// Tabulation

/*

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));

    for(int i = 0; i<n; i++) {
        dp[i][0] = true;
    }

    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 1; target<=k; target++) {
            bool notTaken = dp[ind-1][target];

            bool taken = false;
            if(arr[ind]<=target)
                taken = dp[ind-1][target-arr[ind]];
            
            dp[ind][target] = notTaken||taken;
        }
    }
    return dp[n-1][k];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k=10;
    int n = arr.size();

    if(subsetSumToK(n, k, arr))
        cout<<"Found";
    else
        cout<<"Not Found";
    return 0;
}
*/


bool subsetSumToK(int n, int k, vector<int> & arr) {
    vector<bool> prev(k+1, false);
    prev[0] = true;

    if(arr[0]<=k)
        prev[arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++) {
        vector<bool> cur(k+1, false);
        cur[0] = true;
        for(int target = 1; target<=k; target++) {
            bool notTaken = prev[target];

            bool taken = false;
            if(arr[ind]<=target)
                taken = prev[target-arr[ind]];
            
            cur[target] = notTaken||taken;
        }
        prev = cur;
    }
    return prev[k];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k=10;
    int n = arr.size();

    if(subsetSumToK(n, k, arr))
        cout<<"Found";
    else
        cout<<"Not Found";
    return 0;
}