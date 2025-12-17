#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n*k*3)
//Space complexity :- O(k*3) 

// Approach :-
// further optimize the space to k*3 space instead of 3 dp 
// intialize base case when transaction is 0 inside the main loop 

//link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/


class Solution {
private:
    typedef long long ll;

public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // intialize a two 2d dp with INT_MIN as default value 
        vector<vector<ll>> ahead(k+1, vector<ll> (3, INT_MIN)), curr = ahead;
        // base cases 
        for(int trans=0; trans<k; ++trans){
            ahead[trans][0] = 0;
        }
        
        // explore all possibilities 
        for(int ind=n-1; ind>=0; --ind){
            // intialize base case when transaction is 0
            for(int opn=0; opn<=2; ++opn){
                ahead[0][opn] = 0;
            }
            for(int trans=1; trans<=k; ++trans){
                for(int opn=2; opn>=0; --opn){
                    ll &ans = curr[trans][opn];
                    // not take the current stock and move to the next day 
                    ll notTake = ahead[trans][opn], take = 0;
                    
                    // complete the transactions by selling the stock 
                    if(opn == 1){
                        take = prices[ind] + ahead[trans-1][0];
                    }
                    // complete the short transactions by buying the stock
                    else if(opn == 2){
                        take = -prices[ind] + ahead[trans-1][0];
                    }
                    else{
                        // trying short selling 
                        ll shortSell = prices[ind] + ahead[trans][2];
                        // try buying the stock 
                        ll buy = -prices[ind] + ahead[trans][1];
                        take = max<ll>(buy, shortSell);
                    }
                    ans = max<ll>(take, notTake);
                }
            }
            ahead = curr;
        }
        return ahead[k][0];
    }
};