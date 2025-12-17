#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k*3)
//Space complexity :- O(n*k*3) 

// Approach :-
// express the same case in tabulation 

//link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/


class Solution {
private:
    typedef long long ll;

public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // intialize a 3d dp with INT_MIN as default value 
        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>> (k+1, vector<ll> (3, INT_MIN)));
        // base cases 
        for(int trans=0; trans<k; ++trans){
            dp[n][trans][0] = 0;
        }

        for(int ind=0; ind<=n; ++ind){
            for(int buy=0; buy<=2; ++buy){
                dp[ind][0][buy] = 0;
            }
        }
        // explore all possibilities 
        for(int ind=n-1; ind>=0; --ind){
            for(int trans=1; trans<=k; ++trans){
                for(int opn=2; opn>=0; --opn){
                    ll &ans = dp[ind][trans][opn];
                    // not take the current stock and move to the next day 
                    ll notTake = dp[ind+1][trans][opn], take = 0;
                    
                    // complete the transactions by selling the stock 
                    if(opn == 1){
                        take = prices[ind] + dp[ind+1][trans-1][0];
                    }
                    // complete the short transactions by buying the stock
                    else if(opn == 2){
                        take = -prices[ind] + dp[ind+1][trans-1][0];
                    }
                    else{
                        // trying short selling 
                        ll shortSell = prices[ind] + dp[ind+1][trans][2];
                        // try buying the stock 
                        ll buy = -prices[ind] + dp[ind+1][trans][1];
                        take = max<ll>(buy, shortSell);
                    }
                    ans = max<ll>(take, notTake);
                }
            }
        }
        return dp[0][k][0];
    }
};