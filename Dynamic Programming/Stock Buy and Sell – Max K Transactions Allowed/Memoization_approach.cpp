#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k*2)
//Space complexity :- O(n*k*2)

// Approach :-
// we've to try all possible combination to find whichever gives us the maximum result
// there will be 3 changing parameter i.e. ind, capicity, buy 
// we've to try all possibities of buy and sell at each index
// if buy == 1, then we've the luxury to buy the product otherwise we don't 
// take case will be pay the price of stock and buy at the current index and move to next index to find the answer 
// notTake case will be don't buy the stock at current index and move to the next index
// if buy == 0, the cases will change since we've to sell it 
// take case will be sell at the current index and move to the next index also decrease the cap by 1 since 1 trns is completed
// notTake case will be don't sell at the current index instead move to the other index in order to find more profit
// base case will be, if cap == 0 then we can't go further then we can't trade the stock return 0
// if (ind == n-1), if we hold a stock then sell it and take the profit otherwise don't buy because it'll be a loss since we can't sell it
// if (ind == n), return 0 because there is no more details available about stock on this index (one more way to represent index)

// we can memoize the solution since there are 3 changing parameter then we'll be needing 3-d dp
// we'll save the anwer for the state inorder to recalculation the state again. 
// we'll initialize the dp values with -1

//link :- https://www.geeksforgeeks.org/problems/maximum-profit4657/1


class Solution {
  private:
    int solve(int ind, int cap, int buy, int &n, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(cap == 0)    return 0;
        if(ind == n-1){
            if(buy)     return 0;
            return prices[ind];
        }
        int &ans = dp[ind][cap][buy];
        if(ans != -1)
            return ans;
        
        if(buy){
            int notTake = solve(ind+1, cap, 1, n, prices, dp);
            int take = -prices[ind] + solve(ind+1, cap, 0, n, prices, dp);
            return ans = max(notTake, take);
        }
        int notTake = solve(ind+1, cap, 0, n, prices, dp);
        int take = prices[ind] + solve(ind+1, cap-1, 1, n, prices, dp);
        return ans = max(take, notTake);
    }
  
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (k+1, vector<int> (2, -1)));
        return solve(0, k, 1, n, prices, dp);
    }
};



class Solution {
  private:
    int solve(int ind, int cap, int buy, int &n, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(cap == 0)    return 0;
        if(ind == n)    return 0;
        int &ans = dp[ind][cap][buy];
        if(ans != -1)
            return ans;
        
        if(buy){
            int notTake = solve(ind+1, cap, 1, n, prices, dp);
            int take = -prices[ind] + solve(ind+1, cap, 0, n, prices, dp);
            return ans = max(notTake, take);
        }
        int notTake = solve(ind+1, cap, 0, n, prices, dp);
        int take = prices[ind] + solve(ind+1, cap-1, 1, n, prices, dp);
        return ans = max(take, notTake);
    }
  
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (k+1, vector<int> (2, -1)));
        return solve(0, k, 1, n, prices, dp);
    }
};