#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*s)  
// Space complexity :- O(n*s)

// Approach :-  
// we can further optimize the memoization using tabulation approach
// we will first put the base case and convert it accordingly
// ind will go from 1 to n and s will go from 1 to sum vice versa of recursion
// we'll use the same possibilities case of recursion 
// at last we can check if answer points to maxValue then return -1 otherwise answer

// Link :- https://www.geeksforgeeks.org/problems/number-of-coins1824/1


class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        const int maxValue = 1e7+10;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, maxValue));
        
        for(int ind=0; ind<n; ++ind)
            dp[ind][0] = 0;
        
        for(int s=1; s<=sum; ++s){
            if(s % coins[0] == 0)
                dp[0][s] = s/coins[0];
        }
        
        for(int ind=1; ind<n; ++ind){
            for(int s=1; s<=sum; ++s){
                dp[ind][s] = dp[ind-1][s];
                
                if(coins[ind] <= s)
                    dp[ind][s] = min(dp[ind][s], 1 + dp[ind][s-coins[ind]]);
            }
        }
        int ans = dp[n-1][sum];
        return (ans == maxValue) ? -1 : ans;
    }
};


class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size(), maxValue = 1e7+10;
        vector<vector<int>> dp(n+1, vector<int> (sum+1, maxValue));
        
        for(int ind=0; ind<=n; ++ind)
            dp[ind][0] = 0;
        
        for(int ind=1; ind<=n; ++ind){
            for(int s=1; s<=sum; ++s){
                dp[ind][s] = dp[ind-1][s];
                
                if(coins[ind-1] <= s)
                    dp[ind][s] = min(dp[ind][s], 1 + dp[ind][s-coins[ind-1]]);
            }
        }
        return (dp[n][sum] == maxValue) ? -1 : dp[n][sum];
    }
};