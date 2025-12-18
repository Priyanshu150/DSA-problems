#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(n)
//Space complexity :- O(n) 

// Approach :-
// genral formual will be totalCurrProfit + (modifiedWindowProfit - originalWindowProfit)
// hence we've to maximize the (modifiedWindowProfit - originalWindowProfit) to get max answer 
// caluclate the originalWindowProfit, modifiedWindowProfit for each window using sliding window

//link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/

class Solution {
private:
    typedef long long ll;

public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        ll actualProfit = 0;
        vector<ll> profit(n);   // original profit of each day

        for(int i=0; i<n; ++i){
            profit[i] = (ll)strategy[i] * prices[i];
            actualProfit += profit[i];
        }

        ll originalWindowProfit = 0, modifiedWindowProfit = 0;
        ll maxGain = 0;   //modifiedWindowProfit - originalWindowProfit
        int i=0, j=0;

        while(j < n){
            originalWindowProfit += profit[j];

            //second half of the window contributes to modifiedWindowProfit
            if(j - i + 1 > k/2){
                modifiedWindowProfit += prices[j];
            }

            if(j-i+1 > k){
                originalWindowProfit -= profit[i];
                modifiedWindowProfit -= prices[i + k/2];
                ++i;
            }

            // evaluate window of size k 
            if(j - i + 1 == k){
                maxGain = max(maxGain, modifiedWindowProfit - originalWindowProfit);
            }
            ++j;
        }
        return actualProfit + maxGain;
    }
};