#include<bits/stdc++.h>
using namespace std;

//  Normal Recursion

/*
int fib(int n){
    if(n<=1) return n;
    
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    cin>>n;
    int ans= fib(n);
    cout<<ans<<endl;
    return 0;
}

*/



//  Memoization

/*
int fib(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fib(n-1, dp) + fib(n-2, dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<fib(n, dp)<<endl;
    return 0;
}

*/

// Tabulation

/*
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    return 0;
}

*/ 


 
// Most optimized


int main()
{
    int n;
    cin>>n;
    int prev = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++){
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }

    cout<<prev;
    return 0;
}