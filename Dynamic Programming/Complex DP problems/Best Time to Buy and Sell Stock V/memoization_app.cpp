#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k*3)
//Space complexity :- O(n*k*3) 

// Approach :-
// similar to the preivous stock problem we'll solve this one also using dynamic problem by trying out all ways 
// we've different case, state will be ind, k, cases 
// when case = 0, then we can either short-sell or buy 
// case=1 => sell the stock or case=2 => buy the stock 
// using these case we represent all the option and these can be implement only when k > 0 
// make sure after selling or buying(for case != 0) you mark them as one transaction and decrement the count 
// memoize the solution using 3d dp 

//link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/


class Solution {
private:
    typedef long long ll;

    ll solve(int ind, int trans, int opn, vector<int>& prices, int &n, vector<vector<vector<ll>>> &dp){
        // base cases 
        if(trans == 0)      return 0;
        if(ind == n){
            if(opn == 0)        return 0;
            return INT_MIN;
        }
        // memoization 
        ll &ans = dp[ind][trans][opn];
        if(ans != -1)
            return ans;

        // not take the current stock and move to the next day 
        ll notTake = solve(ind+1, trans, opn, prices, n, dp), take = 0;
        
        // complete the transactions by selling the stock 
        if(opn == 1){
            take = prices[ind] + solve(ind+1, trans-1, 0, prices, n, dp);
        }
        // complete the short transactions by buying the stock
        else if(opn == 2){
            take = -prices[ind] + solve(ind+1, trans-1, 0, prices, n, dp);
        }
        else{
            // trying short selling 
            ll shortSell = prices[ind] + solve(ind+1, trans, 2, prices, n, dp);
            // try buying the stock 
            ll buy = -prices[ind] + solve(ind+1, trans, 1, prices, n, dp);
            take = max<ll>(buy, shortSell);
        }
        return ans = max<ll>(take, notTake);
    }

public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (k+1, vector<ll> (3, -1)));
        return solve(0, k, 0, prices, n, dp);
    }
};