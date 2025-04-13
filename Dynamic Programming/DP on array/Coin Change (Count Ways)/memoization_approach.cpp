#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(N*S)  
// Space complexity :- O(N*S*N)

// Approach :-
// we've to try all possibilities of taking all the coins and we can use recursion to do the same 
// there will be 2 changing parameter in which we can express the state ind and sum 
// there will be 2 case of take or notTake possibities
// notTake will be if we don't want to take curr_ind and move to (ind-1)
// take will be we take the curr_ind and substract the sum of curr_ind from sum parameter
// but we can only take the curr_ind if the sum is less than or equal to sum parameter 
// total number of ways will be sum of take and notTake
// base case will be, when sum == 0 then return 1
// and for ind it can be expressed in multiple form (ind == 0) there will be 0 ways for 1 based indexing 
// (ind < 0)    there will be 0 ways for 0 based indexing
// (ind == 0)   if s is divided by coins[0] then there will be 1 ways otherwise there will be 0 way

// we can memoize the solution, since there are two state changing (ind and sum)
// we can use 2-d dp and save the state for them accordingly to avoid recalculation

// Link :- https://www.geeksforgeeks.org/problems/coin-change2448/1


class Solution {
  private:
    int solve(int ind, int s, vector<int> &coins, vector<vector<int>> &dp){
        if(s == 0)      return 1;
        if(ind < 0)     return 0;
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = solve(ind-1, s, coins, dp), take = 0;
        if(coins[ind] <= s)
            take = solve(ind, s-coins[ind], coins, dp);
        
        return dp[ind][s] = take + notTake;
    }
  
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return solve(n-1, sum, coins, dp);
    }
};


class Solution {
  private:
    int solve(int ind, int s, vector<int> &coins, vector<vector<int>> &dp){
        if(s == 0)      return 1;
        if(ind == 0)     return 0;
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = solve(ind-1, s, coins, dp), take = 0;
        if(coins[ind-1] <= s)
            take = solve(ind, s-coins[ind-1], coins, dp);
        
        return dp[ind][s] = take + notTake;
    }
  
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return solve(n, sum, coins, dp);
    }
};


class Solution {
  private:
    int solve(int ind, int s, vector<int> &coins, vector<vector<int>> &dp){
        if(s == 0)      return 1;
        if(ind == 0){
            if(s % coins[0] == 0)   
                return 1;
            
            return 0;
        }
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = solve(ind-1, s, coins, dp), take = 0;
        if(coins[ind] <= s)
            take = solve(ind, s-coins[ind], coins, dp);
        
        return dp[ind][s] = take + notTake;
    }
  
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return solve(n-1, sum, coins, dp);
    }
};