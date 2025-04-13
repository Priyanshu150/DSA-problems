#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*s)  
// Space complexity :- O(n*s*n)

// Approach :- 
// we've to try all posiblities inorder to check the min coins forming the target
// Recursion can be used in this as greedy will fail eventually 
// index(ind) & sum(s) can be 2 changing parameter which can be expressed as a parameter of recursion
// First possibility, we'll notTake the current_ind and move to the next one
// Second possibility, we'll take the current_ind if coins[ind] <= s and move to next index with decreased sum
// ans will be min value of both case take & notTake
// base case will be, when sum == 0 there will be 0 ways
// when ind < 0 || ind == 0 (1-based-indexing)  return highest value so that we can min value while comparing notTake and take
// when ind == 0 (0-based-indexing) the we can check if (s % coins[0] == 0) then conins value will be s/coins[ind]
// otherwise the value will be m highest value so that we can min value while comparing notTake and take

// we can memoize the solution as there are 2 changing states so we can use 2-d dp array 
// we can save the answer in the array in order to eliminate redundant calculation of states 

// Link :- https://www.geeksforgeeks.org/problems/number-of-coins1824/1

class Solution {
  private:
    const int maxValue = 1e7+10;
  
    int solve(int ind, int s, vector<int> &coins, vector<vector<int>> &dp){
        if(s == 0)      return 0;
        if(ind == 0){
            if(s % coins[0] == 0) 
                return s/coins[0];
            
            return maxValue;
        }
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = solve(ind-1, s, coins, dp), take = maxValue;
        if(coins[ind] <= s)
            take = 1 + solve(ind, s-coins[ind], coins, dp);
        
        return dp[ind][s] = min(take, notTake);
    }
  
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        int ans = solve(n-1, sum, coins, dp);
        return (ans == maxValue) ? -1 : ans;
    }
};

class Solution {
  private:
    const int maxValue = 1e7+10;
  
    int solve(int ind, int s, vector<int> &coins, vector<vector<int>> &dp){
        if(s == 0)      return 0;
        if(ind < 0)     return maxValue;
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = solve(ind-1, s, coins, dp), take = maxValue;
        if(coins[ind] <= s)
            take = 1 + solve(ind, s-coins[ind], coins, dp);
        
        return dp[ind][s] = min(take, notTake);
    }
  
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        int ans = solve(n-1, sum, coins, dp);
        return (ans == maxValue) ? -1 : ans;
    }
};

class Solution {
  private:
    const int maxValue = 1e7+10;
  
    int solve(int ind, int s, vector<int> &coins, vector<vector<int>> &dp){
        if(s == 0)      return 0;
        if(ind == 0)     return maxValue;
        if(dp[ind][s] != -1)
            return dp[ind][s];
        
        int notTake = solve(ind-1, s, coins, dp), take = maxValue;
        if(coins[ind-1] <= s)
            take = 1 + solve(ind, s-coins[ind-1], coins, dp);
        
        return dp[ind][s] = min(take, notTake);
    }
  
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        int ans = solve(n, sum, coins, dp);
        return (ans == maxValue) ? -1 : ans;
    }
};