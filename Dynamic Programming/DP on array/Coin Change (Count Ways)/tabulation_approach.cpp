#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*S)  
// Space complexity :- O(N*S)

// Approach :-
// we can express the memoized solutin in tabulation by using loops
// we'll make default value of dp to 0 and express the base case for ind==0 & sum == 0
// ind can be expressed from 1 to n-1 vice versa of memoization
// sum can be expressed from 1 to sum-1 vice versa of memoization
// express all the posibities as same as we did in memoization 

// Link :- https://www.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, 0));
        
        for(int ind=0; ind<n; ++ind)
            dp[ind][0] = 1;
        
        for(int s=1; s<=sum; ++s){
            if(s % coins[0] == 0)
                dp[0][s] = 1;
        }
        
        for(int ind=1; ind<n; ++ind){
            for(int s=1; s<=sum; ++s){
                dp[ind][s] = dp[ind-1][s];
                
                if(coins[ind] <= s)
                    dp[ind][s] += dp[ind][s-coins[ind]];
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
        
        for(int ind=0; ind<=n; ++ind)
            dp[ind][0] = 1;
        
        for(int ind=1; ind<=n; ++ind){
            for(int s=1; s<=sum; ++s){
                dp[ind][s] = dp[ind-1][s];
                if(coins[ind-1] <= s)
                    dp[ind][s] += dp[ind][s-coins[ind-1]];
            }
        }
        return dp[n][sum];
    }
};