#include<bits/stdc++.h>
using namespace std;

// Time complexity :- O(n*m*log(m))
// Space complexity :- O(2*m)

// Approach :- 
// try all possibilities using recusion and use the concept of buy and sell stock 
// add the fee while completing the transaction
// memoize the solution with the 2d dp technique 


// Links :- https://www.geeksforgeeks.org/problems/buy-stock-with-transaction-fee/1

class Solution {
  private:
    int solve(int ind, int buy, vector<int> &arr, int &k, int &n, vector<vector<int>> &dp){
        if(ind == n){
            return 0;
        }
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        if(buy){
            int buyToday = -arr[ind] + solve(ind+1, 0, arr, k, n, dp);
            int notBuy = solve(ind+1, 1, arr, k, n, dp);
            
            return dp[ind][buy] = max(buyToday, notBuy);
        }
        else{
            int notSell = solve(ind+1, 0, arr, k, n, dp);
            int sell = (arr[ind] - k) + solve(ind+1, 1, arr, k, n, dp);
            
            return dp[ind][buy] = max(notSell, sell);
        }
    }
  
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(0, 1, arr, k, n, dp);
    }
};