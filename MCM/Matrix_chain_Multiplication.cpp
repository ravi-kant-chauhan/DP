#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, vector<vector<int>> & dp, int i, int j){
    if(i>=j)
        return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];

    int ans = INT_MAX;

    for(int k = i; k<j; k++){
        int temp = solve(arr, dp, i, k) + solve(arr, dp, k+1, j) + arr[i-1]*arr[k]*arr[j];

        if(temp<ans)
            ans = temp;
    }
    return dp[i][j] = ans;
}


int matrixMultiplication(vector<int> & arr, int n){
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return solve(arr, dp, 1, n-1);
}

int main() {
	
	vector<int> arr = {10, 20, 30, 40, 50};
	
	int n = arr.size();
	
	cout<<"The minimum number of operations is "<<matrixMultiplication(arr,n);
	
	return 0;
}