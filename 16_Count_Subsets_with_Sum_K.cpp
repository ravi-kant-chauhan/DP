#include <bits/stdc++.h>
using namespace std;

// We are given an array ‘ARR’ with N positive integers and an integer K.
//  We need to find the number of subsets whose sum is equal to K.



// Memoization


/*
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return 1;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}

*/




// Tabulation


/*

int findWays(vector<int> &num, int k){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
    
    if(num[0]<=k)
        dp[0][num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= notTaken + taken;
        }
    }
    
    return dp[n-1][k];
    
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}

*/


// Optimized

int findWays(vector<int> &num, int k){
    int n = num.size();

    vector<int> prev(k+1,0);
    
    prev[0] =1;
    
    if(num[0]<=k)
        prev[num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(k+1,0);
        cur[0]=1;
        for(int target= 1; target<=k; target++){
            
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= notTaken + taken;
        }
        
        prev = cur;
    }
    
    return prev[k];

    
}

int main() {

  vector<int> arr = {1,2,2,3};
  int k=3;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}


// For Element 0
/*
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

int main() {

  vector<int> arr = {0,0,1};
  int k=1;
                                 
  cout<<"The number of subsets found are " <<findWays(arr,k);
}

*/