#include<bits/stdc++.h>
using namespace std;

//Time complextiy :- O(n*2)  
// Space complexity :- O(n*2 + aux_stack_size)

// Approach :-  
// we can try all possibilities to sell and buy stocks 
// changing parameters will be (ind, buy) => where buy 0/1 represents where we've to sell/buy stocks
// try all possibilites to buy and sell stocks, after condition a transactions move to ind+2 
// because we've 1 day cooldown period, take max of all the possibilities
// we can use 2-d dp to memoize the solution 

// Link :- https://www.geeksforgeeks.org/problems/buy-stock-with-cooldown/1

class Solution {
  private:
    int solve(int ind, int buy, vector<int> &arr, int &n, vector<vector<int>> &dp){
        // base case 
        if(ind >= n)
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
            
        if(buy){
            // option to buy current stock 
            int notBuy = solve(ind+1, 1, arr, n, dp);
            int buyNow = solve(ind+1, 0, arr, n, dp) - arr[ind];
            return dp[ind][buy] = max(notBuy, buyNow);
        }
        else{
            // option to sell current stock 
            int notSell = solve(ind+1, 0, arr, n, dp);
            int sellNow = solve(ind+2, 1, arr, n, dp) + arr[ind];
            return dp[ind][buy] = max(notSell, sellNow);
        }
    }
  
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // 1d dp array initialization 
        vector<vector<int>> dp(n, vector<int> (2, -1));
        // try out all possibilities 
        return solve(0, 1, arr, n, dp);
    }
};